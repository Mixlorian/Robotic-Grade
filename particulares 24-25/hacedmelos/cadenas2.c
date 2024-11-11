#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define KCADENA 50
typedef char TCadena [KCADENA];

bool comprobarMatricula(TCadena cadena){
	bool correcta = false;
	int i;
	
	if(strlen(cadena) == 8){
		i = 0;
		correcta = true;
		while(i < 4 && correcta){
			if(cadena[i] < '0' || cadena[i] > '9'){
				correcta = false;
			}
			else{
				i++;
			}
		}
		if(correcta){
			if(cadena[4] == '-'){
				i = 5;
				while(i < 8 && correcta){
					if(cadena[i] >= 'B' && cadena[i] <= 'Z' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U'){
						i++;
					}
					else{
						correcta = false;
					}
				}
			}
			else{
				correcta = false;
			}
		}
	}
	
	return correcta;
}

int main(){
	// Pedid una cadena al usuarios sin espacio y comprobaremos que es una matricula de
	// coche correcta.
	TCadena entrada;
	bool correcta;
	
	printf("Introduce una matricula: ");
	scanf(" %s", entrada);
	correcta = comprobarMatricula(entrada);
	if(correcta){
		printf("CORRECTA\n");
	}
	else{
		printf("INCORRECTA\n");
	}
	return 0;
}
