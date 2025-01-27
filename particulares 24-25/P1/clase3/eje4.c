/*
4. Programa que pida por pantalla los coeficientes de un polinomio de segundo grado a, b y c. Muestra por pantalla las raices del polinomio, puntos de corte con el eje x.

	ax² + bx + c = 0

ayuda:
*/


#include <math.h>
#include <stdio.h>

int main(){
	float a, b, c, raiz1, raiz2;

	printf("a b c: ");
	scanf("%f %f %f", &a, &b, &c);

	raiz1 = (-b + sqrt(b*b - 4 * a * c)) / (2*a);
	raiz2 = (-b - sqrt(b*b - 4 * a * c)) / (2*a);

	printf("raiz1 es: %f\n", raiz1);
	printf("raiz2 es: %f\n", raiz2);
	

	return 0;
}
