#include <stdio.h>

int main(){
	float lado, area, perimetro;
	
	printf("lado: ");
	scanf("%f", &lado);
	
	if(lado >= 0){
		area = lado * lado;
		perimetro = 4 * lado;	
		printf("El area es %f\n", area);
		printf("El perimetro es %f\n", perimetro);
	}
	else{
		printf("Error\n");
	}
	
/*	
	if(lado < 0){
		printf("Error\n");
	}
	else{
		area = lado * lado;
		perimetro = 4 * lado;	
		printf("El area es %f\n", area);
		printf("El perimetro es %f\n", perimetro);	
	}
*/
	return 0;
}
