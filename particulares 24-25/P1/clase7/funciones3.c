#include <stdio.h>

int uno(){
	return 1;
}

int dos(){
	return 2;
}

int suma(int a, int b){
	int s;
	s = a + b;
	return s;
}

void printSuma(int a, int b){
	int s;
	s = a + b;
	printf("%d\n", s);
}

int main(){
	int s;
	
	// s = 1 * 2 + 3 * 2;
	s = uno() * dos() + 3 * dos();
	printf("%d\n", s);

	s = suma(3, 5); // a = 3, b = 5
	printf("%d\n", s); // 8
	
	/*s = */printSuma(3, 4); // a = 3, b = 4
	printf("%d\n", s);	

}
