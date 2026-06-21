#pragma once
#include <string>
using namespace std;

enum class VehicleType {
    BIKE,
    CAR,
    TRUCK
};

class Vehicle {
protected:
    string numberPlate;
    VehicleType type;

public:
    Vehicle(string plate, VehicleType t)
        : numberPlate(plate), type(t) {}

    virtual ~Vehicle() = default;

    string getNumberPlate() const {
        return numberPlate;
    }

    VehicleType getType() const {
        return type;
    }
};

class Bike : public Vehicle {
public:
    Bike(string plate) : Vehicle(plate, VehicleType::BIKE) {}
};

class Car : public Vehicle {
public:
    Car(string plate) : Vehicle(plate, VehicleType::CAR) {}
};

class Truck : public Vehicle {
public:
    Truck(string plate) : Vehicle(plate, VehicleType::TRUCK) {}
};