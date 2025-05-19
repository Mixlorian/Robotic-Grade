#include "Tupla.h"

Tupla::Tupla(){
}

Tupla::Tupla(int f, int s){
	first = f;
	second = s;	
}

int Tupla::getFirst() const{
	return first;
}

int Tupla::getSecond() const{
	return second;
}

bool Tupla::operator==(const Tupla &de) const{
	return first ==  de.first && second == de.second;
}

bool Tupla::operator!=(const Tupla &de) const{
	return !(*this == de);
}
