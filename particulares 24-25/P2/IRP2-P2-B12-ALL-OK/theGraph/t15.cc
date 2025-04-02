
////////////////
// vertexSize //
////////////////

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <string>

const char sep = ' ';

int main(int argc, char *argv[]){
	GraphPtr g = graphCreate (5, GraphType::NOTDIRECTED);

	graphInsert (g, 0, 1, 3);
	graphInsert (g, 0, 3, 5);
	graphInsert (g, 0, 4, 1);
	graphInsert (g, 1, 3, 2);
	graphInsert (g, 2, 3, 4);

	graphInsert (g, 2, 4, 2);
	graphInsert (g, 3, 4, 3);

	auto r1 = graphVertexSize (g) == 5;
	auto r2 = graphEdgeSize(g) == 7;
	
	std::vector<Edge> v = prim(g, 0); 
	showVector(v);
	
	// aristas del resultado.
	int m[4][2] = {{0, 4}, {4, 2}, {0, 1}, {1, 3}};

	// comprobamos si las aristas coinciden con el resultado.
	auto r3 = true;
	for(int i = 0; i < v.size(); i++){
		r3 = r3 && m[i][0] == v[i].o && m[i][1] == v[i].e;
	}
	

	graphDestroy (g);

	//std::cout << "bl: " << bl << "\n";

	return r1&&r2 ? 0 : 1;
}
