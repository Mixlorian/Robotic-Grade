#include <stdio.h>

typedef enum {CARNE = 1, VERDURA, PAN} TipoAlimento;
typedef enum {MODOASADOLENTO, MODOASADORAPIDO, 
		MODOVCOCIONVAPOR, MODOVAPORRAPIDO, MODOHORNEADO, PRECAL, ESTA}
		Modos;

int main(){
	TipoAlimento alimento;
	Modos modo;
	int gramos, grados;
	
	printf("Introdue el tipo de alimento (1-Carne, 2-Verdura, 3-Pan): ");
	scanf("%u", &alimento);
	printf("Introduce la cantidad d ealimentos en gramos: ");
	scanf("%d", &gramos);
	printf("Introduce la temperatura inicial del alimento en ºC: ");
	scanf("%d", &grados);
	
	switch(alimento){
		case CARNE:
			if(gramos >= 300 && grados < 5){
			
			}
			else{
			
			}
			
			if(gramos >= 300 && grados < 5){
			
			}
			else{
				if(gramos >= 300 && grados >= 5){
				
				}
				else{
				
				}
			} 
			
			if(gramos >= 300){
				if(grados < 5){
				
				}
				else{
				
				}
			}
			else{
			
			}
		break;
		case VERDURA:
		
		break;
		case PAN:
		
		break;
		default:
			modo = ESTA;
			break;
	}
	// para imprimir el resultado por pantalla
	switch(modo){
		case MODOASADOLENTO:
			printf("Modo asado lento\n");
			break;
	}
	
	return 0;
}
