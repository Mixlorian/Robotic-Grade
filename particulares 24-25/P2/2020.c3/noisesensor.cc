#include "noisesensor.h"

namespace C3{

NoiseSensor::NoiseSensor(const std::string name):Sensor<float>(name){
			
}

NoiseSensor::~NoiseSensor(){

}

void NoiseSensor::set_level (float l){
	Sensor<float>::set_level(l);
}

float NoiseSensor::get_level (){
	return Sensor<float>::get_level();
}

}
