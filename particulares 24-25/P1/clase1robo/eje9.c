#include <stdio.h>

int main(){
	int n, u, d, c;
	
	printf("Numero de 3 digitos: ");
	scanf("%d", &n);
	
	// n = 247
	
	u = n % 10;	// 247 % 10 => 7
	c = n / 100;	// 247 / 100 => 2
	// d = n - c * 100;
	d = n / 10 % 10;	// 247 / 10
				// 	24 % 10 => 4
	return 0;
}
