#ifndef _CAR_H_
#define _CAR_H_
#include "motorvehicle.h"
#include <iostream>
using namespace std;


namespace C4{

class Car : public MotorVehicle{
	public:
		Car(int m);
		~Car();
};

}

#endif
