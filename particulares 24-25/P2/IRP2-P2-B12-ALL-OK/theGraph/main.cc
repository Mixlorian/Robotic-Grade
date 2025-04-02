#include <vector>
#include "graph.h"
using namespace std;

const char sep = ' ';

int main(int argc, char *argv[]){
	GraphPtr g = graphCreate(5);

	cout << NOEDGE << endl;

	graphInsert(g, 0, 1, 2);
	graphInsert(g, 0, 2, 5);
	graphInsert(g, 0, 4, 7);

	graphInsert(g, 1, 3, 1);
	graphInsert(g, 1, 4, 2);

	graphInsert(g, 2, 4, 5);

	graphInsert(g, 3, 2, 1);

	cout << "Numero de vertices: " << graphVertexSize(g) << endl;
	cout << "Numero de aristas: " << graphEdgeSize(g) << endl;

	vector<weight_t> sol = dijkstra(g, 0);

	for(weight_t peso : sol){
		cout << peso << " ";
	}
	cout << endl;
	graphDestroy (g);

	return 0;
}
