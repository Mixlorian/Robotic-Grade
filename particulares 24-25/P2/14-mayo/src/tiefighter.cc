#include "tiefighter.h"

namespace P4{

TIEFighter::TIEFighter(char symbol, uint energy):ImperialShip(symbol, energy){

}

TIEFighter::~TIEFighter(){

}

void TIEFighter::run_mission(){
	set_in_mission(true);
	reduce_energy(10);
	get_mission_signal()(this);	
}

}
