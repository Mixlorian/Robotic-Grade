#include <stdio.h>
#include <math.h>

int main(){
	float radio, altura, volumen;
	
	printf("Introduce el radio de la base: ");
	scanf("%f", &radio);
	
	printf("Introduce la altura: ");
	scanf("%f", &altura);
	
/*	
	if(radio < 0 || altura < 0){
		printf("Error\n");
	}
	else{
		volumen = M_PI * pow(radio, 2) * altura; 
		printf("el volumen es %f\n", volumen);
	}
*/
	
	if(radio >= 0 && altura >= 0){
		volumen = M_PI * pow(radio, 2) * altura; 
		printf("el volumen es %f\n", volumen);	
	}
	else{
		printf("\a\"\\error\\\\\"\n");	
	}
	
	return 0;
}
