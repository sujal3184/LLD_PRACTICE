#pragma once

#include <chrono>
using namespace std;

class Ticket {
private:
    int ticketId;

public:
    Vehicle* vehicle;
    ParkingSpot* spot;
    chrono::system_clock::time_point entryTime;

    Ticket(int id, Vehicle* v, ParkingSpot* s)
        : ticketId(id), vehicle(v), spot(s) {

        entryTime = chrono::system_clock::now();
    }

    int getId() const {
        return ticketId;
    }
};