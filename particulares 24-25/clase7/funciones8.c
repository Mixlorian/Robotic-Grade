#include <stdio.h>

// devuelve la suma de los dos valores a y b
int suma2(int a, int b){ // a = 2, b = 3
			// s = 2 + 3
			// return 5
			
			// a = 5, b = 5
			// s = 5 + 5
			// return 10
	int s;
	s = a + b;
	return s;
}

// suma los valores a b y c usando la funcion anterior.
int suma3(int a, int b, int c){ // a = 2, b = 3, c = 5
	int s;

	s = suma2(a, b); // s = suma2(2, 3) = 5
	s = suma2(s, c); // s = suma2(5, 5) = 10 
	
	return s; // return 10
}


int main(){
	int x, y, z, s;
	
	// pedid 3 valores
	printf("x y z?: ");
	scanf("%d %d %d", &x, &y, &z); // 2 3 5
	
	// sumalos usando la funcion suma3
	s = suma3(x, y, z); // s = suma3(2, 3, 5) = 10
	
	// muestra el resultado por pantalla
	printf("La suma es %d\n", s); // 10
 
}
