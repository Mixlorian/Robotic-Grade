#include "deathstar.h"

namespace P4{

DeathStar::DeathStar(const std::string& name):Container(name){
	// El objeto mission_ships se inicializa solo aquis.
}

DeathStar::~DeathStar(){

}

void DeathStar::send_all_on_mission(){
	// para cada hangar.
	for(HangarPtr h : items){
		// mientras queden naves en el hangar.
		while(h->size() > 0){
			ShipPtr sp = (*h)[0];
			mission_ships.add(sp);
			sp->run_mission();
			h->remove(0);	
		}
	}
/*
	Ship *ship;	
	for(int i = 0; i < items.size(); i++){ // es mio protected
		while(items[i].size() > 0){
			ship = (*(items[i]))[0];
			ship->run_mission();
			(*(items[i]))->remove(0);			
			mission_ships.add(ship);
		}
	}	

	int j;
	for(int i = 0; i < items.size(); i++){ // es mio protected
		for(j = 0; j < items[i].size(); j++){
			ship = (*(items[i]))[j];
			ship->run_mission();
			items[i]->remove(j);			
			j--;
			mission_ships.add(ship);
		}
	}	
*/
}

void DeathStar::recall_ship_to_hangar(ShipPtr ship, HangarPtr hangar){
	if(find(hangar) && mission_ships.find(ship)){
		mission_ships.remove(ship);
		hangar->add(ship);
		ship->set_in_mission(false);		
	}
}
}




