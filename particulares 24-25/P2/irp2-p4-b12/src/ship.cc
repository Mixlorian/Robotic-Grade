#include "ship.h"
#include <iostream>
using namespace std;

namespace P4{

// polimorfismo puro: parametros de tipo base (punteros or referencias)
// recibiendo objetos de tipo derivado.
ostream &operator<<(ostream &os, const Ship &s){
	os << "[" << s.c << "]";
	return os;
}

Ship::Ship(char c, uint energy){
	this->c = c;
	this->energy = energy;
	this->in_mission = false;
}

void Ship::set_drawing_char(char c){
	this->c = c;
}

char Ship::get_drawing_char() const{
	return c;
}

void Ship::set_in_mission(bool in_mission){
	this->in_mission = in_mission;
}

bool Ship::is_in_mission() const{
	return in_mission;
}

uint Ship::get_energy() const{
	return energy;
}

void Ship::set_energy(uint energy){
	this->energy = energy;
}

void Ship::reduce_energy(uint energy){
	if(energy > this->energy){
		this->energy = 0;
	}
	else{
		this->energy -= energy;
	}
}

mission_sig_t &Ship::get_mission_signal(){
	return mission_sig;
}

}
