
////////////////
// vertexSize //
////////////////

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <string>

const char sep = ' ';

int main(int argc, char *argv[]){
	GraphPtr g = graphCreate (6, GraphType::NOTDIRECTED);

	graphInsert (g, 0, 2, 7);
	graphInsert (g, 0, 3, 5);
	graphInsert (g, 0, 5, 4);
	graphInsert (g, 1, 4, 5);
	graphInsert (g, 1, 5, 11);

	graphInsert (g, 2, 3, 5);
	graphInsert (g, 3, 4, 3);
	graphInsert (g, 4, 5, 2);

	auto r1 = graphVertexSize (g) == 6;
	auto r2 = graphEdgeSize(g) == 8;
	
	std::vector<double> v = dijkstra(g, 4); 
	showVector(v);

	auto r3 = 	v[0] == 6 &&
				v[1] == 5 &&
				v[2] == 8 &&
				v[3] == 3 &&
				v[4] == 0 &&
				v[5] == 2;


	graphDestroy (g);

	//std::cout << "bl: " << bl << "\n";

	return r1&&r2&&r3 ? 0 : 1;
}
