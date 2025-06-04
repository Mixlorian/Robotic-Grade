#include <iostream>
using namespace std;
/*
En C++:
	- Una clase es abstracta si contiene al menos un metodo abstracto.
	- Un metodo abstracto es un metodo definido como virtual puro, no 
	tiene implementacion y si la tiene es una implementacion parcial
	del metodo, no es la implementacion final.
	- De las clases Abstractas no podemos crear instancias, tan solo
	punteros y referencias que apuntaran o objetos derivados.
	- Cuando vamos a usar una clase abstracta? cuando es resultado
	de una factorización, recoge el comportamiento comun, pero sabes
	lo que hace pero no como lo hace, el como se espeficia en las derivadas.
*/
// ESTA CLASE ES ABSTRACTA PORQUE CONTIENE METODOS VIRTUALES PUROS (ABSTRACTOS)
class Figura{
	public:
		// Metodos virtuales que no tienen implementacion.
		virtual double getArea() const = 0;
		virtual double getPerimetro() const = 0;
};
// ESTA CLASE YA NO ES ABSTRACTA PORQUE HA SOBRESCRITO (INDICANDO UN COMPORT.)
// PARA ESOS METODOS VIRTUALES PUROS HEREDADOS.
class Rectangulo : public Figura{
	private:
		double base, altura;
	public:
		Rectangulo(double b = 1, double a = 1);
		// los estamos sobrescribiendo, les vamos a indicar
		// implementacion.
		double getArea() const;
		double getPerimetro() const;
		double getBase() const;
		double getAltura() const;		
};
Rectangulo::Rectangulo(double b, double a){
	base = b;
	altura = a;
}
double Rectangulo::getArea() const{
	return base * altura;
}
double Rectangulo::getPerimetro() const{
	return 2 * (base + altura);
}
double Rectangulo::getBase() const{
	return base;
}
double Rectangulo::getAltura() const{
	return altura;
}

class Circulo : public Figura{
	private:
		double radio;
	public:
		Circulo(double r);
		double getArea() const;
		double getPerimetro() const;
		double getRadio() const;
};
#include <cmath>
Circulo::Circulo(double r){
	radio = r;
}
double Circulo::getArea() const{
	return M_PI * pow(radio, 2);
}
double Circulo::getPerimetro() const{
	return 2 * M_PI * radio;
}
double Circulo::getRadio() const{
	return radio;
}
#include <vector>
int main(){
	// Figura f; ERROR estamos intentando crear un objeto de tipo figura
	vector<Figura *> figuras;
	
	figuras.push_back(new Rectangulo());
	figuras.push_back(new Circulo(12));
	// figuras.push_back(new Figura()); // figura es abstracta
	figuras.push_back(new Rectangulo(33, 2));
	
	for(Figura *f : figuras){
		cout << "Area: " << f->getArea() << endl;
		cout << "Perimetro: " << f->getPerimetro() << endl;
		// como imprimimos base altura o radio para cada figura??
		Circulo *c = dynamic_cast<Circulo *>(f);
		if(c){
			cout << "Radio: " << c->getRadio() << endl;
		}
		Rectangulo *r = dynamic_cast<Rectangulo *>(f);
		if(r){
			cout << "base: " << r->getBase()
			<< ", altura: " << r->getAltura() << endl;
		}
	}
	
	return 0;
}







