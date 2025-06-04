#ifndef _CAR_H_
#define _CAR_H_
#include "Wheel.h"
#include <iostream>
using namespace std;

namespace C3{

// PROPONIDO PARA MAÑANA
// SUPONIENDO QUE LA RELACION QUE HAY ENTRE WHEEL Y CAR SEA
// UNA AGREGACION!!, que tendriamos que cambiar?

class Car{
	private:
		static const int MAX_WHEELS;
		vector<Wheel> wheels; // hasta 4.
	public:
		Car();
		Car(const Car &car);
		void addWheel(const Wheel &w);
		vector<Wheel> getWheels() const;
		void changeTyres(TyreType tt, double d)
};

}

#endif
