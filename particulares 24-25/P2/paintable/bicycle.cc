#include "bicycle.h"

namespace C4{

Bicycle::Bicycle(int m):Vehicle(m){
	
}

Bicycle::~Bicycle(){
	cout << "Destroying your ass (bicycle)" << endl;
}

void Bicycle::paint(string color){
	cout << "Painting( " 
	<< model << ") a bicycle on " 
	<< color << endl;
}

void Bicycle::start(){
	cout << "turn on the bicycle" << endl;
}


}
