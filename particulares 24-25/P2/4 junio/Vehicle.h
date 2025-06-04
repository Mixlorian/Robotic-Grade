#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>
#include "Paintable.h"

using namespace std;

namespace C3{
    class Vehicle : public Paintable{
        protected:
            int model;
        public:
            Vehicle(int m);
            virtual void start() = 0;
            virtual ~Vehicle();
            int getModel() const;
    };

}

#endif