#include <stdio.h>
#define KBASE 82
#define KDESCUENTO_1 .25
#define KDESCUENTO_2 .1
#define KDESCUENTO_3 .05

int main(){
	float aux;
	float carga1, carga2, carga3; // [1..6]
	float precio = KBASE;
	
	printf("Introduce los destinos de las 3 cargas [1..6]: ");
	scanf("%f %f %f", &carga1, &carga2, &carga3);
	if(carga1 == carga2 && carga2 == carga3){
		precio *= 3 * (1 - KDESCUENTO_1);
	}
	else{
		if(carga1 == carga2 || carga2 == carga3 || carga1 == carga3){
			precio = 2 * (KBASE - KBASE * KDESCUENTO_2) + KBASE;
		}
		else{
			if(carga3 < carga2){
				aux = carga3;
				carga3 = carga2;
				carga2 = aux;
			}
			if(carga2 < carga1){
				aux = carga2;
				carga2 = carga1;
				carga1 = aux;
			}
			if(carga3 < carga2){
				aux = carga3;
				carga3 = carga2;
				carga2 = aux;
			}
			if(carga3 == carga2 + 1 && carga2 == carga1 + 1){
				precio = 3 * KBASE  * (1 - KDESCUENTO_3);
			}
			else{
				precio = 3 * KBASE;
			}
		}
	}
	printf("El precio del transporte es %.2f\n", precio);
	return 0;
}

