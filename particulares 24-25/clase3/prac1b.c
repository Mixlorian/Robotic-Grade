#include <stdio.h>

int main(){
	int a, b, aux;
	
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	
	// los intercambio si el segundo es menor que le primero
	if(a > b){
		aux = b;
		b = a;
		a = aux;
	}
	
	printf("%d %d\n", a, b);
	
	return 0;
}
