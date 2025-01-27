#include <stdio.h>

int main(){
	int n1, n2, n3, aux;
	
	
	printf("Introduce 3 numeros (separados por espacios): ");
	scanf("%d %d %d", &n1, &n2, &n3);

	if(n3 < n2){
		aux = n3;
		n3 = n2;
		n2 = aux;
	}
	if(n2 < n1){
		aux = n2;
		n2 = n1;
		n1 = aux;
	}
	if(n3 < n2){
		aux = n3;
		n3 = n2;
		n2 = aux;
	}
	printf("%d %d %d\n", n1, n2, n3);

/*	
	if(n1 <= n2 && n2 <= n3){
	
	}
	else{
		if(n1 <= n3 && n3 <= n2){
			printf("%d %d %d\n", n1, n3, n2);
		}
		else{
			if(n2 <= n1 && n1 <= n3){
			
			}
			else{
				if(n2 <= n3 && n3 <= n1){
				
				}
				else{
					if(n3 <= n2 && n2 <= n1){
					
					}
					else{
						if(n3 <= n1 && n1 <= n2){
						
						}
						else{
						
						}
					}
				}
			}
		}
	}
*/	
	
	
	return 0;
}


