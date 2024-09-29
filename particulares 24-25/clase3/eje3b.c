#include <stdio.h>



int main(){
	int h1, m1, h2, m2, total1, total2, dif;
	
	printf("hora 1\n");
	printf("======\n");
	printf("horas: ");
	scanf("%d", &h1);
	printf("minutos: ");
	scanf("%d", &m1);
	
	printf("hora 2\n");
	printf("======\n");
	printf("horas: ");
	scanf("%d", &h2);
	printf("minutos: ");
	scanf("%d", &m2);
	
	if(h1 > h2 || h1 == h2 && m1 > m2){
		printf("La hora mas tardia %02d:%02d\n", h1, m1);	
	}
	else{
		if(h2 > h1 || h2 == h1 && m2 > m1){
			printf("La hora mas tardia %02d:%02d\n", h2, m2);		
		}
		else{
			printf("son iguales\n");
		}
	}
	/*
	if(h1 > h2){
		printf("La hora mas tardia %02d:%02d\n", h1, m1);
	}
	else{ // h1 <= h2
		if(h2 > h1){
			printf("La hora mas tardia %02d:%02d\n", h2, m2);
		}
		else{
			if(m2 > m1){
				printf("La hora mas tardia %02d:%02d\n", h2, m2);
			
			}
			else{
				if(m1 > m2){
					printf("La hora mas tardia %02d:%02d\n", h1, m1);s
				}
				else{
					printf("son iguales\n");
				}
			}
		}
	}
	*/	
	return 0;	
}
