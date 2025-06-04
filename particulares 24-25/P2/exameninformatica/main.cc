#include "B.h"

using namespace C3;

int main(){
	B *bp = nullptr;
	B b(12, 23);
	cout << b << endl;


	try{
		int x, y;
		cout << "x y?: ";
		cin >> x >> y;
		bp = new B(x, y);
		cout << "Objeto creado: " << *bp << endl;
	}
	catch(invalid_argument &e){
		cout << "Se capturo la excepcion " << e.what() << endl;
	}
	if(bp != nullptr){
		delete bp;
	}
	return 0;
}
