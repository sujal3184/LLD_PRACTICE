#pragma once

#include "Ticket.h"

class FeeStrategy {
public:
    virtual double calculateFee(Ticket* ticket) = 0;
    virtual ~FeeStrategy() = default;
};

class HourlyFeeStrategy : public FeeStrategy {

public:

    double calculateFee(Ticket* ticket) override {

        auto now = chrono::system_clock::now();

        auto hours =
            chrono::duration_cast<chrono::hours>(
                now - ticket->entryTime).count();

        if (hours == 0)
            hours = 1;

        return hours * 20.0;
    }
};