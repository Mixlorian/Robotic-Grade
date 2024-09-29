#include <stdio.h>

/*
- Realiza un programa que pida al usuario una cantidad de minutos y
muestre por pantalla, las horas y los minutos totales

Introduceme los minutos: 146
Horas: 2
Minutos: 26

*/

int main(){
	int horas, minutos, total;

	printf("Introduceme los minutos: ");
	scanf("%d", &total); // total = 128
	
	horas = total / 60; 	// 128 / 60 = 2
	minutos = total % 60;	// 128 / 60 = 8
	// minutos = total - horas * 60;
	
	printf("Horas: %d\n", horas);
	printf("Minutos: %d\n", minutos);

	return 0;
}
