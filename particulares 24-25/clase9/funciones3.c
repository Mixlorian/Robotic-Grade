/*
	1. Añadid a este programa la figura cuadrado
	2. Añadid las sentencias necesarias para que al final del programa
	muestre, la cantidad total de cada figura, la suma total de las areas
	y de los perimetros.
*/
#include <stdio.h>
#include <math.h>
// gcc -o funciones2 funciones2.c -lm
float areaCirculo(float radio){
	float res;
	res = M_PI * pow(radio, 2);
	return res;
}
float perimetroCirculo(float radio){
	float res;
	res = 2 * M_PI * radio;
	return res;
}
float areaRectangulo(float base, float altura){
	float res;
	res = base * altura;
	return res;
}
float perimetroRectangulo(float base, float altura){
	return 2 * (base + altura); // directamente el resultado.
}
void imprimirResultadosCirculo(float a, float p){
	printf("El area del circulo es %f y el permeto es %f\n", a, p);
}
void imprimirResultadosRectangulo(float a, float p){
	printf("El area del rectangul es %f y el perimetro es %f\n", a, p);
}
int main(){
	int nfiguras, i;
	float base, altura, radio, area, perimetro;
	char tipo;
	
	do{
		printf("Cuantas figuras?: ");
		scanf("%d", &nfiguras);
		if(nfiguras <= 0){
			printf("Error debe ser positivo\n");
		}
	}while(nfiguras <= 0);

	for(i = 1; i <= nfiguras; i++){
		printf("Figura %d\n", i);
		printf("=========\n");
		do{
			printf("c para circle, r para rectangle?: ");
			scanf(" %c", &tipo);-3
			if(tipo != 'c' && tipo != 'r'){
				printf("Error en figura.\n");
			}
		}while(tipo != 'c' && tipo != 'r');
		switch(tipo){
			case 'c':
				printf("radio?: ");
				scanf("%f", &radio);
				area = areaCirculo(radio);
				perimetro = perimetroCirculo(radio);
				imprimirResultadosCirculo(area, perimetro);
			break;
			case 'r':
				printf("base?: ");
				scanf("%f", &base);
				printf("altura?: ");
				scanf("%f", &altura);
				area = areaRectangulo(base, altura);
				perimetro = perimetroRectangulo(base, altura);
				imprimirResultadosRectangulo(area, perimetro);
			break;
		}			
	}
	
	// Realiza un programa que pida un numero n positivo al usuario
	// y la figura de la cual se quiere calcular su area y su perimetro.
	// El programa pedirá los datos de n figuras elegida y mostrara
	// por pantalla su area y su perimetro usando las funciones anterios.
	// cuantas figuras: 3
	// figura 1.
	// c para circulo, r para rectangulo? c
	// introduce el radio: 3
	// area:
	// perimetro
	// figura 2.
	// c para circulo, r para rectangulo? c
	// introduce el radio: 3
	// area:
	// perimetro
	// figura 3.
	// c para circulo, r para rectangulo? r
	// base:
	// altura:
	// area:
	// perimetro
}
