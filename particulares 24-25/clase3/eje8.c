/*
Realiza un programa que pida una cantidad en centimos y muestre por
pantalla con cuantas monedas de
	1 euros
	20 centimos
	5 centimos
	1 centimo
podemos construir dicha cantidad. Minimizando el numero total de monedas
*/

#include <stdio.h>

int main(){
	int cantidad, m1e, m20, m5, m1;
	
	printf("Introduce la cantidad a cambiar: ");
	scanf("%d", &cantidad); // <= 1278
	
	m1e = cantidad / 100;		// 1278 / 100 => 12
	//cantidad = cantidad - m1e * 100;
	cantidad = cantidad % 100;	// 1278 % 100 => 78
	
	m20 = cantidad / 20;		// 78 / 20 => 3
	cantidad = cantidad % 20;	// 78 % 20 => 18
	
	m5 = cantidad / 5;		// 18 / 5 => 3
	m1 = cantidad % 5;		// 18 % 5 => 3
	
	if(m1e > 0){
		printf("monedas de 1 euro: %d\n", m1e);
	}
	if(m20 > 0){
		printf("monedes de 20 centimos: %d\n", m20);
	}
	if(m5 > 0){
		printf("monedes de 5 centimos: %d\n", m5);
	}
	if(m1 > 0){
		printf("monedas de 1 centimo: %d\n", m1);
	}
	return 0;
}
