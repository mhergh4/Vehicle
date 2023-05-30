#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>

using namespace std;

enum engineTypes
{
    diesel,
    petrol,
    gas,
    electric
};

class Engine
{
public:
    Engine(engineTypes type, string model, int year, float power);
    Engine();
    Engine(engineTypes type);
    Engine(string model);
    Engine(int year);
    Engine(float power);
    ~Engine();

    void setEngine(engineTypes type, string model, int year, float power);
    void setEngineType(engineTypes type);
    void setEngineModel(string model);
    void setEnginePower(float power);
    void setYearOfIssue(int year);
    engineTypes getEngineType() const;
    string getEngineModel() const;
    int getYearOfIssue() const;
    float getEnginePower() const;

    friend ostream& operator<<(ostream& os, const Engine& engine);
    friend istream& operator>>(istream& is, Engine& engine);

private:
    engineTypes _engineType;
    string _engineModel;
    int _yearOfIssue;
    float _enginePower;
};

#endif

