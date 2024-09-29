#include <stdio.h>

int main(){
	int numero, suma;
	
	suma = 0;
	
		
	printf("Introduce primer digito: ");
	scanf("%d", &numero); 	// 5
	suma = suma * 10 + numero; // 0 * 10 + 5 => 5

	printf("Introduce segundo digito: ");
	scanf("%d", &numero); // 3
	suma = suma * 10 + numero; // 5* 10 + 3 = 53
	
	printf("Introduce tercer digito: ");
	scanf("%d", &numero);	// 2
	suma = suma * 10 + numero; // 53 * 10 + 2 = 532
	
	printf("Introduce cuarto digito: ");
	scanf("%d", &numero); // 1
	suma = suma * 10 + numero; // 5320 + 1

	
	printf("%d\n", numero);


}
