#include <stdio.h>

int main(){
	int n1, n2, n3, aux;
	char orden;
	
	printf("Introduce tres numeros enteros: \n");
	printf("* Numero 1: ");
	scanf("%d", &n1);
	printf("* Numero 2: ");
	scanf("%d", &n2);
	printf("* Numero 3: ");
	scanf("%d", &n3);
	printf("Ascedente (A) o descendente (D)?: ");
	scanf(" %c", &orden);	
	
	if(orden != 'A' && orden != 'D'){
		printf("Orden incorrecto");
	}
	else{
		if(n3 < n2 && orden == 'A' || n3 > n2 && orden == 'D'){
			aux = n3;
			n3 = n2;
			n2 = aux;
		}
		if(n2 < n1 && orden == 'A' || n2 > n1 && orden == 'D'){
			aux = n2;
			n2 = n1;
			n1 = aux;
		}
		if(n3 < n2 && orden == 'A' || n3 > n2 && orden == 'D'){
			aux = n3;
			n3 = n2;
			n2 = aux;
		}
		printf("%d %d %d\n", n1, n2, n3);			
	}
	

	return 0;
}
