#include <stdio.h>


// realiza un programa que pida por pantalla
// 3 valores enteros y muestre la media de esos valores con decimales.

int main(){
	int n1, n2, n3;
	float media;
	
	
	printf("Introduce los 3 valores separados por espacios: ");
	scanf("%d %d %d", &n1, &n2, &n3);
	
	// el cociente arroja un resultado real si alguno 
	// de los operando es real.
	
	media = (n1 + n2 + n3) / 3.0;
	
	media = (float) (n1 + n2 + n3) / 3;
	
	printf("la media es %.2f\n", media);
	
	return 0;
}
