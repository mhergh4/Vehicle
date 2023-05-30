#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck() : Vehicle(), _loadCapacity(1000) {}

Truck::Truck(Engine engine, string owner, string model, float price, float weight, float speed, int year, float velocity, bool isRunning,  float loadCapacity, float correntLoad)
    : Vehicle(engine, owner, model, price, weight, speed, year, velocity, isRunning), _loadCapacity(loadCapacity), _correntLoad(correntLoad) {}

Truck::~Truck() {
    cout << "Truck object with model " << getModel() << ", production year " << getProductionYear() << ", and owner " << getOwner() << " was deleted." << endl;
}

float Truck::getLoadCapacity() const { return _loadCapacity; }

float Truck::getCorrentLoad() const { return _correntLoad; }

void Truck::setLoadCapacity(float loadCapacity) { _loadCapacity = loadCapacity; }

void Truck::setCorrentLoad(float correntLoad) { _correntLoad = correntLoad; }

void Truck::draw()  {
    cout << *this;
}

void Truck::start() {
    std::cout << "\nThe truck started moving\n ";
    setIsRunning(1);
}
void Truck::accelerate(double tillVelocity) {
    std::cout << "\nTruck speed increased by " << tillVelocity << " time\n";
    setVelocity(tillVelocity + getVelocity());
}
void Truck::stop() {
    std::cout << "\nThe truck stoped moving\n ";
    setIsRunning(0);
}


ostream& operator<<(ostream& out, const Truck& truck)
{
    out << static_cast<const Vehicle&>(truck);
    out << "\nCargo Capacity: " << truck.getLoadCapacity() << endl;
    return out;
}

istream& operator>>(istream& in, Truck& truck)
{
    Engine engine;
    string owner, model;
    float price, weight, speed, loadCapacity;
    int year;

    cout << "Enter truck details: " << endl;

    cout << "Model: ";
    getline(in, model);
    truck.setModel(model);

    cout << "Production year: ";
    in >> year;
    truck.setProductionYear(year);

    cout << "Engine type (0 - diesel, 1 - petrol, 2 - gas, 3 - electric): ";
    int engineType;
    in >> engineType;
    engine.setEngineType(static_cast<engineTypes>(engineType));

    cout << "Engine model: ";
    in.ignore();
    getline(in, model);
    engine.setEngineModel(model);

    cout << "Year of issue: ";
    in >> year;
    engine.setYearOfIssue(year);

    truck.setEngineOfVehicle(engine);

    cout << "Owner: ";
    in.ignore();
    getline(in, owner);
    truck.setOwner(owner);

    cout << "Price: ";
    in >> price;
    truck.setPrice(price);

    cout << "Weight: ";
    in >> weight;
    truck.setWeight(weight);

    cout << "Maximum speed: ";
    in >> speed;
    truck.setMaximumSpeed(speed);

    cout << "Cargo capacity: ";
    in >> loadCapacity;
    truck.setLoadCapacity(loadCapacity);

    return in;
}
