
#include "Vehicle.h"

Vehicle::Vehicle(Engine engine, string owner, string model, float price, float weight, float speed, int year, float velocity, bool isRunning)
    : _engine(engine), _owner(owner), _model(model), _price(price), _weight(weight), _maximumSpeed(speed), _productionYear(year), _velocity(velocity), _isRunning(isRunning) {}

Vehicle::Vehicle()
    : _engine(), _owner("Mher"), _model("BMW"), _price(20000), _weight(300), _maximumSpeed(310), _productionYear(2023), _velocity(100), _isRunning(0) {}

Vehicle::~Vehicle()
{
    cout << "Vehicle object with model " << getModel() << ", production year " << getProductionYear() << ", and owner " << getOwner() << " was deleted." << endl;
}

void Vehicle::setEngineOfVehicle(Engine engine)
{
    _engine.setEngine(engine.getEngineType(), engine.getEngineModel(), engine.getYearOfIssue(), engine.getEnginePower());
}

void Vehicle::setOwner(string owner)
{
    _owner = owner;
}

void Vehicle::setModel(string model)
{
    _model = model;
}

void Vehicle::setPrice(float price)
{
    _price = price;
}

void Vehicle::setWeight(float weight)
{
    _weight = weight;
}

void Vehicle::setMaximumSpeed(float speed)
{
    _maximumSpeed = speed;
}

void Vehicle::setProductionYear(int year)
{
    _productionYear = year;
}

void Vehicle::setVelocity(float velocity)
{
    _velocity = velocity;
}

void Vehicle::setIsRunning(bool isRunning)
{
    _isRunning = isRunning;
}

void Vehicle::setVehicle(Engine engine, string owner, string model, float price, float weight, float speed, int year, float velocity, bool isRunning)
{
    setEngineOfVehicle(engine);
    setOwner(owner);
    setModel(model);
    setPrice(price);
    setWeight(weight);
    setMaximumSpeed(speed);
    setProductionYear(year);
    setVelocity(velocity);
    setIsRunning(isRunning);
}

Engine Vehicle::getEngineOfVehicle() const
{
    return _engine;
}

string Vehicle::getOwner() const
{
    return _owner;
}

string Vehicle::getModel() const
{
    return _model;
}

float Vehicle::getPrice() const
{
    return _price;
}

float Vehicle::getWeight() const
{
    return _weight;
}

float Vehicle::getMaximumSpeed() const
{
    return _maximumSpeed;
}

int Vehicle::getProductionYear() const
{
    return _productionYear;
}

float Vehicle::getVelocity() const
{
    return _velocity;
}

bool Vehicle::getIsRunning() const
{
    return _isRunning;
}

 void  Vehicle:: draw() {
    cout << *this;
}

 void Vehicle::run(double tillVelocity) {
     start();
     accelerate(tillVelocity);
     stop();
 }

ostream& operator<<(ostream& os, const Vehicle& vehicle)
{
    os << "Owner: " << vehicle.getOwner() << endl;
    os << "Model: " << vehicle.getModel() << endl;
    os << "Price: " << vehicle.getPrice() << endl;
    os << "Weight: " << vehicle.getWeight() << endl;
    os << "Maximum speed: " << vehicle.getMaximumSpeed() << endl;
    os << "Production year: " << vehicle.getProductionYear() << endl;
    os << "Engine: " << endl
        << vehicle.getEngineOfVehicle();
    return os;
}

istream& operator>>(istream& is, Vehicle& vehicle)
{
    Engine engine;
    is >> engine;
    vehicle.setEngineOfVehicle(engine);
    cout << "Enter owner: ";
    string owner;
    is >> owner;
    vehicle.setOwner(owner);
    cout << "Enter model: ";
    string model;
    is >> model;
    vehicle.setModel(model);
    cout << "Enter price: ";
    float price;
    is >> price;
    vehicle.setPrice(price);
    cout << "Enter weight: ";
    float weight;
    is >> weight;
    vehicle.setWeight(weight);
    cout << "Enter maximum speed: ";
    float speed;
    is >> speed;
    vehicle.setMaximumSpeed(speed);
    cout << "Enter production year: ";
    int year;
    is >> year;
    vehicle.setProductionYear(year);
    return is;
}
