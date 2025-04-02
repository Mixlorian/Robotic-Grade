// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "graph.h"

GraphPtr    graphCreate      (uint64_t nv, GraphType directed){
	GraphPtr g = new Graph;
	
	g->nv = nv;
	g->gt = directed;
	g->ne = 0;
	g->v = new weightRow_t [nv]; 
	for(uint64_t i = 0; i < nv; i++){
		g->v[i] = new weight_t [nv];
		for(uint64_t j = 0; j < nv; j++){
			g->v[i][j] = NOEDGE;
		}
	}	
	return g;
}

void        graphDestroy     (GraphPtr g){
	if(g != nullptr){
		graphMakeNull(g);
		delete g;
	}
}

void        graphMakeNull    (GraphPtr g){
	if(g->v != nullptr){
		for(uint64_t i = 0; i < g->nv; i++){
			delete [] g->v[i];
		}
		delete [] g->v;
		g->nv = 0;
		g->ne = 0;
		g->gt = GraphType::DIRECTED;
	}
}

size_t      graphVertexSize  (GraphPtr g){
	size_t saei = 0;
	if(g != nullptr){
		saei = g->nv;
	}
	return saei;
}

size_t      graphEdgeSize    (GraphPtr g){
	if(g != nullptr){
		return g->ne;
	}
	else{
		return 0;
	}
}

bool        graphInsert      (GraphPtr g, size_t o, size_t e,weight_t w ){
    bool inserted = false;

    if(g != nullptr){
        if(o >= 0 && o < g->nv && e >= 0 && e < g->nv){
            inserted = true;	
            if(g->v[o][e] == NOEDGE){
                g->ne++;
            }			
            g->v[o][e] = w;
            if(g->gt != GraphType::DIRECTED){
                g->v[e][o] = w;
            }
        }
    }
    return inserted;
}

std::vector<weight_t> dijkstra (GraphPtr g, size_t i){
	std::vector<weight_t> sol;
	weight_t *D;
	bool *visitados;
	weight_t menorPeso;
	int menorVertice;

	visitados = new bool [g->nv];
	for(int k = 0; k < g->nv; k++){
		visitados[k] = false;
	}
	visitados[i] = true;
	
	D = new weight_t [g->nv];
	for(int k = 0; k < g->nv; k++){
		D[k] = g->v[i][k];
	}
	D[i] = 0;
	bool seguir = true;
	while(seguir){
		for(int k = 0; k < g->nv; k++){
			std::cout << D[k] << " ";
		}		
		std::cout << std::endl;
		menorVertice = -1;
		menorPeso = EDGEINFINITY;					
		for(int k = 0; k < g->nv; k++){
			if(visitados[k] == false){
				if(D[k] < menorPeso){
					menorPeso = D[k];
					menorVertice = k;
				}
			}		
		}
		std::cout << "seleccionado: " << menorVertice << std::endl;
		
		if(menorPeso == EDGEINFINITY){
			seguir = false;
		}
		else{
			visitados[menorVertice] = true;
			for(int k = 0; k < g->nv; k++){
				if(!visitados[k]){
					if(g->v[menorVertice][k] != EDGEINFINITY){
						D[k] = std::min(D[k], D[menorVertice] + g->v[menorVertice][k]);
					}
				}
			}
		}
	}
	for(int k = 0; k < g->nv; k++){
		sol.push_back(D[k]);
	}
	delete [] D;
	delete [] visitados;
	return sol;
}

std::vector<Edge> prim(GraphPtr g, size_t i){
	std::vector<Edge> edges;
	std::vector<bool> visitados(g->nv, false);
	int k, p, q;
	Edge menor;
	weight_t menor_peso;
	
	visitados[i] = true;
	for(k = 1; k <= g->nv - 1; k++){
		menor_peso = EDGEINFINITY;		
		for(p = 0; p < g->nv; p++){
			if(visitados[p]){
				for(q = 0; q < g->nv; q++){
					if(!visitados[q]){
						if(g->v[p][q] < menor_peso){
							menor_peso = g->v[p][q];
							menor.o = p;
							menor.e = q;
						}
					}
				}
			}
		}
		visitados[menor.e] = true;
		edges.push_back(menor);
	}

	return edges;
}