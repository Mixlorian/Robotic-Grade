#include <stdio.h>


int main(){
	int porcentaje, barras, i;
	
	do{
		printf("Introduce el nivel de carga de la bateria (0-100%%): ");
		scanf("%d", &porcentaje);
		if(porcentaje < 0 || porcentaje > 100){
			printf("Por favor, introduce un valor entre 0 y 100\n");
		}	
	}while(porcentaje < 0 || porcentaje > 100);
	
/*
	printf("Introduce el nivel de carga de la bateria (0-100%%): ");
	scanf("%d", &porcentaje);	
	while(porcentaje < 0 || porcentaje > 100){
		printf("Por favor, introduce un valor entre 0 y 100\n");
		printf("Introduce el nivel de carga de la bateria (0-100%%): ");
		scanf("%d", &porcentaje);		
	}
*/	
	printf("Bateria:|");
	barras = porcentaje / 10;
	
	/*i = 1;
	while(i <= barras){
		printf("#");
		i++;
	}*/
	
	for(i = 1; i <= 10; i++){
		if(i <= barras){
			printf("#");
		}
		else{
			printf("-");
		}
	}
/*	
	for(i = 1; i <= barras; i++){
		printf("#");
	}

	for(i = 1; i <= 10 - barras; i++){
		printf("-");
	}
*/	
	printf("|%d%%\n", porcentaje);
	
	return 0;
}


