#include <iostream>
#include "graph.h"

using namespace std;

int main(){
	GraphPtr g = graphCreate(7, GraphType::NOTDIRECTED);
	auto r = true;

	r = r && graphInsert(g, 0, 1, 10);
	r = r && graphInsert(g, 0, 2, 18);
	r = r && graphInsert(g, 1, 2, 6);
	r = r && graphInsert(g, 1, 3, 3);
	r = r && graphInsert(g, 2, 6, 2);	
	r = r && graphInsert(g, 3, 5, 5);
	r = r && graphInsert(g, 4, 5, 10);
	r = r && graphInsert(g, 5, 6, 2);
	 
	
	
	vector<weight_t> w = dijkstra(g, 0);
	weight_t v[] = {0, 10, 16, 13, 28, 18, 18};
	auto r2 = true;

	for(int i = 0; i < w.size(); i++){
		cout << w[i] << " ";
		r2 = r2 && (w[i] == v[i]);
	}
	cout << endl;

	
	auto r3 = true;
	int sol[6][2] = {{1, 0}, {3, 1}, {5, 3}, {6, 5}, {2, 6}, {4, 5}};
	vector<Edge> p = prim(g, 0);

	for(int i = 0; i < p.size(); i++){
		cout << "(" << p[i].e << ", " << p[i].o << ") ";
		r3 = r3 && sol[i][0] == p[i].e && sol[i][1] == p[i].o;	
	}

	cout << endl;
	cout << r << " " << r2 << " " << r3 << endl;	

	return !(r && r2 && r3);
}
