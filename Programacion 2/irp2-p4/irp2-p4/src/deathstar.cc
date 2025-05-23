// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "deathstar.h"

namespace P4{

    DeathStar::DeathStar(const std::string& name):Container(name){
    }

    DeathStar::~DeathStar(){
    }

    void DeathStar::send_all_on_mission(){
        for(HangarPtr h : items){
            while(h->size() > 0){
                ShipPtr sp = (*h)[0];
                mission_ships.add(sp);
                sp->run_mission();
                h->remove(0);	
            }
        }
    }

    void DeathStar::recall_ship_to_hangar(ShipPtr ship, HangarPtr hangar){
        if(find(hangar) != numeric_limits<uint16_t>::max() && mission_ships.find(ship) != numeric_limits<uint16_t>::max()){
            mission_ships.remove(ship);
            hangar->add(ship);
            ship->set_in_mission(false);		
        }
    }
}