#pragma once

#include "Vehicle.h"

enum class SpotType {
    BIKE,
    CAR,
    TRUCK
};

class ParkingSpot {
private:
    int id;
    SpotType spotType;
    bool occupied;
    Vehicle* vehicle;

public:
    ParkingSpot(int id, SpotType type)
        : id(id), spotType(type), occupied(false), vehicle(nullptr) {}

    bool isAvailable() const {
        return !occupied;
    }

    SpotType getSpotType() const {
        return spotType;
    }

    void parkVehicle(Vehicle* v) {
        occupied = true;
        vehicle = v;
    }

    void removeVehicle() {
        occupied = false;
        vehicle = nullptr;
    }

    int getId() const {
        return id;
    }
};