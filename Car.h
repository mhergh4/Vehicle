#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Vehicle.h"
#include "Engine.h"

class Car : public Vehicle {
public:
	Car();
	Car(Engine engine, std::string owner, std::string model, float price, float weight, float speed, int year, float velocity, bool isRunning, int numSeats);
	~Car();
	int getNumSeats() const;
	void setNumSeats(int numSeats);

	virtual void draw() override;

	friend std::ostream& operator<<(std::ostream& os, const Car& car);
	friend std::istream& operator>>(std::istream& is, Car& car);

private:
	int _numSeats;

	void start() override;
	void accelerate(double tillVelocity) override;
	void stop() override;
};

#endif 