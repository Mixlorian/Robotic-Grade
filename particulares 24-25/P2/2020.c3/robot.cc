#include "robot.h"
namespace C3{

uint Robot::totalRobotsCreated = 0; // no hay robots creados.

Robot::Robot(const std::string name){
	theName = name;	
	totalRobotsCreated++; // accede a la varibable de estatico
}

Robot::~Robot(){

}

std::string Robot::get_name (){
	return theName;
}

void Robot::add_sensor (NoiseSensorPtr aSensor){
	theSensors.push_back(aSensor);
}

NoiseSensorPtr Robot::get_sensor(uint s){//Devuelve el sensor en la posicion 's'
	NoiseSensorPtr p = nullptr;
	if(s >= 0 && s < theSensors.size()){
		p = theSensors[s];
	}
	return p;
}

// metodo que tiene aqui implementacion pero tiene pinta de que se sobrescibira
// en las derivadas
uint Robot::get_num_sensors(){
	return theSensors.size();
}

// metodo de clase
uint Robot::get_total_robots_created (){
	return totalRobotsCreated;
}


}
