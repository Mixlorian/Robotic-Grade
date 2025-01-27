#include <stdio.h>

int main(){
	int i, c;
	
	i = 1;
	while(i <= 5){
		printf("%d ", i);
		i = i + 1;
	}
	printf("\n");
		
	i = 2;
	while(i <= 10){
		printf("%d ", i);
		i += 2; // i = i + 2
	}
	printf("\n"); // 2 4 6 8 10
	
	i = 10;
	while(i >= 1){
		printf("%d ", i);
		i--; // i -= 1; i = i - 1;
	}
	printf("\n");
	
	i = 1;
	c = 1;
	while(i <= 10){
		printf("%d ", i);
		i = i + c;
		c++;
	}
	printf("\n");


	return 0;
}
