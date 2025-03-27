#include <iostream>
#include "graph.h"
#include <vector>
using namespace std;

int main(){
	GraphPtr g = graphCreate(5);
	
	graphInsert(g, 0, 1, 1);
	graphInsert(g, 1, 2, 1);
	graphInsert(g, 0, 2, 3);
	graphInsert(g, 3, 1, 3);
	graphInsert(g, 3, 2, 6);
	graphInsert(g, 4, 3, 4);
	
	vector<weight_t> pesos;

	for(int i = 0; i <= 4; i++){
		pesos = dijkstra(g, i);
		cout << "Desde " << i << ": ";
		for(int j = 0; j < pesos.size(); j++){
			cout << pesos[j] << " ";
		}
		cout << endl;
	}


	return 0;
}
