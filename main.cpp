#include <iostream>
#include <typeinfo>

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

using namespace std;

int main() {
   
    Engine engine(gas, "V8", 2003, 2500);
    Engine engine2(diesel, "MH", 2022, 3200);
    //Car car2(engine2, "Jane Smith", "Toyota Corolla", 17000.0, 1400.0, 300.0, 2020,150, 0, 6);
    Car car3(engine, "Jane Smith", "Toyota Corolla", 25000.0, 2300.0, 200.0, 2010,160,0, 2);
    Car car4(engine2, "Jane noSmith", "Toyota noCorolla", 26000.0, 2370.0, 300.0, 2020, 170, 0, 3);
    //Truck truck(engine, "Mike Johnson", "Ford F-150", 35000.0, 3000.0, 160.0, 2020,180, 0, 2000.0, 1000);
    //Truck truck2(engine, "Mike Johnson", "Ford F-150", 35000.0, 3000.0, 160.0, 2020, 190, 0, 10000, 2000);

    //Car arrOfCars[]{ car, car2, car3, car4 };
    const int arrSize = 4;
    Vehicle* arrOfVehicle[arrSize];
    arrOfVehicle[0] = new Car(engine, "Jane Smith", "Toyota Corolla", 15000.0, 1300.0, 200.0, 2010, 140, 0, 5);
    arrOfVehicle[1] = new Car(engine2, "Jane Smith", "Toyota Corolla", 17000.0, 1400.0, 300.0, 2020, 150, 0, 6);
    arrOfVehicle[2] = new Truck(engine, "Mike Johnson", "Ford F-150", 35000.0, 3000.0, 160.0, 2020, 180, 0, 2000.0, 1000);
    arrOfVehicle[3] = new Truck(engine, "Mike Johnson", "Ford F-150", 35000.0, 3000.0, 160.0, 2020, 190, 0, 10000, 20000);
    for (int i = 0; i < arrSize; i++) {
        if (Truck* truckPtr = dynamic_cast<Truck*>(arrOfVehicle[i])) {
            if (truckPtr->getCorrentLoad() > 10000) {
                cout << "\nThe truck corrent load is more than 10000\n";
                continue;
            }
        }
        arrOfVehicle[i]->run(15);
    }

    for (int i = 0; i < arrSize; i++) {
        cout << "The type of deleted object was " << typeid(*arrOfVehicle[i]).name() << endl;
        delete arrOfVehicle[i];
        
    }


    /*cout << "Engine:\n" << engine << endl;
    cout << "Vehicle:\n" << vehicle << endl;
    cout << "Car:\n" << car << endl;
    cout << "Truck:\n" << truck << endl;*/

    /*cout << "Enter information for Engine:\n";
    cin >> engine;
    cout << "Enter information for Vehicle:\n";
    cin >> vehicle;
    cout << "Enter information for Car:\n";
    cin >> car;
    cout << "Enter information for Truck:\n";
    cin >> truck;

    cout << "Engine:\n" << engine << endl;
    cout << "Vehicle:\n" << vehicle << endl;
    cout << "Car:\n" << car << endl;
    cout << "Truck:\n" << truck << endl;*/

    int i,j;
    /*for (i = 0; i < 4; i++) {
        float max = arrOfCars[i].getEngineOfVehicle().getEnginePower();
        int k = i;
        for (j = i + 1;j < 4;j++) {
            if (arrOfCars[j].getEngineOfVehicle().getEnginePower() > max) {
                max = arrOfCars[j].getEngineOfVehicle().getEnginePower();
                k = j;
            }
        }
        if (k != i) {
            Car car0 = arrOfCars[i];
            arrOfCars[i] = arrOfCars[k];
            arrOfCars[k] = car0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (arrOfCars[i].getNumSeats() <= 5) cout << arrOfCars[i];
    }*/

    return 0;
}