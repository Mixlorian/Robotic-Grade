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
	
	total1 = h1 * 60 + m1;
	total2 = h2 * 60 + m2;
	
    if(total1 > total2){
        printf("la hora mas tardia es %d:%02d\n", h1,m1);
    }else{
        if(total1 < total2){
            printf("la hora mas tardia es %d:%02d\n", h2,m2);
        }else{
            printf("son iguales\n");
        }
    }
	return 0;
}
