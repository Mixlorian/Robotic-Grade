#include <iostream>
#include "mutablegene.h"
using namespace std;

namespace C3{

MutableGene::MutableGene(char c):Gene(c){
	
}

MutableGene::MutableGene(const MutableGene& g):Gene(g){
	
}

void MutableGene::mutate_data(float mr){
	int aleatorio = rand() % 101; // 0 y 100
		
	if(aleatorio <= mr * 100){
		set_random_data();
	}
}


}


