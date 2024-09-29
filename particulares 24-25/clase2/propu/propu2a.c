#include <stdio.h>
#include <math.h>


int main(){
	float radio, altura, volumen;
	
	printf("Introduce el radio de la base: ");
	scanf("%f", &radio);
	printf("Introduce la altura: ");
	scanf("%f", &altura);
	
	if (altura < 0 || radio < 0)
	{
		printf("error en datos");
	}else{
	volumen = M_PI * pow(radio, 2) * altura; 
	printf("el volumen es %f\n", volumen);
	}

	
	return 0;
}