#include <stdio.h>

#define KTAM 50
typedef char TCadena [KTAM];

typedef struct{
	TCadena nombre; //char nombre[50];
	float pvp;
	int stock;
}TProducto;

void leerProducto(TProducto *p){
	printf("Nombre: ");
	scanf(" %[^\n]", (*p).nombre);
	printf("Pvp: ");
	scanf("%f", &(*p).pvp);
	printf("Stock: ");
	scanf("%d", &(*p).stock);
}

void leerProductoArrows(TProducto *p){
	printf("Nombre: ");
	scanf(" %[^\n]", p->nombre);
	printf("Pvp: ");
	scanf("%f", &p->pvp);
	printf("Stock: ");
	scanf("%d", &p->stock);
}

void imprimirProducto(TProducto p){
	printf("Nombre: %s\n", p.nombre);
	printf("Pvp: %.2f\n", p.pvp);
	printf("Stock: %d\n", p.stock);
}

int main(){
	TProducto pa = {"jose", 300, 1};
	imprimirProducto(pa); // TProducto p = pa;
	
	leerProducto(&pa);
	imprimirProducto(pa);
}

