#include "gaspowered.h"

namespace C3{

Gaspowered::~Gaspowered(){
	std::cout << "~Gaspowered" << std::endl;
}

Gaspowered::Gaspowered(float weight, uint8_t nwheels, uint16_t autonomy, float capacity):Vehicle(weight, nwheels, autonomy), capacity(capacity){

}

void Gaspowered::set_capacity(float c){
	capacity = c;
}

float Gaspowered::get_capacity() const{
	return capacity;
}

}
