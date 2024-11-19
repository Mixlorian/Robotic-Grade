/*
Ejercicio 1.
Implementa un programa capaz de almacenar los datos de hasta 20 productos,
de cada producto se conocerá su nombre (maximo 50 caracteres), el precio
de venta al publico y su stock (inicialmente será 0).
El programa tendra un menu con dos opciones:
    1. Rellenar n productos.
    2. Imprimir los productos.
    3. Salir.

En la opcion 1 primero se pedirá la cantidad de productos a rellenar, este
tendra que ser un valor entre 0 y 20. A continuacion se pedira para cada
producto su nombre, su precio y su stock, estos dos ultimos mayores que 0.

En la opcion 2 se imprimiran todos los productos.

Nota: Debeis usar una variable para saber cuantas posiciones del vector
estarán ocupadas.
*/
#include <stdio.h>

#define KTAM 50
typedef char TCadena [KTAM];

typedef struct{
	TCadena nombre; //char nombre[50];
	float pvp;
	int stock;
}TProducto;

int main(){
	// crea dos productos con los datos indicados (dos variables distintas)
	// e imprime los campos.
	TProducto p = {"pipas", 12, 2000};
	TProducto p2 = {"peras", 2, 34};
	printf("%s, %.2f, %d\n", p.nombre, p.pvp, p.stock);
	printf("%s, %.2f, %d\n", p2.nombre, p2.pvp, p2.stock);
	
	// crear un vector de 3 productos con los datos indicados.
	TProducto prods [] = {
		{"laptop", 100, 3},	// Producto
		{"mobile f1", 230, 10},	// Producto
		{"mouse fx dragon", 923, 100}, // Producto
		{"lolipops", 333, 20}
	};
	//                             i
	/*
	printf("%s, %.2f, %d\n", prods[0].nombre, prods[0].pvp, prods[0].stock);
	printf("%s, %.2f, %d\n", prods[1].nombre, prods[1].pvp, prods[1].stock);
	printf("%s, %.2f, %d\n", prods[2].nombre, prods[2].pvp, prods[2].stock);
	printf("%s, %.2f, %d\n", prods[1].nombre, prods[1].pvp, prods[3].stock);
	*/
	// imprimir el nombre, precio y stock de todos los productos de prods.
	for(int i = 0; i < 4; i++){
		printf("%s, %.2f, %d\n", prods[i].nombre, prods[i].pvp, prods[i].stock);
	}
	// imprimir el stock total
	int stockTotal;
	stockTotal = 0;
	for(int i = 0; i < 4; i++){
		stockTotal += prods[i].stock;
	}
	printf("El stock total es %d\n", stockTotal);
	
	// Incrementar en un 10% el precio del producto 0
	prods[0].pvp *= 1.1;
	// Incrementar en un 10% el precio de todos los productos.
	for(int i = 0; i< 4; i++){
		prods[i].pvp *= 1.1;
	}
	// El producto mas caro
	int posMasCaro = 0; // supongo que el primero es el mas caro.
	for(int i = 1; i < 4; i++){
		// compruebo si el que hay en la posicion i es mas caro que 
		// el que hay en la posicion posMasCaro
		if(prods[i].pvp > prods[posMasCaro].pvp){
			posMasCaro = i;
		}
	}
	printf("%s, %.2f, %d\n", prods[posMasCaro].nombre, prods[posMasCaro].pvp, prods[posMasCaro].stock);
	
	
	// leemos los datos de un producto y los almaceno en la posicion 0.
	printf("Nombre: ");
	scanf(" %[^\n]", prods[0].nombre);
	printf("Precio: ");
	scanf("%f", &prods[0].pvp);
	printf("Stock: ");
	scanf("%d", &prods[0].stock);
	printf("has introducido: ");
	printf("%s, %.2f, %d\n", prods[0].nombre, prods[0].pvp, prods[0].stock);
	
	// leer los 3 productos que faltan!!!
	for(int i = 1; i < 4; i++){
		printf("Nombre: ");
		scanf(" %[^\n]", prods[i].nombre);
		printf("Precio: ");
		scanf("%f", &prods[i].pvp);
		printf("Stock: ");
		scanf("%d", &prods[i].stock);
		printf("Exito en alta...\n");
	}
	
	printf("Los datos de los nuevos productos son: \n");
	for(int i = 0; i < 4; i++){
		printf("%s, %.2f, %d\n", prods[i].nombre, prods[i].pvp, prods[i].stock);
	}

	
	return 0;
}
