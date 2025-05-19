#include "TuplaT.cc" // En templates y compilacion separada
// se incluye el .cc (que ya esta todo implementado)



class Libro{
	private: 
		string titulo;
	public:
		Libro(){}
		Libro(string t):titulo(t){}
		// C++ no cancelara nunca el constructor copia de oficio
		// que hace shallow copy (copia superficial, copia bit a bit)
		// a no ser que definamos uno de forma explicita.
		string getTitulo() const{ return titulo; }
		bool operator==(const Libro &de) const{
			return titulo == de.titulo;
		}
};



int main(){
	int x, y(12);
	// C++ rescribe la clase cambiando el tipo T por el tipo que
	// has indicado.
	TuplaT<int> enteros, enteros2(3, 4); // T = int
	TuplaT<float> reales, reales2(4.4, 2.3); // T = float
	TuplaT<char> caracteres('A', 'R');
	
	cout << enteros2.getFirst() << ", " << enteros2.getSecond() << endl;
	cout << caracteres.getFirst() << ", " << caracteres.getSecond() << endl;


	TuplaT<Libro> parDeLibros;
	TuplaT<Libro> otroPar(Libro("hola"), Libro("gramola"));
	
	
	if(otroPar == parDeLibros){
		// otroPar.first == parDeLibros.first
		// Libro == Libro
		cout << "pares de libros iguales" << endl;
	}


	return 0;	
}
