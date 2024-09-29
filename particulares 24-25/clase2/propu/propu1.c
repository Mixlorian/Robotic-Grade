#include <stdio.h>

int main(){
	int lado;
	int area, perimetro;
	
	printf("Introduce el lado de un cuadrado: ");
	scanf("%d", &lado);
	if (lado < 0){
		printf("error el lado no puede ser negativo");
	}else{
		area = lado * lado;
		perimetro = 4 * lado;
	
		printf("El area es %d\n", area);
		printf("El perimetro es %d\n", perimetro);
	}
	return 0;
}
