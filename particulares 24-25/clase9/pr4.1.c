#include <stdio.h>
#include <math.h>

int main(){
	int x1, y1, x2, y2, aux;
	float d;
	
	printf("Introduce las coordenadas del primer punto (x1 y1): ");
	scanf("%d %d", &x1, &y1);
	if(x1 < 0 || x1 > 99 || y1 < 0 || y1 > 99){
		printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
		do{
			printf("Introduce una coordenada x entre 0 y 99: ");
			scanf("%d", &x1);
			if(x1 < 0 || x1 > 99){
				printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
			}
		}while(x1 < 0 || x1 > 99);
		do{
			printf("Introduce una coordenada y entre 0 y 99: ");
			scanf("%d", &y1);	
			if(y1 < 0 || y1 > 99){
				printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
			}
		}while(y1 < 0 || y1 > 99);			
	}

	printf("Introduce las coordenadas del segundo punto (x1 y1): ");
	scanf("%d %d", &x2, &y2);
	if(x2 < 0 || x2 > 99 || y2 < 0 || y2 > 99){
		printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
		do{
			printf("Introduce una coordenada x entre 0 y 99: ");
			scanf("%d", &x2);
			if(x2 < 0 || x2 > 99){
				printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
			}
		}while(x2 < 0 || x2 > 99);
		do{
			printf("Introduce una coordenada y entre 0 y 99: ");
			scanf("%d", &y2);	
			if(y2 < 0 || y2 > 99){
				printf("Coordenada fuera de rango. Debe estar entre 0 y 99\n");
			}
		}while(y2 < 0 || y2 > 99);			
	}

	printf("Intercambiando coordenadas...\n");
	aux = x1;
	x1 = x2;
	x2 = aux;
	
	aux = y1;
	y1 = y2;
	y2 = aux;
	
	printf("Coordenadas despues del intercambio: \n");
	printf("Punto 1: (%d, %d)\n", x1, y1);
	printf("Punto 2: (%d, %d)\n", x2, y2);
	
	
	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	printf("Distancia entre los puntos: %.2f\n", d);


	return 0;
}
