#include <stdio.h>

/*
¿Cuántos puntos de entrega tiene asignados el robot? -3
¿Cuántos puntos de entrega tiene asignados el robot? -1
¿Cuántos puntos de entrega tiene asignados el robot? 4
-- Punto 1 --
¿Cuántos paquetes entregar en este punto? 2 
-- Punto 2 --
¿Cuántos paquetes entregar en este punto? 1 
-- Punto 3 --
¿Cuántos paquetes entregar en este punto? 10
-- Punto 4 --
¿Cuántos paquetes entregar en este punto? 3

*/

int main(){
	int puntos, i, paquetes, j;
	
	do{
		printf("¿Cuántos puntos de entrega tiene asignados el robot?");
		scanf("%d", &puntos);
	}while(puntos <= 0);
	
	for(i = 1; i <= puntos; i++){
		printf("-- Punto %d --\n", i);
		printf("Cuantos paquetes hay que entregar at this point?: ");
		scanf("%d", &paquetes);
		// imprimir entrengado paquetes tantas veces como paquetes valga
		for(j = 1; j <= paquetes; j++){
			/*if((j - 1) % 3 == 0){
				printf("Verificando bateria\n");
			}*/
			printf("Entrengado paquete...\n");
			if(j % 3 == 0 && j != paquetes){
				printf("Verificando bateria\n");
			}
		}
	}

	return 0;
}
