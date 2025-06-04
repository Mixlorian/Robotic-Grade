#include "A.h"

namespace C3{

ostream &operator<<(ostream &os, const A &a){
	
}

A::A(C *c, int i){
	this->c = c;
	this->i = i;
}

A::A(C &c, int i){
	this->c = &c;
	this->i = i;
}

bool A::addB(int x, int y){
	int pos = -1;
	for(int i = 0; i < bs.size() && pos == -1; i++){
		if(bs[i].getX() == x && bs[i].getY() == y){
			pos = i;
		}
	}
	if(pos != -1){
		return false;
	}
	else{
		try{
			B nuevo(x, y);
			bs.push_back(nuevo);
			//bs.push_back(B(x, y));
			//bs.push_back({x, y});
			bspointers.push_back(new B(x, y));
		}
		catch(invalid_argument &e){
			cout << e.what() << endl // imprimo el mensaje asociado a la excepcion
		}
	}
}

bool A::addB(B &b){
	int pos = -1;
	for(int i = 0; i < bs.size() && pos == -1; i++){
		if(bs[i].getX() == b.getX() && bs[i].getY() == b.getY()){
			pos = i;
		}
	}
	if(pos != -1){
		return false;
	}
	else{
		bs.push_back(b); // hace una copia de B y lo guarda en 
		bspointers.push_back(new B(b));	
	}
}


void A::deleteB(int x, int y){
	int pos = -1;
	for(int i = 0; i < bs.size() && pos == -1; i++){
		if(bs[i].getX() == x && bs[i].getY() == y){
			pos = i;
		}
	}
	if(pos != -1){
		bs.erase(bs.begin() + pos);

		// si estoy manejando yo, 		
		delete bspointers[pos];
		bspointers.erase(bspointers.begin() + pos);
	}		
}

A::~A(){
	for(B *p : bspointers){
		delete p;
	}	
}

}


