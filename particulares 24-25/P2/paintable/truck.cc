#include "truck.h"

namespace C4{

Truck::Truck(int m) : MotorVehicle(m, 2){
	
}

string Truck::customModel(){
	return "customed " + getModel();
}

void Truck::start(){
	cout << "starting a vehicle" << endl;
	
}

}
