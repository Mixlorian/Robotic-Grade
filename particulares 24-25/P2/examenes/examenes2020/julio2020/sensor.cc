#include "sensor.h"

namespace C3 {

	template <typename T>
	Sensor<T>::Sensor(const std::string name){
		theName = name;	
	}

	template <typename T>
	Sensor<T>::~Sensor(){

	}

	template <typename T>
	std::string Sensor<T>::get_name(){
		return theName;
	}

	template <typename T>
	void Sensor<T>::set_level(T l){
		theLevel = l;
	}

	template <typename T>
	T Sensor<T>::get_level(){
		return theLevel;
	}

}


