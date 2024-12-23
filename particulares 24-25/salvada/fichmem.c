#include <stdio.h>

/*

************************************
************************************


En el fichero robots.txt tenemos los datos de los robots:
3
mi_rabot 2 3 2 0		nombre x y unidades direccion
machupichu 1 2 2 3
maricris69 8 8 2 1


************************************
************************************

*/
typedef enum{
	NORTE, SUR, ESTE, OESTE
}TDireccion;
typedef struct{
	int x, y;
}TPosicion;
typedef struct{
	char nombre[50];
	TPosicion posicion;
	TDireccion dir;
	int unidades;
}TRobot;
#include <stdlib.h>
int main(){
	TRobot *robots = NULL;
	int numRobots = 0;
	FILE *f;
	
	f = fopen("robots.txt", "r");
	if(f != NULL){
		fscanf(f, "%d", &numRobots);
		robots = (TRobot *) malloc(sizeof(TRobot) * numRobots);
		for(int i = 1; i <= numRobots; i++){
			fscanf(f, "%s", robots[i-1].nombre);
			fscanf(f, "%d", &robots[i-1].posicion.x);
			fscanf(f, "%d", &robots[i-1].posicion.y);
			fscanf(f, "%d", &robots[i-1].unidades);
			fscanf(f, "%d", &robots[i-1].dir);
		}
		fclose(f);
		for(int i = 0; i < numRobots; i++){
			printf("%s (%d, %d)\n", robots[i].nombre, robots[i].posicion.x, robots[i].posicion.y);
		}
	}
	return 0;
}


/*
************************************
************************************

En el fichero datos.txt tenemos los datos de un vector.
12 23 24 12 32 43
34 12 23 12

************************************
************************************

*/
/*
#include <stdlib.h>
int main(){
	int *v;
	int nv, leido;
	FILE *f;
	
	
	f = fopen("datos.txt", "r");
	if(f != NULL){
		nv = 0;
		v = NULL;
		fscanf(f, "%d", &leido);
		while(!feof(f)){
			v = (int *) realloc(v, sizeof(int) * (nv + 1));
			v[nv] = leido;
			nv++;	
			fscanf(f, "%d", &leido);
		}
		fclose(f);
		// vector leido
		for(int i = 0; i < nv; i++){
			printf("%d ", v[i]);
		}
		free(v);
	}
	return 0;
}
*/
/*
************************************
************************************
El nombre del fichero me lo pasan por linea de argumentos.
El contenido del fichero sera:
5^
10^ 12^ 23^ 12^ 43
hay que meterlo en un vector
imprimir el vector
liberar la memoria.
*/
/*
typedef struct{
    int *v;
    int nv;
}TVectorDinamico;
#include <stdlib.h>
int main(int argc, char *argv[]){
    TVectorDinamico td = {NULL, 0};
    int x;
    FILE *f;
    if(argc == 2){
        f = fopen(argv[1], "r");
        if(f != NULL){
            fscanf(f, "%d", &(td.nv)); // leo el 5,
            printf("FILE *: %p\n", ftello(f));
            td.v = (int *) malloc(sizeof(int) * td.nv);
            for(int i = 1; i <= td.nv; i++){ // td.nv veces
                fscanf(f, "%d", &td.v[i - 1]);
	        printf("FILE *: %p\n", ftello(f));

            }
            fclose(f);
            for(int i = 0; i < td.nv; i++){
                printf("%d ", td.v[i]);
            }
            free(td.v);
        }
        else{
            printf("El fichero %s no existe\n", argv[1]);
        }
    }
    return 0;
}
*/
/*
    Escribe lineas en el fichero introducidas por el usuario,
    hasta que el usuario mete fin.
    El fichero a crear (el nombre) se recibe como argumento.
*/
/*
#include <string.h>
#include <stdlib.h>
char *leerCadena(){
    char leido;
    char *leida = NULL;
    int nc = 0;
    do{
        scanf("%c", &leido);
        if(leido != '\n'){
            leida = (char *) realloc(leida, sizeof(char) * (nc + 1));
            leida[nc] = leido;
            nc++;
        }
    }while(leido != '\n');
    leida = (char *) realloc(leida, sizeof(char) * (nc + 1));
    leida[nc] = '\0';
    return leida;
}
*/
// main mis_lineas.txt tuculo.txt
//      argc = 3
//      argv[0] = "main"
//      argv[1] = "lineas.txt"
//      argv[2] = "tuculo.txt"
/*
int main(int argc, char *argv[]){
    FILE *f;
    char *leida = NULL;
    if(argc == 2){
        f = fopen(argv[1], "w");
        do{
            if(leida != NULL){
                free(leida);
            }
            leida = leerCadena();
            fprintf(f, "%s\n", leida);
        }while(strcmp(leida, "fin") != 0);
        fclose(f);
    }
    return 0;
}
*/
/*
int main(){
    FILE *file; // para poder usar un fichero.
    file = fopen("tuculo.txt", "w"); // abro el fichero, "w" => para escritura (si no existe lo crea, si existe lo machaca)
    for(int i = 1; i <= 10; i ++){
        fprintf(file, "%d\n", i); // funciona el igual que el printf (pero hay que indicar el fichero destino)
    }
    fclose(file);
    return 0;
}
*/
