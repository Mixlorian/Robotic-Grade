#ifndef _BICYCLE_H_
#define _BICYCLE_H_
#include "vehicle.h"

namespace C4{

class Bicycle : public Vehicle{
	public:
		Bicycle(int m);
		~Bicycle();
		void paint(string m);
		void start();		
};

}
#endif
