
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
