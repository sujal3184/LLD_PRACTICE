#pragma once

#include <unordered_map>
#include "Ticket.h"

class TicketManager {

private:

    int nextId = 1;

    unordered_map<int, Ticket*> activeTickets;

public:

    Ticket* generateTicket(Vehicle* v,
                           ParkingSpot* s) {

        Ticket* t = new Ticket(nextId++, v, s);

        activeTickets[t->getId()] = t;

        return t;
    }

    Ticket* getTicket(int id) {

        return activeTickets[id];
    }

    void closeTicket(int id) {

        activeTickets.erase(id);
    }
};