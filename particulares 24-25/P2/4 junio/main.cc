#include <iostream>
#include <vector>
#include "car.h"
#include "truck.h"
#include "motorvehicle.h"
using namespace std;

using namespace C3;

int main(){
	vector<MotorVehicle *> mv;
	
	mv.push_back(new Car(32));
	mv.push_back(new Truck(30));
	
	for(int i = 0; i < mv.size(); i++){
		cout << *(mv[i]) << endl;
	}
	
	 return 0;
}
