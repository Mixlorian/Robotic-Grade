#include "p1.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
	int m[5][3] = {
		{1, 2, 3},
		{5, 6, 7},
		{9, 10, 11},
		{9, 10, 11},
		{5, 6, 7},
	};
	TMatrix mi;

	for(int i = 0; i < 5; i++){
		std::vector<int> fila;
		for(int j = 0; j < 3; j++){
			fila.push_back(m[i][j]);
		}
		mi.push_back(fila);
	}
	
	auto sumas = diagonal(mi);

	for(auto fila : mi){
		for(auto e : fila){
			std::cout.width(4);
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	cout << endl << std::endl;

	for(auto elemento : sumas){
		cout << elemento << " ";
	}
	cout << endl;
	
	
}
