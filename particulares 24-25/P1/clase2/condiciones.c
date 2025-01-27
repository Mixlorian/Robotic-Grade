#include <stdio.h>


int main(){
	int a;
	
	printf("a?: ");
	scanf("%d", &a);

	// a pertenece a un rango (esta entre dos valores)
	// 	ejemplo a, tiene dos digitos.
	
	if(a >= 10 && a <= 99){
		printf("Tiene dos digitos\n");
	}
	
	// a esta fuera de un rango
	if(a < 100 || a > 999){
		printf("No tiene 3 digitos\n");
	}  
	
	// a sea uno de los valores del conjunto
	// 	 a es un mes de 30 dias => {4, 6, 9, 11}
	if(a == 4 || a == 6 || a == 9 ||  a == 11){
		printf("tiene 30 dias\n");
	}
	
	// a no sea uno de los valores de los valores del conjunto.
	// 	 a no tiene 30 dias, no es ninguno de los anteriores.
	if(a != 4 && a != 6 && a != 9 && a != 11){
		printf("No tiene 30 dias\n");
	}


	if(a < 10 && a > 100){ // siempre falsa
		printf("fuera\n");
	} 
	if(a >= 100 || a <= 1000){ // siempre true
		printf("jarl\n");
	}
	if(a == 3 && a == 5 && a == 7){ // siempre falsa
		printf("muerte\n");
	}
	if(a != 5 || a != 9 || a != 12){ // siempre cierto
		printf("mondermor\n");
	}
	

	return 0;
}
