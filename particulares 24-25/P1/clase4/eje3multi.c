#include <stdio.h>

int main(){
	int edad;
	
	print("Introduce la edad: ");
	scanf("%d", &edad);
	
	if(edad < 0){
		printf("Edad no puede ser negativa\n");
	}
	else{
		if(edad <= 12){
			printf("niño\n");
		}
		else{
			if(edad <= 17){
				printf("adolescente nazi\n");
			} 
			else{
				if(edad <= 64){
					printf("Adulto\n");
				}
				else{
					printf("Adulto mayor\n");
				}
			}
		}
	}
	return 0;
}
