#include <stdio.h>


// cambia a mayusculas la cadena pasada como parametro
void funcion(char cad[]){
    int i = 0;
    int intervalo = 'a' - 'A';

    while(cad[i] != '\0'){
        if(cad[i] >= 'a' && cad[i] <= 'z'){
            cad[i] = cad[i] - intervalo;
        }
        i++;
    }
}

/*
int main(){
    char cad[] = "libertad para Albacete";
    funcion(cad);
    printf("%s\n", cad);
}
*/

// Propuesto 1.
// Modifica la funcion anterior para
// que si es una consontante la pase a mayusuculas
// y si es una vocal a minuscula.

#define TAM1 5
#define TAM2 5
int matriz[TAM1][TAM2] = {
  // j     j     j
  // 0  1  2  3  4
    {1, 4, 2, 3, 5},
    {2, 1, 5, 4, 5},
    {4, 4, 6, 7, 5},
    {3, 3, 7, 7, 5},
    {1, 1, 7, 8, 5}
};

// intercambia los elementos 2 a 2.
void intercambiar(int m[][TAM2]){
    int aux;
    for(int i = 0; i < TAM1; i++){
        for(int j = 0; j < TAM2 - 1; j = j + 2){
            aux = m[i][j];
            m[i][j] = m[i][j+1];
            m[i][j+1] = aux;
        }
    }
}

// Propuesto 2 intercambia las filas de la matriz
// la 0 con la 1, la 2 con la 3 ...

/*
0    {2, 1, 5, 4, 5},
1    {1, 4, 2, 3, 5},
2    {3, 3, 7, 7, 5},
3    {4, 4, 6, 7, 5},
4    {1, 1, 7, 8, 5}
*/

/*
int main(){
    intercambiar(matriz);
    for(int i = 0;  i < TAM1; i++){
        for(int j = 0; j < TAM2; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

// devuelve la suma de los elementos del vector
// que son mayores que elem.
int sumaMayorIterativa(int array[], int elem, int n){
    int suma = 0;
    for(int i = 0; i < n; i++){
        if(array[i] > elem){
            suma += array[i];
        }
    }
    return suma;
}

// Propuesto 3.
// Devuelve en la estructura los elementos del
// array que son mayores que elem.
typedef struct{
    int *v;
    int nv;
}TVector;

TVector extraer(int array[], int elem, int n){
    TVector resultado;


    return resultado;
}

// Propuesto 4
// Devuelve en la estructra los del elementos del
// array que son mayores que elem, junto con su posicion.
typedef struct{
    int valor;
    int pos;
}TInfo;

typedef struct{
    TInfo *v;
    int nv;
}TVectorInfo;

TVectorInfo extraerPosis(int array[], int elem, int n){
    TVectorInfo vi;

    return vi;
}


// ---------------------------------
// PROPUESTO 5.
/*
int main(){
    int array[] = {4, 10, 2, 6, 1, 7};

    return 0;
}
*/
#define TAM 5

typedef struct{
    int x, y;
}TPunto;

typedef struct{
    TPunto p1;
    TPunto p2;
}TSegmento;

typedef TSegmento TSegmentos [TAM];
typedef int TMatriz [TAM][4];

// m es de entrada
// s es de salida
void convertir(TSegmentos s, TMatriz m){

}


int main_propuesto5(){
    int matriz[TAM][4] = {{1,4,2,3},
                          {2,1,5,4},
                          {4,4,6,7},
                          {3,3,7,7},
                          {1,1,7,8}};

    TSegmentos segs;
    convertir(segs, matriz);
/*
 = {

        {
         {1,  // segs[0].p1.x
          4}, // segs[0].p1.y
         {2, 3}  // segs[0].p2
        },  // segs[0]
        {{2, 1}, {5, 4}},
        {{4, 4}, {6, 7}},
        {{3, 3}, {7, 7}},
        {{1, 1}, {7, 8}}   // segs[4]

    };
*/
    return 0;
}





