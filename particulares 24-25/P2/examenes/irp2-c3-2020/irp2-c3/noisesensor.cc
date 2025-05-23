#include "sensor.cc"
#include "noisesensor.h" 
    
    NoiseSensor::NoiseSensor(const std::string name):Sensor(name){}
    NoiseSensor::~NoiseSensor()=default;
    void NoiseSensor::set_level (float l){
        Sensor::set_level(l);
    }
    float NoiseSensor::get_level (){
        return Sensor::get_level();
    }