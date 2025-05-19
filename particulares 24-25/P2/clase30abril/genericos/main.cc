#include "Tupla.h"
#include <vector>

int main(){
	vector<Tupla> coordenadas;
	
	coordenadas.push_back(Tupla(3, 1));
	coordenadas.push_back(Tupla(34, 2));
	
	
	for(Tupla t :  coordenadas){
		cout << t.getFirst() << ", " << t.getSecond() << endl;
	}
	
	
	return 0;
}
