#include <stdio.h>

void impNC(int n){
	printf("%2d => ", n);
	for(int i = 1; i <= n; i++){
		printf("*");
	}
}

void impMCar(int m, char c){
	printf("%2d => ", m);
	for(int i = 1; i <= m; i++){
		printf("%c", c);
	}	
}

/*
n: 5		i	espacios	asteriscos
    *		1	4		1
   ***		2	3		3
  *****		3	2		5
 *******	4	1		7
*********	5	0		9
*/


int main(){
	impMCar(10, 'x'); //m = 10, c = 'x'
	printf("\n");
	impMCar(23, '-');	
	printf("\n");
	
	int filas;
	printf("Filas: ");
	scanf("%d", &filas); // filas <= 4
	for(int i = 1; i <= filas; i++){
		impMCar(filas - i, ' ');
		impMCar(2 * i - 1, '*');
		
		// i = 1 impCar(3, ' ');
		// i = 1 impCar(1, '*');
		
		// i = 2 impCar(2, ' ');
		// i = 2 impCar(3, '*');
		
		// i = 3 impCar(4-1, ' ');
		// i = 3 impCar(2*3-1, '*')
		
		// i = 4 impCar(4 - 4, ' ')
		// i = 4 impCar(7, '*')
	
		printf("\n");
	}
	
	
	impNC(3); // n = 3
	printf("\n");
	impNC(10); // n = 10
	printf("\n");
	
	int valor;
	printf("Valor: ");
	scanf("%d", &valor); // valor <= 6
	
	for(int i = 1; i <= valor; i++){
		impNC(valor); // n = valor
		printf("\n");
	}
	printf("\n");	

	for(int i = 1; i <= valor; i++){
		impNC(i);
		// i => 1 impNC(1) n = 1
		// i => 2 impNC(2) n = 2
		// i => 3 impNC(3) n = 3
		// ...
		printf("\n");
	}
	
	
	
	return 0;
}


