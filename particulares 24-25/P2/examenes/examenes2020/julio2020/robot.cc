#include "robot.h"


namespace C3{
	// Es una variable compartida por todos los objetos de la clase.
	// Al no estar vinculada a ningun objeto se declara aqui.

	uint Robot::totalRobotsCreated = 0;

	Robot::Robot(const std::string name){
		theName = name;
		totalRobotsCreated++;
	}

	Robot::~Robot(){

	}

	std::string Robot::get_name (){
		return theName;
	}

	void Robot::add_sensor (NoiseSensorPtr aSensor){
		theSensors.push_back(aSensor);
	}

	// Devuelve el sensor en la
	// posicion 's'
	NoiseSensorPtr Robot::get_sensor(uint s){  
		return theSensors[s];
	}

	// Metodo que tiene aqui implementacion pero tiene pinta de que se sobrescibira
	// en las derivadas
	uint Robot::get_num_sensors(){
		return theSensors.size();
	}

	// esto es un metodo de clase no tiene objeto implicito no tiene this
	// se invoca con el nbore clase, solamanete puede acceder a las varaibles de clase.
	// cout << Robot::get_total_robots_created() << endl;
	uint Robot::get_total_robots_created (){
		return totalRobotsCreated;
	}
}

