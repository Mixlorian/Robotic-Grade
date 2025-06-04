#ifndef _PAINTABLE_H_
#define _PAINTABLE_H_
#include <iostream>
using namespace std;

namespace C4{

class Paintable{
	public:
		virtual void paint(string color)  = 0;
		virtual ~Paintable() = default;
};

}

#endif
