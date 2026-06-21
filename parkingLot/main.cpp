#include <iostream>
#include "ParkingLot.h"

using namespace std;

int main() {

    ParkingLot lot(new HourlyFeeStrategy());

    ParkingFloor* floor1 = new ParkingFloor(1);

    floor1->addSpot(new ParkingSpot(1, SpotType::CAR));
    floor1->addSpot(new ParkingSpot(2, SpotType::BIKE));
    floor1->addSpot(new ParkingSpot(3, SpotType::TRUCK));

    lot.addFloor(floor1);

    Vehicle* car = new Car("DL01AB1234");

    Ticket* ticket = lot.parkVehicle(car);

    if (ticket) {
        cout << "Vehicle Parked\n";
        cout << "Ticket ID = " << ticket->getId() << "\n";

         // Simulate that the vehicle entered 5 hours ago
        ticket->entryTime -= std::chrono::hours(5);
    }

    double fee = lot.exitVehicle(ticket->getId());

    cout << "Parking Fee = " << fee << endl;

    return 0;
}