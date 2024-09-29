#include <stdio.h>

/*
	Realizar un programa que reciba dos vertices de un rectangulo opuestos
	y calcule el area del rectangulo.
	
	(3, 4)             (10, 4) (sdx, sdy)
	x-------------------sd
	|		    |
	|                   |
	|                   |
	ii-------------------x
      (3, 1)               (10, 1)
      (iix, iiy)
*/

int main(){
	float sdx, sdy, iix, iiy;
	float base, altura;
	float area, perimetro;
	
	printf("Vertice inferior izquierdo:\n");
	printf("Introduce x: ");
	scanf("%f", &iix);
	printf("Introduce y: ");
	scanf("%f", &iiy);
	
	printf("Vertice superior derecho:\n");
	printf("Introduce x: ");
	scanf("%f", &sdx);
	printf("Introduce y: ");
	scanf("%f", &sdy);
	
	base = sdx - iix;
	altura = sdy - iiy;
	
	area = base * altura;
	perimetro = base + base + altura + altura;
	
	printf("Area es %f\n", area);
	printf("Perimetro es %f\n", perimetro);

	return 0;
}

