// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "xwing.h"

namespace P4{

    XWing::XWing(char symbol, uint energy):RebelShip(symbol, energy){
    }

    XWing::~XWing(){
    }

    void XWing::run_mission(){ 
        set_in_mission(true);
        reduce_energy(20);
        get_mission_signal()(this);	

    }
}