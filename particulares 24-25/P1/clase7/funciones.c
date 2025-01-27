#include <stdio.h>


void saluda(){
	printf("hola\n");
}


int main(){
	printf("esto no compila xicos\n");
	saluda();
	printf("hola pomarita\n");
	
	for(int i = 1; i <= 10; i++){
		printf("%d => ", i);
		saluda();
	}
	
	printf("---\n");
	
	
	return 0;
}
