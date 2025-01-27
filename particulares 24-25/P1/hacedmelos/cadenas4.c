#include <stdio.h>
#define KTAM 50
typedef char TCadena[KTAM];

// si se llega a '0' comenzaria desde '0'
// c = 2
// El puto jorge

// El0 p1ut2o 3jo4rg5e

// cada c caracteres vamos a añadir un digito.

void codificar(TCadena org, TCadena codificada, int c){
	int i, j;
	int borja;
	char digito = '0';
	
	borja = 0; // numero de caracteres que has copiado
	i = 0;
	j = 0; // por donde voy almacenando en la cadena destino.
	while(org[i] != '\0'){
		codificada[j] = org[i];
		j++;
		i++;
		borja++;
		if(borja == c){ // ya he copiado c caracteres
			// añado un digito!!
			codificada[j] = digito;
			j++;
			// vuelvo a esperar
			borja = 0;
			if(digito == '9'){
				digito = '0';
			}
			else{
				digito++;
			}
		}
	}
	codificada[j] = '\0';
}

int main(){
	TCadena cadena, codificada;
	
	printf("Introduce una cadena: ");
	scanf(" %[^\n]", cadena);
	
	codificar(cadena, codificada, 3);
	printf("%s\n", codificada);
	
	return 0;
}
