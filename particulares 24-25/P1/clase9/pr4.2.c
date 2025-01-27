#include <stdio.h>


typedef enum {NORTE, SUR, ESTE, OESTE} Direccion;

Direccion leerDireccion(int n){
	Direccion leida;
	
	// faltaria filtrar
	printf("Introduce direccion de movimiento del robot %d: ", n);
	scanf("%u", &leida);
	
	return leida;
}


void leerDireccion(Direccion *leida, int n){
	printf("Introduce direccion de movimiento del robot %d: ", n);
	scanf("%u", leida);	
}


void leerRobot(int *ppx, int *ppy, int *u, Direccion *d, int n){
	// esta nos se validan
	
	
	
	// cogiendo el valor devuelto
	*d = leerDireccion(n);
	
	// leerDireccion(d, n);
	
} 

int main(){
	int px1, py1, unidades1;
	Direccion d1;
	
	int px2, py2, unidades2;
	Direccion d2;

	leerRobot(&px1, &py1, &unidades1, &d1, 1);
	leerRobot(&px2, &py2, &unidades2, &d2, 2);

	
	return 0;
}
