
////////////////
// vertexSize //
////////////////

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <string>

const char sep = ' ';

int main(int argc, char *argv[]){
	GraphPtr g = graphCreate (5);

	graphInsert (g, 0, 1, 2);
	graphInsert (g, 0, 2, 5);
	graphInsert (g, 0, 4, 7);
	graphInsert (g, 1, 3, 1);
	graphInsert (g, 1, 4, 2);

	graphInsert (g, 3, 2, 1);
	graphInsert (g, 2, 4, 5);

	auto r1 = graphVertexSize (g) == 5;
	auto r2 = graphEdgeSize(g) == 7;
	
	std::vector<double> v = dijkstra(g, 0); 
	showVector(v);

	auto r3 = 	v[0] == 0 &&
				v[1] == 2 &&
				v[2] == 4 &&
				v[3] == 3 &&
				v[4] == 4;


	graphDestroy (g);

	//std::cout << "bl: " << bl << "\n";

	return r1&&r2&&r3 ? 0 : 1;
}
