#include <stdio.h>


// Introduce las horas: 2
// Introduce los minutos: 23
// El total de minutos es 143 minutos

int main(){
	int horas, minutos, total;
	
	printf("Introduce las horas: ");
	scanf("%d", &horas);
	printf("Introduce los minutos: ");
	scanf("%d", &minutos);
	
	total = horas * 60 + minutos;
	
	printf("El total es %d minutos\n", total);
	
	return 0;
}
