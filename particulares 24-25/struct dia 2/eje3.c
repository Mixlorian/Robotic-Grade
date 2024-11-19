#include <stdio.h>
/*
	De cada alumno sabemos, su nombre (vector de 50 caracteres),
	su descuento (numero real) y un vector con las notas de sus 
	ultimas calificasiones (maximo 10).
	
	Tenemos hasta 5 alumnos.
*/

typedef struct{
	char nombre[50];
	float descuento;
	float notas[10];
	int numNotas;	// cantidad de posiciones ocupadas del vector anterior	
}TAlumno;


typedef TAlumno TListaAlumnos [5];

int main(){
	// TAlumno lista[5];
	TListaAlumnos lista = {
		{"marcos", 0, {5, 8, 6.5}, 3}, // 0
		{"borja", -10, {7, 5, 6.75}, 3},  // 1
		{"jorge mas", 100, {0, 2, 8.9, 9.9}, 4}, // 2
		{"elba", 200, {6.2, 6.3, 6.1, 6.2, 1.2}, 5}, // 3
		{"vincent", -12.32, {5.2}, 1}
	};
	// 1. Imprimir los nombres de todos los alumnos.
	for(int i = 0; i < 5; i++){
		printf("Nombre: %s\n", lista[i].nombre); 
	}

	// 2. Imprimeme la ultima nota que ha sacado Elba.
	printf("Ultima nota de elba %.2f\n", lista[3].notas[4]);
	
	// 3. Imprimeme la ultima nota de todos los alumnos y su nombre.
	for(int i = 0; i < 5; i++){
		printf("Nombre: %s ", lista[i].nombre); 
		printf("nota: %.2f\n", lista[i].notas[lista[i].numNotas - 1]);
	}
	


	return 0;
}
