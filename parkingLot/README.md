# 🚗 Parking Lot System (Low-Level Design in C++)

A modular **Parking Lot System** implemented in **C++** to practice **Object-Oriented Programming (OOP)**, **SOLID Principles**, and common **Low-Level Design (LLD)** concepts frequently discussed in software engineering interviews.

## 📌 Current Features

* ✅ Support for multiple vehicle types:

  * Bike
  * Car
  * Truck
* ✅ Parking spot allocation based on vehicle type
* ✅ Multi-floor parking structure
* ✅ Ticket generation when a vehicle enters
* ✅ Ticket management using a dedicated `TicketManager`
* ✅ Parking spot allocation and release using a dedicated `ParkingManager`
* ✅ Fee calculation using the **Strategy Design Pattern**
* ✅ Automatic parking fee calculation when a vehicle exits
* ✅ Extensible and object-oriented architecture

---

## 🏗️ Project Structure

```text
ParkingLot/
│
├── main.cpp
├── ParkingLot.h
├── ParkingManager.h
├── ParkingFloor.h
├── ParkingSpot.h
├── Ticket.h
├── TicketManager.h
├── Vehicle.h
└── FeeStrategy.h
```

---

## 🧩 Core Components

### Vehicle

Represents different types of vehicles entering the parking lot.

* `Vehicle` (Base Class)
* `Bike`
* `Car`
* `Truck`

---

### ParkingSpot

Represents an individual parking space.

Attributes include:

* Spot ID
* Spot Type
* Occupancy Status
* Assigned Vehicle

Responsibilities:

* Park a vehicle
* Release a vehicle
* Check availability

---

### ParkingFloor

Represents a floor containing multiple parking spots.

Responsibilities:

* Maintain parking spots
* Provide available spots for allocation

---

### ParkingManager

Responsible for:

* Finding a suitable parking spot
* Assigning a spot to a vehicle
* Releasing the spot when the vehicle exits

This keeps parking logic separate from business orchestration and follows the **Single Responsibility Principle (SRP)**.

---

### Ticket

Stores information related to a parking session:

* Ticket ID
* Vehicle
* Assigned Parking Spot
* Entry Time

---

### TicketManager

Responsible for:

* Generating tickets
* Storing active tickets
* Retrieving tickets
* Closing tickets on vehicle exit

Separating ticket handling into its own component improves maintainability and scalability.

---

### FeeStrategy

Parking fee calculation is implemented using the **Strategy Design Pattern**.

Current implementation:

* `HourlyFeeStrategy`

This design allows new pricing policies to be added without modifying existing business logic.

Examples of future extensions:

* Flat Fee
* Weekend Pricing
* Dynamic Pricing
* VIP Pricing

---

### ParkingLot

Acts as the central coordinator of the system.

Responsibilities:

* Manage parking floors
* Coordinate parking requests
* Coordinate vehicle exits
* Interact with `ParkingManager` and `TicketManager`
* Delegate fee calculation to the configured strategy

---

## 🎯 Design Principles Used

### SOLID Principles

* **Single Responsibility Principle (SRP)** – Separate responsibilities for parking management, ticket management, and fee calculation.
* **Open/Closed Principle (OCP)** – New fee calculation strategies can be introduced without modifying existing classes.
* **Liskov Substitution Principle (LSP)** – Different vehicle types inherit from the `Vehicle` base class.
* **Interface Segregation Principle (ISP)** – Responsibilities are kept focused and minimal.
* **Dependency Inversion Principle (DIP)** – `ParkingLot` depends on abstractions such as `FeeStrategy` rather than concrete implementations.

---

## 🎨 Design Patterns Used

### Strategy Pattern

Used for parking fee calculation.

```text
          FeeStrategy
                ▲
                │
     -----------------------
     │                     │
HourlyFeeStrategy   (Future Strategies)
```

---

## 🔄 Sample Flow

1. Create a parking lot.
2. Add one or more parking floors.
3. Add parking spots to each floor.
4. Create a vehicle.
5. Park the vehicle.
6. Generate a parking ticket.
7. Simulate parking duration.
8. Exit the vehicle.
9. Calculate parking charges.
10. Release the occupied parking spot.

---

## 🚀 Possible Future Enhancements

* Vehicle Factory (Factory Pattern)
* Payment Module (Cash, Card, UPI)
* Singleton `ParkingLot`
* Entry Gate and Exit Gate abstraction
* Observer-based display board
* Spot allocation strategies (Nearest, Random, VIP)
* Reservation support
* Electric vehicle charging spots
* Admin dashboard and analytics
* Persistent database storage

---

## 📚 Learning Objectives

This project was built to strengthen understanding of:

* Object-Oriented Programming in C++
* Low-Level System Design
* SOLID Principles
* Strategy Design Pattern
* Separation of Concerns
* Extensible Software Architecture

---

## ▶️ Example Output

```text
Vehicle Parked
Ticket ID = 1
Parking Fee = 40
```

(Example assumes the vehicle remained parked for 2 hours with an hourly rate of 20 units.)

---

## 📝 Note

This is an educational project focused on learning software design and interview-oriented Low-Level Design concepts. Additional patterns such as Factory, Singleton, Observer, and Payment Strategies are planned for future iterations.
