#include "ship.h"


using namespace P4;

int main(){
	// Esta dentro del espacio de nombres.
	// no hace falta que lo ponga porque he puesto el using.
	// Es correcto porque no creo Ship, guardare direcciones de
	// memoria de derivadas.
	P4::Ship *ship;
	
	// El puntero tendra que apuntar a derivada que si hayan
	// implementado (sobrescrito) el metodo puro.
	// Ship *ship2 = new Ship('F', 12);	
	
	// Esto nunca ^ ^
	// Ship ship1('F', 12);
	
	return 0;
}
