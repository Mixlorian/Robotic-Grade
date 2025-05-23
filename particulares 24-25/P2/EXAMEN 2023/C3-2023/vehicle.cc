#include "vehicle.h"

namespace C3{

Vehicle::~Vehicle(){
	std::cout << "~Vehicle" << endl;
}


Vehicle::Vehicle(float weight, uint8_t nwheels, uint16_t autonomy){
	speed = 0;
	this->weight = weight;
	this->nwheels = nwheels;
	this->autonomy = autonomy;
}

void Vehicle::set_weight(float w){
	weight = w;
}

void Vehicle::set_nwheels(uint8_t n){
	nwheels = n;
}

void Vehicle::set_autonomy(uint16_t a){
	autonomy = a;
}

void Vehicle::set_speed(float s){
	speed = s;
}

float Vehicle::get_weight() const{
	return weight;
}

uint8_t Vehicle::get_nwheels() const{
	return nwheels;
}

uint16_t Vehicle::get_autonomy() const{
	return autonomy;
}

float Vehicle::get_speed() const{
	return speed;
}}
