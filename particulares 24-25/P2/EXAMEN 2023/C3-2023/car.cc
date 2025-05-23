#include "car.h"

namespace C3{

Car::~Car(){
	std::cout << "~Car" << std::endl;	
}

Car::Car(float w, uint8_t n, uint16_t a, float c, string b):Gaspowered(w, n, a, c), brand(b){

}

void Car::set_brand(string n){
	brand = n;
}

string Car::get_brand() const{
	return brand;
}

}
