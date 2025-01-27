#include <stdio.h>

int main(){
	int num1, num2;
	
	printf("Escribe un numero entero: ");
	scanf("%d", &num1);
	printf("Escribe otro numero entero: ");
	scanf("%d", &num2);
	
	if(n1 >  n2){
		printf("El numero %d es mayor que el numero %d\n", num1, num2);
	}
	else{
		if(n2 > n1){
			printf("El numero %d es mayor que el numero %d\n", num2, num1);		
		}
		else{
			printf("Los numeros son iguales\n");		
		}
	}
	
	return 0;
}
