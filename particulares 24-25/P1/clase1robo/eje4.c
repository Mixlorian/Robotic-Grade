#include <stdio.h>
#include <math.h>

int main(){
	// programa que calcula el area de un circulo de radio 4.5
	
	float radio, area, perimetro;
	
	// radio = 4.5;
	printf("Introduce el radio: ");
	scanf("%f", &radio);
	
	area = M_PI * radio * radio;	
	perimetro = 2 * M_PI * radio;
	
	printf("El area es %f\n", area);
	printf("El perimetro es %f\n", perimetro);
	
	return 0;
}
