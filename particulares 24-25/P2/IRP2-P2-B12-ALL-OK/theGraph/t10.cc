
////////////////
// vertexSize //
////////////////

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <string>

const char sep = ' ';

int main(int argc, char *argv[]){
	GraphPtr g = graphCreate(3);

	auto r1 = graphVertexSize (g) == 3;
	auto r2 = graphEdgeSize(g) == 0;
	auto r3 = g->gt == GraphType::DIRECTED;
	graphDestroy (g);

	//std::cout << "bl: " << bl << "\n";

	return r1&&r2 ? 0 : 1;
}
