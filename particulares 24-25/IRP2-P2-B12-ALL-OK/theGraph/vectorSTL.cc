#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main(){
	// vectores dinamicos que inicialmente estan vacios.
	vector<int> enteros;	// vector de enteros
	vector<float> reales;	// vector de reales

	cout << enteros.size() << endl;
	cout << reales.size() << endl;
	
	enteros.push_back(12);	// añade un elemento al final y copia el 12
	enteros.push_back(15);  // añade un elemento al final y copia el 15
	enteros.push_back(35);  // añade un elemento al final y copia el 35

	cout << enteros.size() << endl;

	for(int i = 0; i < enteros.size(); i++){
		cout << enteros[i] << " ";
	}
	cout << endl;


	queue<int> cola;
	int elemento;

	cout << cola.empty() << endl; // true (1) si vacia, false (0) si no vacia

	cola.push(12);
	cola.push(34);
	cola.push(54);
	cola.push(45);
	cola.push(65); // 12 <= 34 <= 54 <= 45 <= 65
	
	cout << "desncolando..." << endl;
	while(cola.empty() == false){
		elemento = cola.front(); // devuelve el primero (no lo quita)
		cout << "en la cabeza: " << elemento << endl;
		cola.pop(); // quita el elemento de la cabeza
	}
		
	return 0;
}
