#include "noisesensor.h"
#include <iostream>
using namespace std;
using namespace C3;

int main(){
	NoiseSensor ns("holi que tal");
	ns.set_level(12.3);
	cout << ns.get_level() << endl;


	// Como es una plantilla si la quiero usar tengo que instanciar el
	// tipo.
	//Sensor *p = new NoiseSensor("nr-34");	
	Sensor<float> *s = new NoiseSensor("nhr-23");
	
	s->set_level(3.2);
	/*
		- El metodo set_level tiene que estar definido dentro
		de la clase Sensor<float>.
		- virtual?
			si, entonces enlazado dinamico: se mira el objeto al cual 				esta apuntando el puntero en ese momento en la ejecucion.
			no, entonces enlazado estatico: se mira el tipo de la s.
	*/	

	return 0;
}
