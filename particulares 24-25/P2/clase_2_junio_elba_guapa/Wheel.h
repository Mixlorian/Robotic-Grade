#ifndef _WHEEL_H_
#define _WHEEL_H_
#include <iostream>
#include "TyreType.h"
using namespace std;

namespace C3{

class Wheel{
	private:
		TyreType *tyreType;
		double pressure;
	public:
		Wheel();
		Wheel(TyreType *tt);
		Wheel(const Wheel &wheel);
		
		void setTyreType(TyreType *tt);
		TyreType *getTyreType() const;
		void inflate(double p);
};

}
#endif
