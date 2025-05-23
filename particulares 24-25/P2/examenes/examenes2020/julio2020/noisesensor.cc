#include "noisesensor.h"
#include "sensor.cc"

namespace C3{

	NoiseSensor::NoiseSensor(const std::string name):Sensor(name){
		
	}

	NoiseSensor::~NoiseSensor(){

	}

	void NoiseSensor::set_level (float l){
		Sensor::set_level(l);	
	}

	float NoiseSensor::get_level (){
		return Sensor::get_level();
	}

}
