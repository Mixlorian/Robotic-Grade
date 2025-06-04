#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>
#include "paintable.h"
using namespace std;

namespace C4{

class Vehicle : public Paintable{
	protected:
		int model;
	public:
		Vehicle(int m);
		virtual void start() = 0;
		int getModel() const;
		virtual ~Vehicle();
		// lo heredo abstracto, no se pone esta heredado.
};

}



#endif
