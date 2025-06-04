#ifndef _CAR_H 
#define _CAR_H_
#include "motorvehicle.h"
#include <iostream>
using namespace std;

namespace C3{
    class Car : public MotorVehicle{
        public: 
            Car(int m);
            ~Car();
    };
}

#endif