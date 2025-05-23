#include "battlerobot.h"

namespace C3{

    BattleRobot::BattleRobot(const std::string name, uint mapSize):Robot(name){
   	//RobotPtr** map;
   	theMapSize = mapSize;
   	map = new RobotPtr * [mapSize];
   	for(int i = 0; i < (int) mapSize; i++){
   		map[i] = new RobotPtr [mapSize];
   		for(int j = 0; j < (int) mapSize; j++){
   			map[i][j] = nullptr;
   		}
   	}
   	attackLevel = 0;
    	damage = 0;

    }
    BattleRobot::~BattleRobot(){
    	if(map != nullptr){
    		for(int i = 0; i < (int) theMapSize; i++){
    			delete [] map[i];
    		}
    		delete [] map;
    		map = nullptr;
    	}
    }
    
    bool BattleRobot::canWalk (){
    	return true;
    }
    bool BattleRobot::canTalk (){
    	return false;
    }
    uint BattleRobot::get_num_sensors(){
    	uint total = Robot::get_num_sensors();
    	
    	for(int i = 0; i < (int) theMapSize; i++){
    		for(int j = 0; j < (int) theMapSize; j++){
    			if(map[i][j]){
    				total += map[i][j]->get_num_sensors();
    			}
    		}
    	}
    	
    	return total;
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
    	damage = d;
    }
    bool BattleRobot::add_robot_at(uint x, uint y, RobotPtr r){
    	bool added = false;
 	if(x >= 0 && x < theMapSize && y >= 0 && y < theMapSize){
 		if(map[x][y] == nullptr){
 			map[x][y] = r;
 		}
 		else{
 			delete map[x][y];
 			map[x][y] = r;
 		}
 		added = true;
 	}
 	else{
 		robotNotAddedSignal(this, r, x, y);
 	}
    	return added;
    }
}





