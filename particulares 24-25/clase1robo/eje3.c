#include <stdio.h>


int main(){
	int base, altura;
	int area, perimetro;
	
	
	// base = 12;
	// altura = 3;
	
	printf("Introduce la base: ");
	scanf("%d", &base);
	printf("Introduce la altura: ");
	scanf("%d", &altura);
	
	
	area = base * altura;
	perimetro = 2 * (base + altura);
	
	// arimetica
	// 1. * / %
	// 2. + -
	printf("El area es %d\n", area);
	printf("El perimetro es %d\n", perimetro);
	
	return 0;
}
