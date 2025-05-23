#include "hangar.h"
#include "xwing.h"
#include "tiefighter.h"
#include "imperialship.h"

#include <iostream>
using namespace std;
using namespace P4;

int main(){
	Hangar hangar("mi aznar");
	
	cout << hangar << endl;
	
	hangar.add(new XWing('b', 200));
	hangar.add(new TIEFighter('f', 300));
	hangar.add(new TIEFighter('x', 300));
	
	cout << "===" << endl;
	cout << hangar << endl;
	
	return 0;
}

