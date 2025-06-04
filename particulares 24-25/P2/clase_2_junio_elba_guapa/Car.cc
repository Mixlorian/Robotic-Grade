#include "Car.h"

namespace C3{

const int Car::MAX_WHEELS = 4;

Car::Car(){
	// ya se incializa a vacio.
}

Car::Car(const Car &car){
	for(int i = 0; i < car.wheels.size(); i++){
		// El push_back copia en la ultima posicion
		// del vector la rueda pasada como parametro.
		wheels.push_back(car.wheels[i]);
	}
}

void Car::addWheel(const Wheel &w){
	if(MAX_WHEELS == wheels.size()){
		throw "Too many wheels exceptions";
	}
	if(wheels.size() > 0){
		if(w.getTyreType() == nullptr ^ wheels[0].getTyreType() == nullptr){
			throw "Wrong tyre type exception";
		}
		if(w.getTyreType() && wheels[0].getTyreType()){
			if(!(w.getTyreType() == wheels[0].getTyreType())){
				throw "Wrong tyre type exception";
			}
		}
		wheels.push_back(w);		
	}
	
}

/*
if ((w.getTyreType() == nullptr && wheels[0].getTyreType() != nullptr) ||
    (w.getTyreType() != nullptr && wheels[0].getTyreType() == nullptr)) {
    throw "Wrong tyre type exception";
}

*/
vector<Wheel> Car::getWheels() const{
	return wheels;
}

// PROPUESTO PARA MAÑANA!!
// throw "Illegal argument exception";
void Car::changeTyres(TyreType tt, double d){
	
}

}



