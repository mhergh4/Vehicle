#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "Engine.h"

using namespace std;

class Vehicle {
    virtual void start() = 0;
    virtual void accelerate(double tillVelocity) = 0;
    virtual void stop() = 0;
public:
    Vehicle(Engine engine, string owner, string model, float price, float weight, float speed, int year, float velocity, bool isRunning);
    Vehicle();
    ~Vehicle();

    void setEngineOfVehicle(Engine engine);
    void setOwner(string owner);
    void setModel(string model);
    void setPrice(float price);
    void setWeight(float weight);
    void setMaximumSpeed(float speed);
    void setProductionYear(int year);
    void setVehicle(Engine engine, string owner, string model, float price, float weight, float speed, int year, float velocity, bool isRunning);
    void setVelocity(float velocity);
    void setIsRunning(bool isRunning);

    Engine getEngineOfVehicle() const;
    string getOwner() const;
    string getModel() const;
    float getPrice() const;
    float getWeight() const;
    float getMaximumSpeed() const;
    int getProductionYear() const;
    float getVelocity() const;
    bool getIsRunning() const;

    virtual void draw();

    void run(double tillVelocity);

    friend ostream& operator<<(ostream& os, const Vehicle& vehicle);
    friend istream& operator>>(istream& is, Vehicle& vehicle);

private:
    Engine _engine;
    string _owner;
    string _model;
    float _price;
    float _weight;
    float _maximumSpeed;
    int _productionYear;
    float _velocity;     // New variable for velocity
    bool _isRunning;     // New variable for running state
};

#endif
