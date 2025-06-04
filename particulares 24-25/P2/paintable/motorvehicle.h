#ifndef _MOTORVEHICLE_H_
#define _MOTORVEHICLE_H_
#include "vehicle.h"

namespace C4{

class MotorVehicle : public Vehicle{
	friend ostream &operator<<(ostream &os, const MotorVehicle &mv);
	protected:
		int doors;
	public:
		MotorVehicle(int m, int d);
		~MotorVehicle();
		void paint(string color);
		int getNumberOfDoors() const;
		void start();
};

}

#endif
