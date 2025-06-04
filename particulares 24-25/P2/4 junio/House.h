#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "Paintable.h"
#include <iostream>

using namespace std;

namespace C3{
    class House : public Paintable{
        public:
            House();
            virtual ~House();
            void paint(string color) override;
    };
}
#endif