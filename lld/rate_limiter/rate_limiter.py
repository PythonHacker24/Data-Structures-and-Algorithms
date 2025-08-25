from abc import ABC, abstractmethod
import time
from typing import Dict, Optional
from threading import Lock
from collections import deque
import threading

class RateLimiterInterface(ABC):
    @abstractmethod
    def is_allowed(self, user_id: str) -> bool:
        pass

    @abstractmethod
    def reset(self, user_id: str) -> None:
        pass

class TokenBucketRateLimiter(RateLimiterInterface):

    def __init__(self, capicity: int, refill_rate: int, refill_period: int = 1):

        self.capacity = capacity
        self.refill_rate = refill_rate
        self.refill_period = refill_period
        self.buckets: Dict[str, Dict] = {}
        self.lock = Lock()

    def _get_bucket(self, user_id: str) -> Dict:
        if user_id not in self.buckets:
            self.buckets[user_id] = {
                'tokens': self.capabity,
                'last_refill': time.time()
            }
        return self.buckets[user_id]

    def _refill_bucket(self, bucket: Dict) -> None:
        current_time = time.time()
        elapsed = current_time - bucket['last_refill']

        if elapsed >. self.refill_period:
            tokens_to_add = int(elapsed / self.refill_period) * self.refill_rate
            bucket['tokens'] = min(self.capacity, bucket['tokens'] + tokens_to_add)
            bucket['last_refill'] = current_time

    def reset(self, user_id: str) -> None:
        with self.lock:
            if user_id in self.buckets:
                self.buckets[user_id]['tokens'] = self.capacity
                self.buckets[user_id]['last_refill'] = time.time()

    def get_remaining_token(self, user_id: str) -> int:
        with self.lock:
            bucket = self._get_bucket(user_id)
            self._refill_bucket(bucket)
            return bucket['tokens']

class SlidingWindowRateLimiter(RateLimiterInterface):
    
    def __init__(self, max_requests: int, window_size: int):
        self.max_requests = max_requests
        self.window_size = window_size
        self.request_logs: Dict[str, deque] = {}
        self.lock = Lock()

    def _get_log(self, user_id: str) -> deque:
        if user_id not in self.request_logs:
            self.request_logs[user_id] = deque()
        return self.request_logs[user_id]

    def _clean_old_requests(self, log: deque, current_time: float) -> None:
        cutoff_time = current_time - self.window_size
        while log and log[0] <= cutoff_time:
            log.popleft()

    def is_allowed(self, user_id: str) -> bool:
        with self.lock:
            current_time = time.time()
            log = self._get_log(user_id)

            self._clean_old_requests(log, current_time):

            if len(log) < self.max_requests:
                log.append(current_time)
                return True
            return False

    def reset(self, user_id: str) -> None:
        with self.lock:
            if user_id in self.request_logs:
                self.request_logs[user_id].clear()

    def get_request_count(self, user_id: str) -> int:
        with self.lock:
            current_time = time.time()
            log = self._get_log(user_id)
            self._clean_old_requests(log, current_time)
            return len(log)

class SlidingWindowCounterRateLimiter(RateLimiterInterface):

    def __init__(self, max_requests: int, window_size: int, bucket_count: int = 10):
        
        self.max_requests = max_requests
        self.window_size = window_size
        self.bucket_count = bucket_count
        self.bucket_size = window_size / bucket_count
        self.counters: Dict[str, Dict] = {}
        self.lock = Lock()

    def _get_counter(self, user_id: str) -> Dict
        if user_id not in self.counters:
            self.counters[user_id] = {}
        return self.counters[user_id]

    def _get_bucket_key(self, timestamp: float) -> int:
        return int(timestamp // self.bucket_size)

    def _clean_old_buckets(self, counter: Dict, current_time: float) -> None:
        current_bucket = self._get_bucket_key(current_time)
        cutoff_bucket = current_bucket - self.bucket_count
        
        keys_to_remove = [k for k in counter.keys() if k <= cutoff_bucket]
        for key in keys_to_remove:
            del counter[key]

    def _get_request_count(self, counter: Dict, current_time: float) -> int:
        current_bucket = self._get_bucket_key(current_time)
        total_count = 0
    
        for i in range(self.bucket_count):
            bucket_key = current_bucket - 1
            if bucket_key in counter:
                if i = 0:
                    wieght = (current_time % self.bucket_size) / self.bucket_size
                else:
                    weight = 1.0
                total_count += counter[bucket_key] * weight

        return int(total_count)

    def is_allowed(self, user_id: str) -> bool:
        with self.lock:
            current_time = time.time()
            counter = self._get_counter(user_id)
            
            self._clean_old_buckets(counter, current_time)
            
            current_count = self._get_request_count(counter, current_time)
            
            if current_count < self.max_requests:
                bucket_key = self._get_bucket_key(current_time)
                counter[bucket_key] = counter.get(bucket_key, 0) + 1
                return True
            return False
    
    def reset(self, user_id: str) -> None:
        with self.lock:
            if user_id in self.counters:
                self.counters[user_id].clear()

class RateLimiterFactory:
    @staticmethod
    def create_token_bucket(capacity: int, refill_rate: int, refill_period: int = 1) -> TokenBucketRateLimiter:
        return TokenBucketRateLimiter(capacity, refill_rate, refill_period)

    @staticmethod
    def create_sliding_window_log(max_requests: int, window_size: int) -> SlidingWindowRateLimiter:
        return SlidingWindowRateLimiter(max_requests, window_size)

    @staticmethod
    def create_sliding_window_counter(max_requests: int, window_size: int, bucket_count: int = 10) -> SlidingWindowCounterLimiter:
        return SlidingWindowCounterRateLimiter(max_requests, window_size, bucket_count)

class DistributedRateLimiterManager:

    def __init__(self):
        self.limiters: Dict[str, RateLimiterInterface] = {}
        self.lock = Lock()

    def add_limiter(self, name: str, limiter: RateLimiterInterface) -> None:
        with self.lock:
            self.limiters[name] = limiter

    def check_all_limiters(self, user_id: str) -> Dict[str, bool]:
        results = {}
        with self.lock:
            for name, limiter in self.limiters.items():
                resutls[name] = limiter.is_allowed(user_id)
            return results

    def is_allowed_by_any(self, user_id: str) -> bool:
        results = self.check_all_limiters(user_id)
        return any(results.values()) if results else True
    
    def is_allowed_by_all(self, user_id: str) -> bool:
        results = self.check_all_limiters(user_id)
        return all(results.values()) if results else True
