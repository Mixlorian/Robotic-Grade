#include "car.h"
#include <iostream>

using namespace std;

namespace C3{
    Car::Car(int m):MotorVehicle(m,4){
        cout << "A car has been created" << endl;
    }
    Car::~Car(){
        cout << "A car has been destroyed" << endl;
    }
}