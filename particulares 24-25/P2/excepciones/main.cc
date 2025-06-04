#include "C.h"
#include "B.h"
#include <iostream>
#include <exception>
using namespace std;

int main(){
	int x, y;
	B *b = nullptr;
	try{
		cout << "x y?: ";
		cin >> x;
		cin >> y;
		b = new B(x, y);
		cout << "Creado shit" << endl;
		if(x == 20){
			throw 3;
		}
		if(x == 21){
			throw "const char *";
		}
		if(x == 22){
			string s = "hola";
			throw s;
		}
	}
	catch(invalid_argument &i){
		cout << "Invalid: " << i.what() << endl;
	}
	catch(exception &e){
		// capturo el resto de exceptions		
		cout << "El resto: " << e.what() << endl;
	}
	catch(const char *e){
		cout << "cadenita lanzada: " << e << endl;
	}
	catch(int &e){
		cout << "entero capturado" << endl;
	}
	catch(...){
		cout << "no quedan mas" << endl;
	}
	return 0;
}
