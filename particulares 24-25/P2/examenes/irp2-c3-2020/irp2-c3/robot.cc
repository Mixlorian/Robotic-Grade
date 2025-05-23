#include "robot.h"

using namespace C3;
    uint Robot::totalRobotsCreated = 0;
    
    Robot::Robot(const std::string name):theName(name){
        Robot::totalRobotsCreated++;
    }
    Robot::~Robot(){
        for (auto i:theSensors){
            delete i;
        }
    }

// los metodos que no son virtuales solo se implementan en la clase base
    std::string Robot::get_name (){
        return theName;
    }
    void Robot::add_sensor (NoiseSensorPtr aSensor){
        theSensors.push_back(aSensor);
    }
    NoiseSensorPtr Robot::get_sensor(uint s){
        return theSensors[s];
    } // Devuelve el sensor en la
    // posicion 's'

// metodo que tiene aqui implementacion pero tiene pinta de que se sobrescibira
// en las derivadas
   uint Robot::get_num_sensors(){
    return theSensors.size();
   }

// metodo de clase
    uint Robot::get_total_robots_created (){
        return Robot::totalRobotsCreated;
    }
