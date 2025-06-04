#include "Wheel.h"
#include <stdexcept>

namespace C3{

Wheel::Wheel(){
	pressure = 0;
	tyreType = nullptr;
}

Wheel::Wheel(TyreType *tt){
	pressure = 0;
	tyreType = tt;
}

Wheel::Wheel(const Wheel &wheel){
	pressure = wheel.pressure;
	tyreType = wheel.typeType;
}

void Wheel::setTyreType(TyreType *tt){
	tyreType = tt;	
}

TyreType *Wheel::getTyreType() const{
	return tyreType;
}

void Wheel::inflate(double p){
	if(p < 0){
		throw range_error("Wrong pressure");
	}
	if(tyreType == nullptr){
		throw "No TyreType";
	}
	if(p < tt->getMinPressure() || p > tt->getMaxPressure()){
		throw range_error("Wrong pressure");
	}
	pressure = p;
}

}
