#include <stdio.h>
#include <ctype.h>



int main(){
	char cadena[100];
	int i, vocales;
	
	printf("Introduce una cadena: ");
	scanf(" %[^\n]", cadena); // lee hasta el salto de linea.
	
	printf("Cadenita <%s>\n", cadena);
	
	// cuenta las vocales :).
	vocales = 0;
	i = 0;
	while(cadena[i] != '\0'){
		if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'i'){
			vocales++;
		}
		i++;
	}
	printf("La cantidad de vocales encontradas es %d\n", vocales);
	
	// capitalizamos las palabras frase.
	// La primera letra de cada palabra se pone en mayusculas.
	
	// la casa es grande y blanca
	// La Casa Es Grande Y Blanca
	
	i = 0;
	while(cadena[i] != '\0'){
		if(i == 0 || cadena[i] != ' ' && cadena[i-1] == ' '){
			cadena[i] = toupper(cadena[i]); // pasa el caracter a mayuscula.
		}
		i++;
	}
	printf("Capitalizada: %s\n", cadena);
	
	
	
	
	
	
	
	
	
	return 0;
}
