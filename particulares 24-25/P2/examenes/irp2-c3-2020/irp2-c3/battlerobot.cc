#include "battlerobot.h"

using namespace C3;


    
    BattleRobot::BattleRobot(const std::string name, uint mapSize):Robot(name),attackLevel(0.0),
    damage(0.0),theMapSize(mapSize){
    
    map = new RobotPtr*[mapSize];

    for(uint i=0;i<mapSize;i++){
        map[i] = new RobotPtr [mapSize];
    }
    for(uint i = 0; i < theMapSize; i++){
		for(uint j = 0; j< theMapSize; j++){
			map[i][j] = nullptr;
		}
	}


    }
    BattleRobot::~BattleRobot(){
	if(map != nullptr){
		// libero los robots que hay en el mapa
		for(int i = 0; i < (int) theMapSize; i++){
			for(int j = 0; j < (int) theMapSize; j++){
				if(map[i][j] != nullptr){
					delete map[i][j];
				}
			}
		}
		for(int i = 0; i < (int) theMapSize; i++){
			delete[] map[i];
		}
		delete[] map;
    }
    }
    
    bool BattleRobot::canWalk (){
        return true;
    }
    bool BattleRobot::canTalk (){
        return false;
    }
    uint BattleRobot::get_num_sensors(){

            uint total = 0;

        for(uint i = 0; i < theMapSize; i++){
            for(uint j = 0; j < theMapSize; j++){
                if(map[i][j] != nullptr){
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
        attackLevel=l;
    }
    float BattleRobot::get_damage (){
        return damage;
    }
    void BattleRobot::set_damage (float d){
        damage = d;
    }

    bool BattleRobot::add_robot_at(uint x, uint y, RobotPtr r){
        if(x>=0 and x<theMapSize and y>=0 and y<theMapSize){
            if(map[x][y]!=nullptr){
                delete map[x][y];
                map[x][y]=r;
                return true;
            }else{
                map[x][y]=r;
                return true;
            }
        }
        robotNotAddedSignal(this,r,x,y);
        return false;
    }