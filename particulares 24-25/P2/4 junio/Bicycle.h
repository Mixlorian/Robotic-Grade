#ifndef _BICYCLE_H_
#define _BICYCLE_H_
#include <iostream>
#include "vehicle.h"

using namespace std;
namespace C3{
    class Bicycle : public Vehicle{
        public:
            Bicycle(int m);
            ~Bicycle();
            void paint(string color);
            void start();
    }
}

#endif