#pragma once

#include "ParkingFloor.h"

class ParkingManager {

public:

    ParkingSpot* assignSpot(vector<ParkingFloor*>& floors,
                            Vehicle* vehicle) {

        SpotType needed;

        if (vehicle->getType() == VehicleType::BIKE)
            needed = SpotType::BIKE;
        else if (vehicle->getType() == VehicleType::CAR)
            needed = SpotType::CAR;
        else
            needed = SpotType::TRUCK;

        for (auto floor : floors) {

            for (auto spot : floor->getSpots()) {

                if (spot->isAvailable() &&
                    spot->getSpotType() == needed) {

                    spot->parkVehicle(vehicle);
                    return spot;
                }
            }
        }

        return nullptr;
    }

    void releaseSpot(ParkingSpot* spot) {
        spot->removeVehicle();
    }
};