#include "sensor.cc"
#include <iostream>
using namespace std;
using namespace C3;

class A{
	public:
		A(){ cout << "creando un A" << endl; }
		~A(){ cout << "destruyendo A" << endl; }
};

int main(){
	Sensor<A> sensora("sensei");


	return 0;
}
