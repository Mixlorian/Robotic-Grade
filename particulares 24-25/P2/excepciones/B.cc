#include "B.h"

B::B(int x, int y){
	if(x == y){
		throw invalid_argument(to_string(x) + " duplicated");
	}
	if(x < 10 || x > 99){
		throw out_of_range(to_string(x));
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

ostream &operator<<(ostream &os, const B &b){
	os << b.x << " " << b.y;
	return os;
}
