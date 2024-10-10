/*
1. Realiza un programa que pida un numero n y muestre
por pantalla los divisores de ese valor.

	n: 8
	1 2 4 8

		 8 8 8 8 8 8 8 8
	divisor: 1 2 3 4 5 6 7 8

*/
#include <stdio.h>

int main(){
	int n, divisor;
	
	printf("n: ");
	scanf("%d", &n); // n <= 8
	
	divisor = 1;
	while(divisor <= n){
		if(n % divisor == 0){
		// if(8 % 1 == 0){ // si
		// if(8 % 2 == 0){ // si
		// if(8 % 3 == 0){ // no
		// if(8 % 4 == 0){ // si
		// if(8 % 5 == 0){ // no
		// if(8 % 6 == 0){ // no
		// if(8 % 7 == 0){ // no
		// if(8 % 8 == 0){ // si
			printf("%d ", divisor);
		}
		divisor++;
	}
	printf("\n");
	
	
	return 0;
}

