/// evita la doble inclusion del fichero cabecera
#ifndef _terry_heart_breaker_
#define _terry_heart_breaker_
#include <iostream>
#include "B.h"
#include "C.h"
using namespace std;

namespace C3{

class A{
	friend ostream &operator<<(ostream &os, const A &a);
	private:
		int i;
		// Agregacion
		// 	- Apunto a un objeto que ya existe (inclusion por ref.)
		C *c;	
		// Composicion
		//	- Creo objetos nuevos con los que me pasan como
		//     parametro.
		vector<B> bs;
		vector<B *> bspointers;
	public:
		A(CPtr c, int i = 0);
		A(C &c, int i = 0);
		~A();
		
		// inclusion por valor (composicion)
		bool addB(int x, int y);
		bool addB(B &b);
		void deleteB(int x, int y);
};

}


#endif
