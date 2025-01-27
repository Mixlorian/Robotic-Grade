#include <stdio.h>

int main(){
	int i, n;
	char car;
	
	
	do{
		printf("Introduce un numero positivo mayor que 0: ");
		scanf("%d", &n); // n = 4
	}while(n <= 0);
	
	do{
		printf("Introduce un caracter: ");
		scanf(" %c", &car); // car = 't'
	}while(car >= '0' && car <= '9');


	i = 1;
	while(i <= n){
		printf("%c", car); // tttt
		i++;
	}
	printf("\n");
	
	i = 1;
	while(i <= n){
		printf("%d%c", i, car);
		i = i + 1;
	}
	printf("\n");
	return 0;
}
