#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nombres[5][100];
	
	printf("Introduce 5 nombres uno por linea:\n");
	// Introduce 5 nombres uno por linea.
	for(int i = 0; i < 5; i++){
		scanf(" %[^\n]", nombres[i]);
	}
	
	// Los nombres introducidos son 
	printf("Los nombres introducidos son: \n");
	for(int i = 0; i < 5; i++){
		printf("%s (%lu)\n", nombres[i], strlen(nombres[i]));
	}
	printf("\n");
	
	
	// Pide un nombre al usuario y muestra por pantalla
	// si esta o no esta en la lista de nombres introducida
	char buscado[100];
	int pos, i;
	
	printf("Introduce el nombre a buscar: ");
	scanf(" %[^\n]", buscado);
	i = 0;
	pos = -1;
	while(i < 5 && pos == -1){
		if(strcmp(buscado, nombres[i]) == 0){ 
			// nombres[i] == buscado (es mal)
			pos = i;
		}
		else{
			i++;
		}
	} 
	if(pos == -1){
		printf("Nombre no encontrado\n");
	}
	else{
		printf("Encontrado en la fila %d\n", pos);
	}
	printf("\n");
	
	
	
	return 0;
}
