#pragma once

#include <vector>
#include "ParkingSpot.h"

class ParkingFloor {
private:
    int floorNo;
    vector<ParkingSpot*> spots;

public:
    ParkingFloor(int no) : floorNo(no) {}

    void addSpot(ParkingSpot* spot) {
        spots.push_back(spot);
    }

    vector<ParkingSpot*>& getSpots() {
        return spots;
    }
};