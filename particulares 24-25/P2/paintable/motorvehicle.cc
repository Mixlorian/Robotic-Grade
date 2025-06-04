#include "motorvehicle.h"

namespace C4{

MotorVehicle::MotorVehicle(int m, int d):Vehicle(m){
	doors = d;
}

void MotorVehicle::paint(string color){
	cout << "painting a motor vehicle on " << color << endl;
}

int MotorVehicle::getNumberOfDoors() const{
	return doors;
}

void MotorVehicle::start(){
	cout << "Turn on a motorvehicle" << endl;
}

MotorVehicle::~MotorVehicle(){
	cout << "destroying a vehicle" << endl;
}

ostream &operator<<(ostream &os, const MotorVehicle &mv){
	os << "MV (" << mv.model << ")";
	return os;
}


}
