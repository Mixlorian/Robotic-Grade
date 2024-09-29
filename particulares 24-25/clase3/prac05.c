#include <stdio.h>

int main(){
	int numero, suma;
	
	
	printf("Introduce primer digito: ");
	scanf("%d", &numero); 	// 5
	suma = numero * 1000;	// suma = 5 * 1000 = 5000

	printf("Introduce segundo digito: ");
	scanf("%d", &numero); // 3
	suma = suma + numero * 100; // suma = 5000 + 3 * 100 = 5300
	
	printf("Introduce tercer digito: ");
	scanf("%d", &numero);	// 2
	suma = suma + numero * 10; // suma = 5300 + 2 * 10 = 5320
	
	printf("Introduce cuarto digito: ");
	scanf("%d", &numero); // 1
	suma = suma + numero; // suma = 5320 + 1
	
	printf("%d\n", numero);
	
	
	
	return 0;
}
