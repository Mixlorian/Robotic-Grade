#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
/*		0	1	2	3
	----------------------------------
	0|	3	1	4	1
	1|	2	1	2	2
	2|	1	2	3	5
*/
	int m[3][4] = {
		3, 1, 4, 1, 
		2, 1, 2, 2, 
		1, 2, 3, 5
	};
	int suma;
	printf("%d\n", m[0][0]);
	printf("%d\n", m[2][3]);
	printf("La fila 1\n");
	//		    j
	printf("%d ",  m[1][0]);
	printf("%d ",  m[1][1]);
	printf("%d ",  m[1][2]);
	printf("%d\n", m[1][3]);
	// imprime la fila 2 con un bucle.
	for(int j = 0; j < 4; j++){
		printf("%d ", m[2][j]);
	}
	printf("\n");
	// Suma los elementos de la fila 0 y muestralos por pantalla.
	suma = 0;
	for(int j = 0; j < 4; j++){
		suma += m[0][j];
		//        0  0
		//        0  1
		//        0  2
		//        0  3
	}
	printf("La suma es %d \n", suma);
	
	// Imprimir toda la matriz, cada fila en una linea distinta
	// separando los elementos por comas nazis.
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%d", m[i][j]);
			//		0  0
			//		0  1
			//		0  2
			//		0  3
			// -----------------
			//		1  0
			//		1  1
			//		1  2
			//		1  3
			// -----------------
			//		2  0
			//		2  1
			//		2  2
			//		2  3
				
			if(j != 3){
				printf(", ");
			}
		}
		printf("\n");
	}
/*		0	1	2	3
	----------------------------------
	0|	3	1	4	1
	1|	2	1	2	2
	2|	1	2	3	5
*/
	int A[3][5];
	// Rellenad la matriz aleatoria con valores en 0 y 20
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			A[i][j] = rand() % 21;
		}
	}
	
	// Imprimir la matriz con columnas de 4.
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
/*
Al final de cada fila poner la suma de la fila.
Al final de cada columna la fila de la columna. 

   1   4   9  19   8  41
  10  10   9  15  10  54
   2  19  20   4  20  65
  13  23  38  38  38
*/
	for(int i = 0; i < 3; i++){
		suma = 0;
		for(int j = 0; j < 5; j++){
			printf("%4d", A[i][j]);
			suma += A[i][j];
		}
		printf("%4d\n", suma);
	}
	
	for(int j = 0; j < 5; j++){
		suma = 0;
		for(int i = 0; i < 3; i++){
			suma += A[i][j];
			//        0  0
			//        1  0
			//        2  0
			// ------------
			//        0  1
			//        1  1
			//        2  1
			// ------------
		}
		printf("%4d", suma);
	}
	printf("\n");
	
/*
- El menor elemento de cada fila al final de la fila
y el mayor elemento de cada columna al final de la columna.

   1   4   9  19   8
  10  10   9  15  10
   2  19  20   4  20
*/
	printf("\n\n");
	int menor;
	// El menor de cada fila.
	for(int i = 0; i < 3; i++){
		menor = A[i][0]; // el primer elemento de la fila i :) ;)
		for(int j = 0; j < 5; j++){
			printf("%4d", A[i][j]);
			// si encuentro uno menor en j actualizo.
			if(A[i][j] < menor){
				menor = A[i][j];
			}
		}
		printf("%4d\n", menor);
	}
	int mayor;
	// El mayor de cada columna.
	for(int j = 0; j < 5; j++){
		mayor = A[0][j];
		for(int i = 0; i < 3; i++){
			if(A[i][j] > mayor){
				mayor = A[i][j];
			}
		}
		printf("%4d", mayor);
	}
	printf("\n");
	
// rellenar la matriz con los valores introducidos por el usuario
// los valores que no tengan dos digitos y no sean positivos se 
// ignoraran.
	int rellenamela[2][3];	
/*
Introduce los valores de la matriz separados por espacios:
2 3 1
2 3 4
y la matriz se rellenara con los valores introducios.

2 3 1 2 3 4
*/
	printf("Introduce 2 filas y 3 columnas: ");
	printf("\n");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &rellenamela[i][j]);
		}
	}
	
	printf("================\n");
	for(int i = 0; i <2; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", rellenamela[i][j]);
		}
		printf("\n");
	}
	return 0;
}






