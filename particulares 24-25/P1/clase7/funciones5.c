#include <stdio.h>


// becil => devuelve la suma de los divisores de n.
int becil(int n){
	int sumaDivisores = 0;
	int divisor = 1;
	while(divisor <= n){ // divisor <= 6
		if(n % divisor == 0){
// 		if(n % 1 == 0){ si
//			sumaDivisores = 0 + 1
// 		if(n % 2 == 0){ si
//			sumaDivisores = 1 + 2
// 		if(n % 3 == 0){ si
//			sumaDivisores = 3 + 3
// 		if(n % 4 == 0){ no
// 		if(n % 5 == 0){ no
// 		if(n % 6 == 0){ si
//			sumaDivisores = 6 + 6 => 12
			sumaDivisores = sumaDivisores + divisor;
		}
		divisor++;
	}
	return sumaDivisores; // 12
}

int main(){
	int valor, sd;
	
	printf("Valor: ");
	scanf("%d", &valor); // valor <= 6

	sd = becil(valor); // sd = becil(6); n = 6
	printf("la suma de los divisores: %d\n", sd);
	
	return 0;
}
