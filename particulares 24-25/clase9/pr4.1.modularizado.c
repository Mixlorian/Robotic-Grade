#include <stdio.h>
#include <math.h>

void printCoord(int x, int y, int n){
	printf("Punto %d: (%d, %d)\n", n, x, y);

}

void swap(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
void intercambiar(int *x1, int *y1, int *x2, int *y2){
	swap(x1, x2);
	swap(y1, y2);
}

// int v;
// leerCoordenada(&v, 'z');

void leerCoordenada(int *valor, char c){
	do{
		printf("Introduce una coordenada %c entre 0 y 99: ",c);
		scanf("%d", valor);
		if(*valor < 0 || *valor > 99){
			printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
		}
	}while(*valor < 0 || *valor > 99);

}


void leerCoordenadas(int *px, int *py, int n){
	
	if(n == 1){
		printf("Introduce las coordenadas del primer punto (x1 y1): ");
	}
	else{
		printf("Introduce las coordenadas del segundo punto (x2 y2): ");	
	}
	scanf("%d %d", px, py); 	// scanf("%d %d", &x1, &y1); <= leerCoordenadas(&x1, &y1, 1);
					// scanf("%d %d", &x2, &y2); <= leerCoordenadas(&x2, &y2, 2);
	
	if(*px < 0 || *px > 99 || *py < 0 || *py > 99){ // accedemos al contenido de la direccion de memoria almacenada en x
		printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
		leerCoordenada(px, 'x');
		leerCoordenada(py, 'y');
	}
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

