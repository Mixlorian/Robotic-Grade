#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <cstdint>
#include <iostream>
using namespace std;
namespace C3{

class Vehicle{
	private:
		float weight;
		uint8_t nwheels;
		uint16_t autonomy;
		float speed;
	public:
		Vehicle(float weight, uint8_t nwheels, uint16_t autonomy);
		virtual ~Vehicle();
		void set_weight(float w);
		void set_nwheels(uint8_t n);
		void set_autonomy(uint16_t a);
		void set_speed(float s);
		
		float get_weight() const;
		uint8_t get_nwheels() const;
		uint16_t get_autonomy() const;
		float get_speed() const;
};

using VehiclePtr = Vehicle *;

}
#endif
