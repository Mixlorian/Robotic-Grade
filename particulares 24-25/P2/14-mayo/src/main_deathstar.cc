#include "deathstar.h"
#include "hangar.h"
#include "xwing.h"
#include "tiefighter.h"
#include "stardestroyer.h"
#include <iostream>
using namespace std;
using namespace P4;

void mission_event(const Ship *s) {
  std::cout << "Signal: Ship " << s->get_drawing_char() << " now has " << s->get_energy() << " energy.\n";
}


// t1->get_mission_signal().connect(mission_event);

int main(){
	DeathStar d("death-corbi");
	
	d.add(new Hangar("H-01"));
	d.add(new Hangar("H-02"));
	
	d[0]->add(new XWing('T', 200));
	d[0]->add(new TIEFighter('I', 200));
	d[1]->add(new StarDestroyer('S', 220));
	
	cout << d << endl;

	// conectale a todas las naves el metodo mission event 
	// y manda a todas las naves a misiom
	

	return 0;
}
