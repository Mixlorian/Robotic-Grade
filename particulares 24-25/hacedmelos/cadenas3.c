#include <stdio.h>
#include <stdbool.h>
#define KTAM 50
typedef char TCadena [KTAM];

// devuelve cierto, si las dos cadenas son iguales
// devuelve falso si no.

//       01234
// c1 = "jorge"
// c2 = "jorge"
bool iguales(TCadena c1, TCadena c2){
	bool son;
	int i;
	son = true;
	i = 0;
	while(c1[i] != '\0' && c2[i] != '\0' && son){
		if(c1[i] != c2[i]){
			son = false;
		}
		else{
			i++;
		}
	}
	if(c1[i] != '\0' || c2[i] != '\0'){
		son = false;
	}
	return son;
}

int main(){
	TCadena cad1, cad2;
	
	printf("Introduce una cadena: ");
	scanf(" %s", cad1);
	printf("Introduce otra cadena: ");
	scanf(" %s", cad2);
	
	if(iguales(cad1, cad2)){
		printf("son iguales\n");
	}
	else{
		printf("son disitntas\n");
	}
	
	return 0;
}
