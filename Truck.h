#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck();
    Truck(Engine engine, string owner, string model, float price, float weight, float speed, int year, float velocity, bool isRunning,  float loadCapacity, float correntLoad);
    ~Truck();

    float getLoadCapacity() const;
    void setLoadCapacity(float loadCapacity);

    float getCorrentLoad() const;
    void setCorrentLoad(float loadCapacity);

    virtual void draw() ;
    
    friend ostream& operator<<(ostream& out, const Truck& truck);
    friend istream& operator>>(istream& in, Truck& truck);

private:
    float _loadCapacity;
    float _correntLoad;

    void start() override;
    void accelerate(double tillVelocity) override;
    void stop() override;
};

#endif // TRUCK_H
