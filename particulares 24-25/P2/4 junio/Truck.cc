#include "truck.h"
#include <iostream>

using namespace std; 

namespace C3{
    Truck::Truck(int m) : MotorVehicle(m,2){

    }
    void Truck::start(){
        cout << "A truck has been started" << endl;
    }
    string Truck::customModel(){
        return "customed" + getModel();
    }

}