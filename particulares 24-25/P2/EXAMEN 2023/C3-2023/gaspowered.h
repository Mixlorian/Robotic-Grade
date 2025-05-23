#ifndef _GASPOWERED_H_
#define _GASPOWERED_H_
#include "vehicle.h"
#include <iostream>
#include <cstdint>
#include "types.h"
namespace C3{
class Gaspowered : public Vehicle{
	private:
		float capacity;
	public:
		Gaspowered(float weight, uint8_t nwheels, uint16_t autonomy, float capacity);
		~Gaspowered();
		void set_capacity(float c);
		float get_capacity() const;
		
		// abstractos son virtuales puros.
		virtual void set_brand(string n) = 0;
		virtual string get_brand() const = 0;
	
};

PtrTypeFrom(Gaspowered);

}

#endif
