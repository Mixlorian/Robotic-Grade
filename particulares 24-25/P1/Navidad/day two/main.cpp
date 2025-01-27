#include <stdio.h>


int main(){
    // Como escribimos por pantalla del 1 al 5.
    for(int i = 1; i <= 5; i++){
        printf("%d\n", i);
    }
    // Como escribimos del 1 al 5 en el fichero, de nombre daatosNavidad.txt, cada numero en una linea?
    // Solo cambia que tenemos que indicar el fichero destino.
    FILE *file = fopen("datosNavidad.txt", "w"); // fichero para escritura!!
    if(file != NULL){
        for(int i = 1; i <= 5; i++){
            fprintf(file, "%d\n", i);
        }
        fclose(file);
    }
    // Como leemos 5 enteros de pantalla y los almacenamos en un vector.
    int v[5];
    printf("introduce 5 valores enteros: ");
    for(int i = 0; i< 5; i++){
        scanf("%d", &v[i]);
    }
    // Como leo los 5 valores entero que hay en el fichero datosNavidad.txt y los meto en un vector.
    file = fopen("datosNavidad.txt", "r");
    if(file != NULL){
        for(int i = 0; i < 5; i++){
            fscanf(file, "%d", &v[i]); // todos los espacios y todos los intros que hayan entre dos entero se ignoran!!
        }
        fclose(file);
        printf("Vector leido del fichero: ");
        for(int i = 0; i < 5;  i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    return 0;
}
    // Escribir un vector dinamico en un fichero, es igual que escribir un vector estatico.!!

    // LEER UN VECTOR DINAMICO DEL FICHERO!!
    // Opcion 1: En la primera linea aparezca el tamaño del vector.
    //          1.1 - Hacemos una primera lectura para leer el tamaño
    //          1.2 - Reservamos con malloc
    //          1.3 - Leemos el resto de elementos del fichero y los almaceno en el vector.

    // Opcion 2: No sabemos a priori cuantos elementos hay en el vector.
    //          while(!feof(file)){ // mientras que no llegue al fin del fichero.
    //              para cada elemento leido, tengo que reservar una posicion mas en el vector con realloc
    //              almacenar el valor leido en esa posicion!!

    // MATRIZ DE EXAMEN
    //          Leer una matriz de un fichero
    //          Muy parecido al leerMatriz que acabamos de hacer, porque en la primera linea del fichero
    //          vamos a tener la dimension de la matriz, creas la matriz y leemos el resto de elementos del fichero
    //          y los almaceno en la matriz.




    

#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 4
typedef int TMatriz [M][N];
void fillMatrizRandom(TMatriz m){
}
void fillMatrizUsuario(TMatriz m){
}
void fillMatrizFichero(TMatriz m, char fileName[]){
}
void printMatriz(TMatriz m){
}
typedef struct{
    int fil, col;
}TPosicion;
typedef struct{         // aqui guardo la posicion que ocupa el valor en la matriz.
    TPosicion pos;
    int valor;
}TElemento;
typedef struct{
    TElemento *elementos;
    int nElementos;         // cantidad de elementos almacenados de la matriz.
}TVectorED;
// almaceno los elementos de la matriz que no son nulos.
// matriz
//      0   1   2   3
//0     12  0   0   32
//1      0  0   0   3
//2      0  4   0   0
//
// lo que tengo que construir
//                  vector.nElementos = 4
//                  vector.elementos = {{0, 0, 12}, {0, 3, 32}, {1, 3, 3}, {2, 0, 4}}
TVectorED extraerNoNulos(TMatriz matriz){
    TVectorED vector = {NULL, 0};

    // COMO TENEMOS QUE CREAR UN VECTOR CON LA CANTIDAD DE ELEMENTOS QUE NO SON NULOS,

    //      OPCION 1: RECORRO LA MATRIZ, CUENTO LA CANTIDAD DE ELEMENTOS NO NULOS, LLAMO A MALLOC Y VUELVO A RECORRER LA MATRIZ!

    //      OPCION 2: RECORRIENDO LA MATRIZ SOLO UNA VEZ, CADA VEZ QUE ME ENCUENTRO UN ELEMENTO DISINTO DE NULL, REDIMENSIONAMOS
    //      EL VECTOR ACTUAL AÑADIENDO UN ELEMENTO PARA GUARDAR EL NUEVO ELEMENTO NO NULO.

    return vector;
}

int main(){
    TMatriz m = {12, 0, 0, 32, 0, 0, 0, 3, 0, 4, 0, 0};
    TVectorED vec;
    vec = extraerNoNulos(m);
    for(int i = 0; i < vec.nElementos; i++){
        printf("%d, %d = %d\n", vec.elementos[i].pos.fil, vec.elementos[i].pos.col, vec.elementos[i].valor);
    }
    return 0;
}

