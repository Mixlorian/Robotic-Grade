#include <stdio.h>

int main(){
	int i, j, n, m;
	
	printf("n: ");
	scanf("%d", &n); // n <= 3
	printf("m: ");
	scanf("%d", &m); // m <= 5
	
	i = 1;
	while(i <= n){
		printf("%d: ", i);
		
		
		j = 1;
		
		while(j <= i){
			printf("(%d, %d) ", i, j);
			j++;
		}
		
		printf(" X ");
		
		j = i;
		
		
		while(j >= 1){
			printf("(%d, %d) ", i, j);
			j--;
		}
		
		
		printf("\n");
		i++;
	}

	return 0;
}
