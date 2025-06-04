#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "paintable.h"

namespace C4{

class House : public Paintable{
	public:
		House();
		virtual ~House();
		void paint(string color);
};


}


#endif
