#pragma once

#include "ParkingManager.h"
#include "TicketManager.h"
#include "FeeStrategy.h"

class ParkingLot {

private:

    vector<ParkingFloor*> floors;

    ParkingManager parkingManager;

    TicketManager ticketManager;

    FeeStrategy* feeStrategy;

public:

    ParkingLot(FeeStrategy* strategy)
        : feeStrategy(strategy) {}

    void addFloor(ParkingFloor* floor) {
        floors.push_back(floor);
    }

    Ticket* parkVehicle(Vehicle* vehicle) {

        ParkingSpot* spot =
            parkingManager.assignSpot(floors, vehicle);

        if (!spot)
            return nullptr;

        return ticketManager.generateTicket(vehicle, spot);
    }

    double exitVehicle(int ticketId) {

        Ticket* ticket =
            ticketManager.getTicket(ticketId);

        double fee =
            feeStrategy->calculateFee(ticket);

        parkingManager.releaseSpot(ticket->spot);

        ticketManager.closeTicket(ticketId);

        return fee;
    }
};