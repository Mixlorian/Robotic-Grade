#ifndef _TRUCK_H_
#define _TRUCK_H_
#include "motorvehicle.h"

namespace C4{

class Truck : public MotorVehicle{
	private:
		string customModel();
	public:
		Truck(int m);
		void start();
};

}

#endif
