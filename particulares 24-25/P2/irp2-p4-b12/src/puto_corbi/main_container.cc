#include "container.h"
#include "xwing.h"
#include "tiefighter.h"
#include "imperialship.h"

using namespace std;

int main(){
	P4::Container<int> enteros;
	
	enteros.add(42);
	enteros.add(12);
	
	cout << enteros << endl;
	
	
	cout << enteros.find(31) << endl;
	cout << enteros.find(12) << endl;
	
	
	P4::Container<P4::ShipPtr> chipis;
	
	P4::XWing xwing('x', 200);
	
	chipis.add(new P4::XWing('x', 200));
	chipis.add(new P4::TIEFighter('f', 300));
	
	cout << chipis << endl;
	
	vector<int> mis_enteros;
	vector<int *> mis_punteros;
	
	
	mis_enteros.push_back(12);
	mis_enteros.push_back(34);
	mis_enteros.push_back(43);
	
	mis_punteros.push_back(new int (34));
	int un_entero = 12;
	mis_punteros.push_back(&un_entero);

	
	return 0;
}
