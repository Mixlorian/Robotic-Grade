#include <stdio.h>
#include <math.h>


int main(){
	float radio, altura, volumen;
	
	printf("Introduce el radio de la base: ");
	scanf("%f", &radio);
	if (radio < 0){
		printf("error");
	}else{
        printf("Introduce la altura: ");
	    scanf("%f", &altura);
        if(altura < 0){
            printf("error");
        }else{
            volumen = M_PI * pow(radio, 2) * altura; 
	        printf("el volumen es %f\n", volumen);
        }
    }
	return 0;
}