#include "vehicle.h"

namespace C4{

Vehicle::Vehicle(int m){
	model = m;
}

int Vehicle::getModel() const{
	return model;
}

Vehicle::~Vehicle(){
	cout << "Vehicle destroyed" << endl;
}


}
