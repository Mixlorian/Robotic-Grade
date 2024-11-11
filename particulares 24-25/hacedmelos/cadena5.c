#include <stdio.h>
#include <string.h>
#define KTAM 50
#define KCADENAS 10

typedef char TCadena [KTAM];
typedef TCadena TListaCadenas [KCADENAS];



int main(){
	TListaCadenas lista; // vector de 10 cadenas.
	int n;
	
	strcpy(lista[0], "hola");
	strcpy(lista[1], lista[0]);
	strcpy(lista[2], lista[1]);
	strcat(lista[2], " mundo"); // añade la cadena al final.
	
	printf("%s\n", lista[0]);
	printf("%s\n", lista[1]);
	printf("%s\n", lista[2]);
/*
	lista[0] = "hola"
	lista[1] = "hola"
	lista[2] = "hola mundo"
	
	lista
			 0   1   2   3   4   5   6   7   8   9   10
		0 	'h' 'o' 'l' 'a' '\0'
		1	'h' 'o' 'l' 'a' '\0'
		2 	'h' 'o' 'l' 'a' ' ' 'm' 'u' 'n' 'd' 'o' '\0'

*/	
	for(int i = 0; i < 3; i++){
		int j = 0;
		while(lista[i][j] != '\0'){
			printf("%c ", lista[i][j]);
			j++;
		}
		printf("\n");
	}
	
	
	do{
		printf("Cuantas cadenas quieres rellenar?: ");
		scanf("%d", &n);
	}while(n < 0 || n > KCADENAS);

	// lista[0] => TCadena
	// lista[0][0] => char
	
	TCadena leida;
	for(int i = 0; i <  n; i++){
		printf("Introduce la cadena %d: ", i);
		scanf(" %[^\n]", leida);
		strcpy(lista[i], leida);
	}
	
	for(int i = 0; i < n; i++){
		printf("%s\n", lista[i]);
	}
	
	
		
	
	
	
	

	return 0;
}
