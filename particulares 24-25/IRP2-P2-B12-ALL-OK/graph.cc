#include "graph.h"

GraphPtr graphCreate(uint64_t nv, GraphType directed){
	GraphPtr g = new Graph;
	g->nv = nv;
	g->ne = 0;
	g->gt = directed;
	
	g->v = new weightRow_t [g->nv];
	for(int i = 0; i < g->nv; i++){
		g->v[i] = new weight_t [g->nv];
		for(int j = 0; j < g->nv; j++){
			g->v[i][j] = NOEDGE;
		}
	}
	return g;
}

void graphDestroy(GraphPtr g){
	if(g){
		graphMakeNull(g);
		delete g;	
	}
}

void graphMakeNull(GraphPtr g){
	if(g->nv != 0){
		for(int i = 0; i < g->nv; i++){
			delete [] g->v[i];
		}
		delete [] g->v;
		g->v = nullptr;
		g->nv = 0;
	}

}

size_t graphVertexSize(GraphPtr g){
	size_t tam = 0;
	if(g){
		tam = g->nv;
	}
	return tam;
}

size_t graphEdgeSize(GraphPtr g){
	size_t ne = 0;
	if(g){
		ne = g->ne;
	}
	return ne;
}


bool graphInsert(GraphPtr g, size_t o, size_t e, weight_t w){
	bool inserted = false;
	if(g){
		if(o >= 0 && o < g->nv && e >= 0 && e < g->nv){
			g->v[o][e] = w;
			if(g->gt == GraphType::NOTDIRECTED){
				g->v[e][o] = w;
			}
			inserted = true;
			g->ne = 0;
			for(int i = 0; i < g->nv; i++){
				for(int j = 0; j < g->nv; j++){
					if(g->v[i][j] != NOEDGE){
						g->ne++;
					}
				}
			}
		}
	}
	return inserted;
}

std::vector<weight_t> dijkstra(GraphPtr g, size_t i){
		std::vector<weight_t> D(g->nv, NOEDGE);
		size_t actual, numVisitados;
		vector<bool> visitados(g->nv, false);
		double menor = numeric_limits<double>::max();
		
		numVisitados = 0;
		D[i] = 0;
		while(numVisitados != g->nv){
			/*actual = -1;
			for(int k = 0; k < g->nv; k++){
				if(!visitados[k]){
					if(actual == -1 || D[k] < D[actual]){
							actual = k;
						}
					}
				}
			}*/
			menor = numeric_limits<double>::max(); // menor = +inf
			actual = -1;
			for(int k = 0; k < g->nv; k++){
				if(!visitados[k] && D[k] < menor){
					actual = k;
					menor = D[k];
				}
			}
			visitados[actual] = true;
			for(int k = 0; k < g->nv; k++){
				if(!visitado[k]){
					if(g->v[actual][k] != NOEDGE){
						if(g->v[actual][k] + D[actual] < D[k]){
							D[k] = g->v[actual][k] + D[actual];
						}
					}		
				}
			}
		}
		
		return D;
}












