#include "basicrobot.h"

namespace C3{

BasicRobot::BasicRobot(const std::string name):Robot(name){
	
}

BasicRobot::~BasicRobot(){

}

bool BasicRobot::canWalk (){
	return false;	
}

bool BasicRobot::canTalk (){
	return false;
}	

}
