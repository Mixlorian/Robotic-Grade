#include <stdio.h>
#define KPIEZAS 3
typedef 
typedef int TEnsambladas [KPIEZAS];

typedef enum {tornillo = 0, clavo, tuerca} TPieza;


char preguntar(){
	char r;
	do{
		printf("Quieres ensamblar otra pieza (s/n)?: ");
		scanf(" %c", &r);	
	}while(r  != 's' && r != 'n');	
	return r;
}

TPieza leerPieza(){
	int tipo;
	do{
		printf("Introduce el tipo de pieza (0-Tornillo, 1-Clavo, 2-Tuerca):");
		scanf("%d", &tipo);
	}while(tipo != tornillo && tipo != clavo && tipo != tuerca);	
	return tipo;
}

// muestra la herramienta correspondiente a la pieza p,
// e incrementa la posicion del vector correspondiente
// modificar la carga, // restarle 10 a asterisco carga
// almacenar en el vector de hc, la carga despues de ensamblar!!!


void mostrarHerramienta(TPieza p, TEnsambladas ensam, int *carga, int hc[], int *piezasEnsambladas){

}

int main(){
	TEnsambladas ensam = {0, 0, 0};
	int historialCarga[MAX_ENSAMBLAJES];
	int piezas = 0;
	
	
	
	return 0;
}

