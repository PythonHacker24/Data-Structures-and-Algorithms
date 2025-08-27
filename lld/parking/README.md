# Parking System - Low Level Design

## Problem Statement

Design a multi-level parking garage system that can handle different types of vehicles with varying space requirements. The system should include payment processing and efficient space allocation.

## Requirements Analysis

### Functional Requirements
- **Multi-level parking garage** with configurable floors and spots per floor
- **Vehicle type support**: Cars, Limousines, and Semi-trucks with different space requirements
- **Payment system**: Pay-first model with hourly charging
- **Space allocation**: Assign the lowest available parking spots on the lowest floor
- **Entry/Exit management**: Track vehicle parking duration for billing

### Non-Functional Requirements
- **Scalability**: Support for multiple floors and variable spots per floor
- **Efficiency**: O(n) space allocation where n is spots per floor
- **Extensibility**: Easy to add new vehicle types
- **Data integrity**: Accurate tracking of occupied/available spots

## System Design Overview

### Core Components

```
ParkingSystem
    ├── ParkingGarage
    │   └── ParkingFloor[] (multiple floors)
    │       └── spots[] (0=empty, 1=occupied)
    ├── Vehicle Hierarchy
    │   ├── Car (1 spot)
    │   ├── Limo (2 spots)
    │   └── SemiTruck (3 spots)
    └── Driver (owns vehicle, tracks payment)
```

## Class Design

### 1. Vehicle Hierarchy (Strategy Pattern)
```python
class Vehicle:
    # Base class defining vehicle interface
    def get_spot_size(self) -> int
    
class Car(Vehicle):
    # Takes 1 parking spot
    
class Limo(Vehicle):
    # Takes 2 consecutive parking spots
    
class SemiTruck(Vehicle):
    # Takes 3 consecutive parking spots
```

### 2. Driver Class
```python
class Driver:
    # Represents a driver with their vehicle and payment tracking
    - id: unique identifier
    - vehicle: Vehicle object
    - payment_due: accumulated charges
```

### 3. ParkingFloor Class
```python
class ParkingFloor:
    # Manages individual floor with spot allocation
    - spots[]: array representing parking spots (0=empty, 1=occupied)
    - vehicle_map: maps vehicle to [start_spot, end_spot]
    
    + park_vehicle(vehicle) -> bool
    + remove_vehicle(vehicle) -> void
```

### 4. ParkingGarage Class
```python
class ParkingGarage:
    # Manages multiple parking floors
    - parking_floors[]: array of ParkingFloor objects
    
    + park_vehicle(vehicle) -> bool  # tries floors from bottom to top
    + remove_vehicle(vehicle) -> bool
```

### 5. ParkingSystem Class (Facade Pattern)
```python
class ParkingSystem:
    # Main system controller
    - parkingGarage: ParkingGarage instance
    - hourlyRate: charging rate per hour
    - timeParked: maps driver_id to parking start time
    
    + park_vehicle(driver) -> bool
    + remove_vehicle(driver) -> bool
```

## Key Algorithms

### Parking Algorithm (Sliding Window)
```python
def park_vehicle(self, vehicle):
    size = vehicle.get_spot_size()
    l, r = 0, 0  # two pointers
    
    while r < len(spots):
        if spots[r] != 0:  # occupied spot found
            l = r + 1      # reset left pointer
        if r - l + 1 == size:  # found enough consecutive spots
            # Mark spots as occupied
            for k in range(l, r + 1):
                spots[k] = 1
            return True
        r += 1
    return False  # no space available
```

**Time Complexity**: O(n) where n = spots per floor  
**Space Complexity**: O(1) for the algorithm itself

### Floor Selection Strategy
- **Bottom-up allocation**: Always try to park on the lowest available floor
- **First-fit**: Within a floor, allocate the first available consecutive spots

## Design Patterns Used

1. **Strategy Pattern**: Vehicle hierarchy with different spot size strategies
2. **Facade Pattern**: ParkingSystem provides a simplified interface
3. **Template Method**: Common vehicle operations with specific implementations
4. **Composite Pattern**: ParkingGarage contains multiple ParkingFloors

## System Workflow

### Parking Process
1. Driver arrives with vehicle
2. System identifies vehicle type and required spots
3. Search from floor 0 upwards for available consecutive spots
4. If found: mark spots as occupied, record parking time
5. If not found: notify driver that garage is full

### Exit Process
1. Driver requests to leave
2. System calculates parking duration
3. Calculate charges based on hourly rate (rounded up)
4. Update driver's payment due
5. Free up the occupied spots
6. Remove vehicle from tracking

## Example Usage

```python
# Initialize system
garage = ParkingGarage(floor_count=3, spots_per_floor=10)
parking_system = ParkingSystem(garage, hourlyRate=5)

# Create drivers with vehicles
car_driver = Driver("D001", Car())
limo_driver = Driver("D002", Limo())
truck_driver = Driver("D003", SemiTruck())

# Park vehicles
parking_system.park_vehicle(car_driver)    # Takes 1 spot
parking_system.park_vehicle(limo_driver)   # Takes 2 consecutive spots
parking_system.park_vehicle(truck_driver)  # Takes 3 consecutive spots

# Later, when leaving
parking_system.remove_vehicle(car_driver)  # Charges based on duration
```

## Trade-offs and Considerations

### Advantages
- **Flexible vehicle types**: Easy to add new vehicle categories
- **Efficient space utilization**: Consecutive spot allocation for larger vehicles
- **Simple payment model**: Pay-after-use with hourly rates
- **Scalable architecture**: Configurable floors and spots

### Limitations
- **No reservation system**: First-come, first-served basis
- **No spot type differentiation**: All spots are generic
- **Simple time tracking**: Uses only hours (could be more granular)
- **No payment processing**: Only tracks dues, doesn't handle actual payments

### Potential Improvements
1. **Reserved parking**: VIP or handicapped spots
2. **Dynamic pricing**: Peak hour rates, vehicle type based pricing
3. **Spot optimization**: Defragmentation of parking spaces
4. **Real-time availability**: API for checking available spots
5. **Payment integration**: Credit card processing, digital payments

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Park Vehicle | O(F × S) | O(1) |
| Remove Vehicle | O(F) | O(1) |
| Initialize System | O(F × S) | O(F × S) |

Where F = number of floors, S = spots per floor

## Interview Discussion Points

1. **Scalability**: How would you handle 1000+ floors?
2. **Concurrency**: Multiple vehicles trying to park simultaneously?
3. **Persistence**: How to save/restore system state?
4. **Monitoring**: How to track system performance and utilization?
5. **Error handling**: What happens if payment fails?

This design provides a solid foundation for a parking system while maintaining flexibility for future enhancements and requirements.
