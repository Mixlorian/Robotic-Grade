#include <stdio.h>

// 1 * 2 * 3 ... * n
int factorial(int n){
	int f;
	
	f = 1;
	for(int i = 1; i <= n; i++){
		f = f * i;
		// f = 1 * 1
		// f = 1 * 2
		// f = 2 * 3
		// f = 6 * 4
		// f = 24 * 5 = 120
	}
	
	return f;
}


int combinaciones(int n, int k){
	int fn, fk, fnk, r;
	
	fn = factorial(n);		// fn = factorial(5) => 120
	fk = factorial(k);		// fk = factorial(4) => 24
	fnk = factorial(n - k);		// fnk = factorial(1) => 1
	 
	r = fn / (fk * fnk);  // 120 / 24 = 5
	
	return r; // return 5
}


int main(){
	// 5 tomados de 4
	int resultado = combinaciones(5, 4); // n = 5, k = 4
	printf("El resultado es %d\n", resultado);
	printf("%d\n", factorial(5)); // n = 5
	
	int f = factorial(6); // n = 6
	printf("%d\n", f);


}
