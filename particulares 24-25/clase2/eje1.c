#include <stdio.h>

int main(){
	float lado, area, perimetro;
	
	printf("lado: ");
	scanf("%f", &lado);
	
	area = lado * lado;
	perimetro = 4 * lado;
	
	printf("El area es %f\n", area);
	printf("El perimetro es %f\n", perimetro);
	
	return 0;
}
