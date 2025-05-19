#include "ship.h"
#include "xwing.h"
#include "tiefighter.h"
#include "stardestroyer.h"


using namespace std;
using namespace P4;

// funcion libre
void imprimirShip(const Ship &ship){
	cout << "In mission: " << (ship.is_in_mission()? "SI" : "NO") << endl; 
	cout << "Energy: " << ship.get_energy() << endl;
}


void print_informer(const Ship *ship){
	cout << "Sending to mission: " << *ship << endl;
}

void print_cosicah(const Ship *ship){
	cout << "mursianico al rescate " << ship->get_energy() << endl;
}

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
	
	ship = new XWing('F', 12);
	
	ship->get_mission_signal().connect(print_informer);
	ship->get_mission_signal().connect(print_cosicah);
	
	cout << *ship << endl;
	// cout << "Energy: " << ship->get_energy() << endl;
	imprimirShip(*ship);
	
	cout << "Send to mission: " << endl;
	ship->run_mission(); // XWing *this = ship;
	imprimirShip(*ship);
	

	P4::Ship *ship2 = new XWing('R', 300);
	ship2->get_mission_signal().connect(print_informer);
	ship2->run_mission(); // XWing *this = ship2;

	vector<Ship *> the_ships;
	the_ships.push_back(ship);
	the_ships.push_back(ship2);
	the_ships.push_back(new StarDestroyer('0', 100));

	vector<RebelShip *> the_rebels;
	vector<ImperialShip *> the_imperials;
	
	// XWing => 'A',100 'B',200 'C',50
	// Tie-Fighter => 'a',100 'b',50
	// StarDestroyer => 'd', 300
	
	the_rebels.push_back(new XWing('A', 100));
	the_rebels.push_back(new XWing('B', 200));
	the_rebels.push_back(new XWing('C', 50));
	
	the_imperials.push_back(new TIEFighter('a', 100));
	the_imperials.push_back(new TIEFighter('b', 50));
	the_imperials.push_back(new StarDestroyer('d', 300));
	
	
	
	// mandar a mision a todos los rebeldes y los imperiales!!
	cout << "Rebelship to mission: " << endl;
	for(RebelShip *rs : the_rebels){
		rs->get_mission_signal().connect(print_informer);
		rs->run_mission();
		cout << rs->get_energy() << endl;

	}
	cout << "Imperiales a mision: " << endl;
	for(ImperialShip *is : the_imperials){
		is->get_mission_signal().connect(print_informer);
		is->run_mission();
		cout << is->get_energy() << endl;

	}
	
	return 0;
}
