
////////////////
// vertexSize //
////////////////

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <string>

const char sep = ' ';

int main(int argc, char *argv[]){
	GraphPtr g = graphCreate (8, GraphType::NOTDIRECTED);

	graphInsert (g, 2, 3);
	graphInsert (g, 3, 4);
	graphInsert (g, 4, 2);
	graphInsert (g, 3, 7);
	graphInsert (g, 3, 2); // esta no cuenta en dirigido

	auto r1 = graphVertexSize (g) == 8;
	auto r2 = graphEdgeSize(g) == 4;

	graphDestroy (g);

	//std::cout << "bl: " << bl << "\n";

	return r1&&r2 ? 0 : 1;
}
