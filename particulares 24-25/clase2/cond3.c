#include <stdio.h>

/*
	Realiza un programa que pida dos valores sneteros a y b.
	Si ambos valores son positivos muestra la suma de ambos valores,
	en otro caso, muestra el producto de ambos valores.
*/
int main(){
	int a,  b;
	
	printf("Intorduce los dos vlaores: ");
	scanf("%d %d", &a, &b);
	
	if(a >= 0){
		if(b >= 0){
			printf("%d + %d = %d\n",a, b, a + b);  // 1
		}
		else{
			printf("%d * %d = %d\n", a, b, a * b);	// 2	
		}
	}
	else{
		printf("%d * %d = %d\n", a, b, a * b); // 3
	}

	return 0;
}
