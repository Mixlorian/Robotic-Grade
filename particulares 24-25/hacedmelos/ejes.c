#include <stdio.h>
#include <string.h>
#define KTAM 50
#define KCADENAS 10
#define KCONTADORES 5

typedef char TCadena [KTAM];
typedef TCadena TListaCadenas [KCADENAS];

typedef int TContadores [KCONTADORES];

// Eje 2. 	contadores[0] => la cantidad de a o A
//		contadores[1] => la cantidad de e o E
// 		...
void contarVocales(TCadena lista, TContadores contadores){

}

//             x    x
// Eje 3. 0123456789012345 
// org = "pepe es el mejor"
// c = 5
// token "perro"

// dst <= "pepe perroes elperro mejperroor"
void codificar(TCadena org, TCadena dst, int c, TCadena token){

}

int main(){
	TListaCadenas lista; // vector de 10 cadenas.
	int n;
	TCadena leida;
	
	
	// Eje 1. Modifica el bucle for, para que las cadenas cuya longitud
	// no este entre 5 y 20, no se almacenen en el vector.
	do{
		printf("Cuantas cadenas quieres rellenar?: ");
		scanf("%d", &n);
	}while(n < 0 || n > KCADENAS);
	for(int i = 0; i <  n; i++){
		printf("Introduce la cadena %d: ", i);
		scanf(" %[^\n]", leida);
		strcpy(lista[i], leida);
	}

