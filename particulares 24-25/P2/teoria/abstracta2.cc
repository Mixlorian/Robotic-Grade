#include <iostream>
using namespace std;


// no queremos crear instancias de esta clase. que hacemos?
// el elegido al azaaar un metodo de losque tienen implementacion
// y lo he definido como abstracto => problema: se me puede olvidar
// implementarlo. 

// La forma correcta de proceder es declarar el destrcutror virtual puro
// porque es el unico metodo en c++ que tiene implementacion obligatoria!!
// porque el destructor de la derivada llama siempre al de la base.

class Conectable{
	private:
		string ip;
	public:
		Conectable(string ip);
		virtual ~Conectable() = 0;
		string getIp() const;
};

// EN ESTE EJEMPLO NO COMPILA Y C++ ME AVISA DE QUE TENGO QUE PONERLE
// CUERPO ... TENDRIA QUE IMPLEMENTAR EL DESTRUCTOR Y DEJARLO VACIO..
/*
Conectable::~Conectable(){
}
*/

class Movil : public Conectable {
	public:
		Movil(string ip);
};


Conectable::Conectable(string ip){
	this->ip = ip;
}

string Conectable::getIp() const{
	return ip;
}

Movil::Movil(string ip):Conectable(ip){
}


int main(){
	Conectable *c = new Movil("123.12.12.12");
	
	return 0;
}



