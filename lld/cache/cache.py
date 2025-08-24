from fastapi import FastAPI
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel, Field
from typing import Any, Optional
from datetime import datetime, timedelta
import threading
import time

# ---------------------------
# Pydantic models
# ---------------------------

class Item(BaseModel):
    key: str
    value: Any
    timestamp: datetime = Field(default_factory=datetime.utcnow)


class ItemIn(BaseModel):
    key: str
    value: Any


class ItemOut(BaseModel):
    key: str
    value: Any
    timestamp: datetime


class UpdateItem(BaseModel):
    value: Any


# ---------------------------
# Storage layer
# ---------------------------

class Database:
    """
    Simple in-memory key-value store for Item objects.
    Thread-safe via an RLock.
    """
    def __init__(self):
        self._store: dict[str, Item] = {}
        self._lock = threading.RLock()

    def set(self, key: str, item: Item) -> None:
        with self._lock:
            self._store[key] = item

    def get(self, key: str) -> Optional[Item]:
        with self._lock:
            return self._store.get(key)

    def has(self, key: str) -> bool:
        with self._lock:
            return key in self._store

    def update(self, key: str, value: Any) -> None:
        with self._lock:
            if key not in self._store:
                raise KeyError(key)
            # Preserve timestamp or refresh? We’ll refresh to indicate last write time.
            self._store[key].value = value
            self._store[key].timestamp = datetime.utcnow()

    def delete(self, key: str) -> bool:
        with self._lock:
            return self._store.pop(key, None) is not None

    def length(self) -> int:
        with self._lock:
            return len(self._store)

    def scan_and_clean_time(self, ttl_seconds: int) -> int:
        """Delete keys whose items are older than ttl_seconds. Returns count deleted."""
        now = datetime.utcnow()
        deleted = 0
        with self._lock:
            # Build a list first to avoid mutating while iterating
            to_delete = [
                k for k, item in self._store.items()
                if (now - item.timestamp) > timedelta(seconds=ttl_seconds)
            ]
            for k in to_delete:
                self._store.pop(k, None)
                deleted += 1
        return deleted

    def delete_oldest_n(self, n: int) -> int:
        """Delete the n oldest items by timestamp. Returns count deleted."""
        if n <= 0:
            return 0
        with self._lock:
            items_sorted = sorted(self._store.items(), key=lambda kv: kv[1].timestamp)
            count = 0
            for i in range(min(n, len(items_sorted))):
                key = items_sorted[i][0]
                if key in self._store:
                    self._store.pop(key, None)
                    count += 1
            return count


# ---------------------------
# Manager with policies (TTL + memory cap)
# ---------------------------

class DatabaseSystem:
    """
    Adds background TTL enforcement and a simple memory cap policy.
    delay: seconds between cleanup scans
    ttl: seconds an item may live before being auto-deleted
    max_vals: soft cap on number of items; oldest items evicted when exceeded
    """
    def __init__(self, database: Database, delay: int = 10, ttl: int = 600, max_vals: int = 1000):
        if database is None:
            raise ValueError("Database must be provided")
        self.database = database
        self.delay = max(1, int(delay))
        self.ttl = max(1, int(ttl))
        self.max_vals = max(1, int(max_vals))
        self._stop_event = threading.Event()

        # Start background cleaner
        self._thread = threading.Thread(target=self._cleanup_loop, name="ttl-cleaner", daemon=True)
        self._thread.start()

    # CRUD wrappers
    def get(self, key: str) -> Optional[Item]:
        return self.database.get(key)

    def set(self, key: str, value: Any) -> Item:
        item = Item(key=key, value=value, timestamp=datetime.utcnow())
        self.database.set(key, item)
        self._memory_cleaner_if_needed()
        return item

    def update(self, key: str, value: Any) -> Item:
        self.database.update(key, value)
        return self.database.get(key)  # type: ignore

    def delete(self, key: str) -> bool:
        return self.database.delete(key)

    def length(self) -> int:
        return self.database.length()

    # Background policies
    def _cleanup_loop(self):
        while not self._stop_event.is_set():
            # TTL cleanup
            cleaned = self.database.scan_and_clean_time(self.ttl)
            # Memory cleanup after TTL cleanup
            self._memory_cleaner_if_needed()
            # Sleep/wait for the next cycle
            self._stop_event.wait(self.delay)

    def _memory_cleaner_if_needed(self):
        # If we exceed the cap, evict oldest items to bring size back to cap.
        over_by = self.database.length() - self.max_vals
        if over_by > 0:
            self.database.delete_oldest_n(over_by)

    def stop(self):
        self._stop_event.set()
        # No join() in typical FastAPI lifecycle, but provided for completeness.


# ---------------------------
# FastAPI app + routes
# ---------------------------

app = FastAPI(title="KV Store with TTL", version="1.0.0")

_db = Database()
db_system = DatabaseSystem(database=_db, delay=5, ttl=600, max_vals=10000)  # tweak as needed


@app.post("/items", response_model=ItemOut)
def create_item(item: ItemIn):
    created = db_system.set(item.key, item.value)
    return ItemOut(**created.dict())


@app.get("/items/{key}", response_model=ItemOut)
def read_item(key: str):
    found = db_system.get(key)
    if not found:
        raise HTTPException(status_code=404, detail="Key not found")
    return ItemOut(**found.dict())


@app.put("/items/{key}", response_model=ItemOut)
def update_item(key: str, body: UpdateItem):
    if not db_system.get(key):
        raise HTTPException(status_code=404, detail="Key not found")
    updated = db_system.update(key, body.value)
    return ItemOut(**updated.dict())


@app.delete("/items/{key}")
def delete_item(key: str):
    ok = db_system.delete(key)
    if not ok:
        raise HTTPException(status_code=404, detail="Key not found")
    return {"message": "Deleted", "key": key}


@app.get("/stats")
def stats():
    return {
        "count": db_system.length(),
        "ttl_seconds": db_system.ttl,
        "cleanup_interval_seconds": db_system.delay,
        "max_items": db_system.max_vals,
    }


# ---------------------------
# Local dev entrypoint
# ---------------------------

if __name__ == "__main__":
    import uvicorn
    uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)
