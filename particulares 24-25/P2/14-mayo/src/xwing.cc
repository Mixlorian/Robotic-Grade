#include "xwing.h"

namespace P4{

XWing::XWing(char symbol, uint energy):RebelShip(symbol, energy){

}

XWing::~XWing(){

}

// XWing my_ship('X', 1000);
// my_ship.run_mission(); // XWing *this = &my_ship;


void XWing::run_mission(){ // la clase ya no es abstracta!
	set_in_mission(true);
	reduce_energy(20);
	get_mission_signal()(this);	
	// esto ejecuta los metodos que has conectado a la señal
	// y le paso como parametro (a todos esos metodos) la
	// direccion del objeto que invoco el metodo.
}

}
