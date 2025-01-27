#include <stdio.h>
 

int main(){
	int n, i, j;
	
	printf("n: ");
	scanf("%d", &n);
	
	i = 1;
	while(i <= n){	
		printf("%d", i);
		
		
		j = 1;
		while(j <= i){
			printf("*");
			j++;
		}
		

		j = 1;
		while(j <= i){
			printf("%d", j);
			j++;
		}

		
		j = 1;
		while(j <= n){
			printf("#");
			j++;
		}

		
		i++;1
		printf("\n");
	}
	
	for(i = 1; i <= n; i++){
		printf("%d", i);
		for(j = 1; j <= i; j++){
			printf("*");
		}
		for(j = 1; j <= i; j++){
			printf("%d", j);
		}
		printf("\n");
	}
	
	
	return 0;
}
