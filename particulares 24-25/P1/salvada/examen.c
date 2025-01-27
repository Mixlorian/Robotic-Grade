#include <stdio.h>
#include <stdlib.h>

// El nombre del fichero con los productos se recibe por linea de comandos.
/*
La estructura del fichero es:

3
pipas negras	(maximo 50 caracteres)
12.5
aceitunas azules
2.78
garbanzos molidos
2.31
*/
// despues de leer el fichero con los productos
// el usuario meterá:
// 0 2
// 1 3
// -1
// y mostraremos el total de la compra: 2 * 12.5 + 3 * 2. 78

#include <stdio.h>
#include <stdlib.h>
#define KNOMBRE 50
typedef char TCadena [KNOMBRE + 1];
typedef struct{
	TCadena nombre;
	float precio;
}TProducto;
int main(int argc, char *argv[]){
	TProducto *productos = NULL;
	int np = 0;
	FILE *f;
	int unidades, producto;
	float total;
	
	if(argc == 2){
		f = fopen(argv[1], "r");
		if(f != NULL){
			fscanf(f, "%d", &np);	// leo la cantidad de productos
			productos = (TProducto *) malloc(sizeof(TProducto) * np); // reservo memoria para almacenar np productos
			for(int i = 0; i < np; i++){
				fscanf(f, "%[^\n]", productos[i].nombre);
				fscanf(f, "%f", &productos[i].precio);
			}
			fclose(f);
			total = 0;
			do{
				scanf("%d", &producto); // esto es el numero de producto :)
				if(producto != -1){
					scanf("%d", &unidades);
					total += unidades * productos[producto].precio;
				}
			}while(producto != -1);
			printf("El total de tu compra asciende a %.2f\n", total);
		}
	}
	return 0;
}


