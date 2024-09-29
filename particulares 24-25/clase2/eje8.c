/*
Realiza un programa que pida una cantidad en centimos y muestre por
pantalla con cuantas monedas de
	1 euros
	50 centimos
	5 centimos
	1 centimo
podemos construir dicha cantidad. Minimizando el numero total de monedas
*/

#include <stdio.h>

int main(){
	int cantidad, m1e, m50, m5, m1;
	
	printf("Introduce la cantidad a cambiar: ");
	scanf("%d", &cantidad); // <= 1234
	
	// COMPLETA EL CODIGO CON TODOS LOS CALCULOS.
	m1e = cantidad / 100; // m1e = 1234 / 100 => 12
	cantidad = cantidad % 100; // m1e = 1234 % 100 => 34
	

	m50 = cantidad / 50; // m50 = 34 / 50 => 0
	cantidad = cantidad % 50;  // cantidad = 34 % 50 = 34
	
	m5 = cantidad / 5; // m5 = 34 / 5 => 6
	m1 = cantidad % 5; // m5 = 34 % 5 => 4
	
	
		
	
	return 0;
}
