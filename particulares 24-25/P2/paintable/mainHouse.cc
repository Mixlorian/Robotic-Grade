#include "house.h"
#include <iostream>
using namespace std;
using namespace C4;

int main(){
	Paintable *p = new House();
	
	p->paint("red love");
	
	delete p;
	
	return 0;
}
