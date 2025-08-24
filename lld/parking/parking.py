You said:
"""
- multiple levels in the parking lot 
- car, limo, semi-truck -> take different spaces
- payment system -> entrance and exit
- parking spots assigned after payment is made

About vehicles:
- car takes 1 spot, lime takes 2 spots while truck takes 3 spots
- no fractional spots
- assign next available parking spot lowest on the floor

Payment System:
- pay first and get next available parking spot at lowest level
- pay for variable number of hours and charged after they remove their vehicle based on an hourly rate
- if no space is available, notify the driver

Vehicle class -> Car, Limo, Truck (predefined size)
Driver Class (to which a vechile belongs)
ParkingGarage will have ParkingFloors -> [0 = empty, 1 = occupied]
- ParkingSystem controls ParkingGarage

"""

# this is a vehicle -> it has a specific size
class Vehicle:
    def __init__(self, spot_size):
        self._spot_size = spot_size

    def get_spot_size(self):
        return self._spot_size

# Car takes 1 spot
class Car(Vehicle):
    def __init__(self):
        super().__init__(1)

# Limo takes 2 spots
class Limo(Vehicle):
    def __init__(self):
        super().__init__(2)

# SemiTruck takes 3 spots
class SemiTruck(Vehicle):
    def __init__(self):
        super().__init__(3)

# Driver class allows us to create Driver objects with an id and a vehicle assigned. Also, it keeps track of payment due.
class Driver:
    def __init__(self, id, vehicle):
        self._id = id
        self._vehicle = vehicle
        self._payment_due = 0

    def get_vehicle(self):
        return self._vehicle

    def get_id(self):
        return self._id

    def charge(self, amount):
        self._payment_due += amount

# ---- at this point, we have basic elements in place ----#

# A parking floor
class ParkingFloor:
    def __init__(self, spot_count):
        # we create a parking floor with a variable number of parking spots available and store them in an array
        self._spots = [0] * spot_count
        self._vehicle_map = {}

    def park_vehicle(self, vehicle):
        size = vehicle.get_spot_size()
        l, r = 0, 0
        while r < len(self._spots):
            if self._spots[r] != 0:
                l = r + 1
            if r - l + 1 == size:
                # enough parking spots have been found
                for k in range(l, r + 1):
                    self._spots[k] = 1
                self._vehicle_map[vehicle] = [l, r]
                return True
            r += 1
        return False

    def remove_vehicle(self, vehicle):
        start, end = self._vehicle_map[vehicle]
        for i in range(start, end + 1):
            self._spots[i] = 0
        del self._vehicle_map[vehicle]

    def get_parking_spots(self):
        return self._spots

    def get_vehicle_spots(self, vehicle):
        return self._vehicle_map.get(vehicle)

# Complete Parking Building
class ParkingGarage:
    def __init__(self, floor_count, spots_per_floor):
        self._parking_floors = [ParkingFloor(spots_per_floor) for _ in range(floor_count)]

    def park_vehicle(self, vehicle):
        for floor in self._parking_floors:
            if floor.park_vehicle(vehicle):
                return True
        return False

    def remove_vehicle(self, vehicle):
        for floor in self._parking_floors:
            if floor.get_vehicle_spots(vehicle):
                floor.remove_vehicle(vehicle)
                return True
        return False

# ---- Now the complete parking system that interacts with all the classes above (I call them elements) ---- #

import datetime
import math

class ParkingSystem:
    def __init__(self, parkingGarage, hourlyRate):
        self._parkingGarage = parkingGarage
        self._hourlyRate = hourlyRate
        # map driverId to time that they parked
        self._timeParked = {}

    def park_vehicle(self, driver):
        currentHour = datetime.datetime.now().hour
        isParked = self._parkingGarage.park_vehicle(driver.get_vehicle())
        if isParked:
            self._timeParked[driver.get_id()] = currentHour
        return isParked

    def remove_vehicle(self, driver):
        if driver.get_id() not in self._timeParked:
            return False
        currentHour = datetime.datetime.now().hour
        timeParked = math.ceil(currentHour - self._timeParked[driver.get_id()])
        driver.charge(timeParked * self._hourlyRate)

        del self._timeParked[driver.get_id()]
        return True
