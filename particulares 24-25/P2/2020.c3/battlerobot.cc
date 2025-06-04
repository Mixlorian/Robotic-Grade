#include "battlerobot.h"

namespace C3{

BattleRobot::BattleRobot(const std::string name, uint mapSize):Robot(name){
	theMapSize = mapSize;
	attackLevel = damage = 0;

	// RobotPtr** map; /	
	map = new RobotPtr * [mapSize];
	for(uint32_t i = 0; i < mapSize; i++){
		map[i] = new RobotPtr [mapSize];
		for(uint32_t j = 0; j < mapSize; j++){
			map[i][j] = nullptr;
		}
	}
	
	
}

BattleRobot::~BattleRobot(){
	if(map != nullptr){
		for(int i = 0; i < theMapSize; i++){
			delete [] map[i];
		}
		delete [] map;
		map = nullptr;
		theMapSize = 0;
	}
}

bool BattleRobot::canWalk (){
	return true;
}

bool BattleRobot::canTalk (){
	return false;
}

uint BattleRobot::get_num_sensors(){
	uint totalSensors = Robot::get_num_sensors();
	for(uint i = 0; i < theMapSize; i++){
		for(uint j = 0; j < theMapSize; j++){
			if(map[i][j] != nullptr){
				totalSensors += map[i][j]->get_num_sensors();
			}
		}
	}
	return totalSensors;		
}

float BattleRobot::get_attack_level (){
	return attackLevel;
}

void BattleRobot::set_attack_level (float l){
	attackLevel = l;
}

float BattleRobot::get_damage (){
	return damage;
}

void BattleRobot::set_damage (float d){
	damge = d;
}

bool BattleRobot::add_robot_at(uint x, uint y, RobotPtr r){
	bool added = false, found;
	if(x < theMapSize && y < theMapSize && r != nullptr){
		found = false;
		for(uint i = 0; i < theMapSize && !found; i++){
			for(uint j = 0; j < theMapSize && !found; j++){
				if(map[i][j] == r){
					found = true;
				}		
			}
		}
		if(!found){
			robotNotAddedSignal(this, r, x, y);			
		}
		else{
			if(map[x][y] != nullptr){
				delete map[x][y];
			}
			map[x][y] = r;
			added = true;
		}
	}
	else{
		robotNotAddedSignal(this, r, x, y);
	}
	return added;
}


}
