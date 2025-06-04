#ifndef _TRUCK_H_
#define _TRUCK_H_
#include "motorvehicle.h"
#include <iostream>
using namespace std;

namespace C3{
    class Truck : public MotorVehicle{
        private:
            string customModel();
        public:
            Truck(int m);
            void start();

    };
}

#endif