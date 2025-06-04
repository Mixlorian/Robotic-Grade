#include "motorvehicle.h"
#include <iostream>

using namespace std;

namespace C3{
    MotorVehicle::MotorVehicle(int m, int d):Vehicle(m){
        doors = d;
    }
    MotorVehicle::~MotorVehicle(){
        cout << "Motor Vehicle has been destroyed" << endl;
    }
    void MotorVehicle::paint(string color){
        cout << "Motor Vehicle has been painted with color " << color << endl;
    }
    int MotorVehicle::getNumberOfDoors() const{
        return doors;
    }
    void MotorVehicle::start(){
        cout << "Motor Vehicle has been started" << endl;
    }
    ostream &operator<<(ostream &os, const MotorVehicle &mv){
        os << "MV (" << mv.model << ")";
        return os;
    }

}