#include "B.h"
#include <exception>

namespace C3{

B::B(int x, int y){
	if(x == y){
		throw invalid_argument("duplicated value " + to_string(x));
	}
	this->x = x;
	this->y = y;	
}

int B::getX() const{
	return x;
}

int B::getY() const{
	return y;
}

void B::setX(int x){
	this->x = x;
}

void B::setY(int y){
	this->y = y;
}

// no es un metodo de clase juan, es una puta funcion
// amiga, estamos locoooos!!!
ostream &operator<<(ostream &os, const B &b){
	os << b.x << " " << b.y;
	return os;
}

}

