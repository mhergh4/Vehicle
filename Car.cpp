#include <iostream>
#include "Car.h"
using namespace std;

Car::Car() : Vehicle(), _numSeats(5) {}

Car::Car(Engine engine, std::string owner, std::string model, float price, float weight, float speed, int year, float velocity, bool isRunning,  int numSeats) :
    Vehicle(engine, owner, model, price, weight, speed, year, velocity, isRunning), _numSeats(numSeats) {}

Car::~Car() {
    std::cout << "Car object with model " << getModel() << ", production year " << getProductionYear() << ", and owner " << getOwner() << " was deleted." << std::endl;
}

int Car::getNumSeats() const {
    return _numSeats;
}

void Car::setNumSeats(int numSeats) {
    _numSeats = numSeats;
}

void Car::draw() {
    cout << *this;
}

void Car::start() {
    std::cout << "\nThe car started moving\n ";
    setIsRunning(1);
}
void Car::accelerate(double tillVelocity) {
    std::cout << "\nCar speed increased by "<<tillVelocity <<" time\n";
    setVelocity( tillVelocity + getVelocity());
}
void Car::stop() {
    std::cout << "\nThe car stoped moving\n ";
    setIsRunning(0);
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Car information:\n";
    os << static_cast<const Vehicle&>(car);
    os<<"Number of seats: " << car.getNumSeats() << "\n";
    return os;
}

std::istream& operator>>(istream& is, Car& car)
{
    cout << "Enter engine type (0 - diesel, 1 - petrol, 2 - gas, 3 - electric): ";
    int engineType;
    is >> engineType;
    car.setEngineOfVehicle(Engine(static_cast<engineTypes>(engineType)));

    string owner;
    cout << "Enter owner name: ";
    is >> owner;
    car.setOwner(owner);

    string model;
    cout << "Enter car model: ";
    is >> model;
    car.setModel(model);

    float price;
    cout << "Enter car price: ";
    is >> price;
    car.setPrice(price);

    float weight;
    cout << "Enter car weight: ";
    is >> weight;
    car.setWeight(weight);

    float maxSpeed;
    cout << "Enter maximum speed: ";
    is >> maxSpeed;
    car.setMaximumSpeed(maxSpeed);

    int prodYear;
    cout << "Enter production year: ";
    is >> prodYear;
    car.setProductionYear(prodYear);

    int numOfSeats;
    cout << "Enter number of seats: ";
    is >> numOfSeats;
    car.setNumSeats(numOfSeats);

    return is;
}

