#include "house.h"

namespace C4{

House::House(){
	cout << "Building a fucking house" << endl;
}

House::~House(){
	cout << "House destroyed" << endl;
}

void House::paint(string color){
	cout << "Painting a house on " << color << endl;
}

}
