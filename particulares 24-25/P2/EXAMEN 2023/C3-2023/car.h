#ifndef _CAR_H_
#define _CAR_H_
#include "gaspowered.h"
#include <cstdint>
#include "types.h"

namespace C3{
class Car : public Gaspowered<string>{
	private:
		string brand;
	public:
		Car(float w, uint8_t n, uint16_t a, float c, string b);
		~Car();
		void set_brand(string n);
		string get_brand() const;
		boost::signals2::signal<void (Car*)> sig_change;
};

PtrTypeFrom(Car);

}

#endif
