#include <stdio.h>

/*
	Realiza un programa que pida un caracter y dos numeros enteros.
	El caracter debe ser o un + o un -, en otro caso mostrar error
	y acabara.
	
	El programa mostrara el resultado de la operacion seleccionada
	usando como parametros a y b.
*/

int main(){
	char operador;
	int a, b, resultado;
	
	printf("Introduce + para sumar y - para restar: ");
	scanf(" %c", &operador);
	
	
	if(operador == '+'){
		printf("Introduce a: ");
		scanf("%d", &a);
		printf("Introduce b: ");
		scanf("%d", &b);
		resultado = a + b;
		printf("%d %c %d = %d\n", a, operador, b, resultado);
	}
	else{
		if(operador == '-'){
			printf("Introduce a: ");
			scanf("%d", &a);
			printf("Introduce b: ");
			scanf("%d", &b);
			resultado = a - b;
			printf("%d - %d = %d\n", a, b, resultado);
		}
		else{
			printf("Error\n");
		}
	}
	
	return 0;
}
