#include <stdio.h>
#include <math.h>

int main(){
	float a, b, c, r1, r2, discriminante;
	
	printf("Coef. de la ecuacion (a b c): ");
	scanf("%f %f %f", &a, &b, &c);
	
	printf("Ecuacion: %.2f·x^2 + %.2f·x + %.2f\n", a, b, c);
	discriminante = b * b - 4 * a * c;
	
	if(a == 0){
		if(b == 0){
			printf("Hay soluciones infinitas nazis\n");
		}
		else{
			printf("Hay una unica solucion real\n");
			r1 = -c / b;
			printf("La unica solucion %.2f\n", r1);
		}
	}
	else{
		if(discriminante == 0){
			printf("hay una solucion, el suicidio\n");
			r1 = -b / (2 * a);
			printf("La unica solucion %.2f\n", r1);
		}
		else{
			if(discriminante < 0){
				printf("no hay soluciones reales\n");
			}
			else{
				printf("there is 2 solutions\n");
				r1 = (-b + sqrt(discriminante)) / (2*a);
				r2 = (-b - sqrt(discriminante)) / (2*a);
				printf("x = %.2f y x = %.2f\n", r1, r2);
			}

		}
	}

	return 0;
}
