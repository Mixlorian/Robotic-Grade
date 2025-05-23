#include "stardestroyer.h"

namespace P4{

StarDestroyer::StarDestroyer(char symbol, uint energy):ImperialShip(symbol, energy){
}

StarDestroyer::~StarDestroyer(){
}

void StarDestroyer::run_mission(){
	set_in_mission(true);
	reduce_energy(50);
	get_mission_signal()(this);	
}

}
