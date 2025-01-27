#include <stdlib.h>
#include <stdio.h>
#define MAX_ICONOS 10
#define MAX_NOMBRE 50
#define DIMENSION_PATRON 5

typedef struct {
    char *nombre;
    char **patron;
    int dim;
} TIcono;

typedef struct {
    TIcono *lista;
    int cantidad;
} TColeccionIconos;
//################## IMPORTANTE ##################################
char **crearMatriz(int filas, int columnas){
    char **m;
    m = (char **) malloc(sizeof(char *) * filas);
    for(int i = 0; i < filas; i++){
        m[i] = (char *) malloc(sizeof(char) * columnas);
    }
    return m;
}

// lee una cadena de caracteres desde teclado de forma dinamica
char *leerCadena(){
    char *cad = NULL;
    char leido;
    int n;
    do{
        // leo un caracter del teclado y lo añado a la cadena.
        scanf("%c", &leido);
        if(leido != '\n'){
            cad = (char *) realloc(cad, sizeof(char) * (n + 1));
            cad[n] = leido;
            n++;
        }
    }while(leido != '\n');
    cad = (char *) realloc(cad, sizeof(char) * (n + 1));
    cad[n] = '\0';
    n++;
    return cad;
}

TIcono leerIcono(int dimension){
    TIcono leido;
    printf("Introduce el nombre del icono: ");
    leido.nombre = leerCadena();
    printf("Introduce el patro de (%d x %d): ", dimension, dimension);
    leido.patron = crearMatriz(dimension, dimension);
    leido.dim = dimension;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            scanf(" %c", &leido.patron[i][j]);
        }
    }
    return leido;
}

// ./programa 4
// argv[1] = "4"
int main(int argc, char *argv[]){
    int dimension;
    TIcono leido;
    TColeccionIconos coleccion = {NULL, 0};

    ////////////// PROBANDO LOS ARGUMENTOS ////
    printf("El numero de argumento es %d\n", argc);
    printf("Y los argumentos son:\n");
    for(int i = 0; i < argc; i++){
        printf("%d => %s\n", i, argv[i]);
    }
    //////////////////////////////////////////
    if(argc == 2){
        dimension = atoi(argv[1]); // la cadena la paso a entero y es la dimension del patron.
        printf("La dimension del patron sera: %d\n", dimension);

        printf("Introduce la cantidad de iconos que quieres leer: ");
        scanf("%d", &coleccion.cantidad);

        coleccion.lista = (TIcono *) malloc(sizeof(TIcono) * coleccion.cantidad);
        for(int i = 0; i < coleccion.cantidad; i++){
            coleccion.lista[i] = leerIcono(dimension);
        }
        // Recorre la coleccion e imprime los iconos.
        // imprimir el icono leido
        // imprimir el nombre
        // imprimir el patron
    }
    return 0;
}