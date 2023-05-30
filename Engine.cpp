#include "Engine.h"

Engine::Engine(engineTypes type, string model, int year, float power)
{
    setEngine(type, model, year, power);
}

Engine::Engine() : Engine(gas, "V8", 2003, 25000) {}

Engine::Engine(engineTypes type) : Engine(type, "V8", 2003, 25000) {}

Engine::Engine(string model) : Engine(gas, model, 2003, 25000) {}

Engine::Engine(int year) : Engine(gas, "V8", year, 25000) {}

Engine::Engine(float power) : Engine(gas, "V8", 2003, power) {}


Engine::~Engine()
{
    cout << "Engine object with model " << _engineModel << ", production year " << _yearOfIssue << ", with power " << _enginePower << ", and type ";
    switch (_engineType)
    {
    case diesel:
        cout << "diesel";
        break;
    case petrol:
        cout << "petrol";
        break;
    case gas:
        cout << "gas";
        break;
    case electric:
        cout << "electric";
        break;
    default:
        cout << "unknown";
        break;
    }
    cout << " was deleted." << endl;
}

void Engine::setEngine(engineTypes type, string model, int year, float power)
{
    setEngineType(type);
    setEngineModel(model);
    setYearOfIssue(year);
    setEnginePower(power);
}

void Engine::setEngineType(engineTypes type)
{
    _engineType = type;
}

void Engine::setEnginePower(float power)
{
    _enginePower = power;
}

void Engine::setEngineModel(string model)
{
    _engineModel = model;
}

void Engine::setYearOfIssue(int year)
{
    _yearOfIssue = year;
}

engineTypes Engine::getEngineType() const
{
    return _engineType;
}

string Engine::getEngineModel() const
{
    return _engineModel;
}

int Engine::getYearOfIssue() const
{
    return _yearOfIssue;
}

float Engine::getEnginePower() const
{
    return _enginePower;
}

std::ostream& operator<<(ostream& os, const Engine& engine)
{
    os << "Engine type: ";
    switch (engine.getEngineType())
    {
    case diesel:
        os << "diesel" << endl;
        break;
    case petrol:
        os << "petrol" << endl;
        break;
    case gas:
        os << "gas" << endl;
        break;
    case electric:
        os << "electric" << endl;
        break;
    }
    os << "Engine model: " << engine.getEngineModel() << endl;
    os << "Year of issue: " << engine.getYearOfIssue() << endl;
    os << "Power of engine: " << engine.getEnginePower() << endl;
    return os;
}

std::istream& operator>>(istream& is, Engine& engine)
{
    cout << "Enter engine type (0 - diesel, 1 - petrol, 2 - gas, 3 - electric): ";
    int type;
    is >> type;
    switch (type)
    {
    case 0:
        engine.setEngineType(diesel);
        break;
    case 1:
        engine.setEngineType(petrol);
        break;
    case 2:
        engine.setEngineType(gas);
        break;
    case 3:
        engine.setEngineType(electric);
        break;
    }
    cout << "Enter engine model: ";
    string model;
    is >> model;
    engine.setEngineModel(model);
    cout << "Enter year of issue: ";
    int year;
    is >> year;
    engine.setYearOfIssue(year);
    cout << "Enter power of engine: ";
    float power;
    is >> power;
    engine.setEnginePower(power);
    return is;
}