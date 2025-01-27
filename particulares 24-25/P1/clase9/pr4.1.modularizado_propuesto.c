#include <stdio.h>
#include <math.h>

void printCoord(int x, int y, int n){

}

void swap(int *a, int *b){
}
void intercambiar(int *x1, int *y1, int *x2, int *y2){
}


// int v;
// leerCoordenada(&v, 'z');
void leerCoordenada(int *valor, char c){

}


void leerCoordenadas(int *px, int *py, int n){
}


int main(){
	int x1, y1, x2, y2, aux;
	float d;
	leerCoordenadas(&x1, &y1, 1);
	leerCoordenadas(&x2, &y2, 2);
	printf("Intercambiando coordenadas...\n");
	intercambiar(&x1, &y1, &x2, &y2);
	printf("Coordenadas despues del intercambio: \n");
	printCoord(x1, y1, 1);
	printCoord(x2, y2, 2);
	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	printf("Distancia entre los puntos: %.2f\n", d);
	return 0;
}

