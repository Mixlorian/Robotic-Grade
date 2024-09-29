#include <stdio.h>
#include <math.h>

int main(){
	float radio, altura, volumen;
	
	printf("Introduce el radio de la base: ");
	scanf("%f", &radio);
	if(radio < 0){
		printf("error en radio\n");
	}
	else{
		printf("Introduce la altura: ");
		scanf("%f", &altura);
		if(altura < 0){
			printf("Error en altura\n");
		}
		else{
			volumen = M_PI * pow(radio, 2) * altura; 
			printf("el volumen es %f\n", volumen);
		}
	}
	
	printf("Introduce el radio de la base: ");
	scanf("%f", &radio);
	if(radio >= 0){
		printf("Introduce la altura: ");
		scanf("%f", &altura);
		if(altura >= 0){
			volumen = M_PI * pow(radio, 2) * altura; 
			printf("el volumen es %f\n", volumen);			
		}
		else{
			printf("ERror en altura\n");
		}
	}	
	else{
		printf("Error en base\n");
	}
	return 0;
}
