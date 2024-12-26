////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int **m;
    int filas, columnas;
}TMatrizD;

/*
filas: 3
columnas 2
valores, separa las columnas por espacios y las filas por saltos de linea:
2 3
1 2
3 1
*/
void leerMatriz(TMatrizD *mat){

}

TMatrizD leerMatriz(){

}
/*
Imprime la matriz en ancho de columnas de 4.
   2   3
   1   2
   3   1
*/
void imprimir(TMatrizD mat){

}

void liberarMatriz(TMatrizD *mat){

}

typedef struct{
    int *elementos;
    int tamano;
}TVectorD;

// Copia la matriz en el vector, los elementos de la matriz
// se guardan de forma secuencial, por filas de izquierda a derecha:
// v.elementos = {2, 3, 1, 2, 3, 1}
// v.tamano = 6
void ejercicioExamen(TMatrizD mat, TVectorD *v){

}

int main(){
    TMatrizD mi_matriz;
    // 1. lee la matriz usando la funcion
    // 2. imprime la matriz usando la funcion
    // 3. libera la matriz.
}


/////////////////////////////////////////////////////////
#include <stdio.h>
#define M 6
#define N 6
typedef int TMatriz [M][N];

void imprimir(TMatriz m){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%4d", m[i][j]);
        }
        printf("\n"); // cada fila en una linea distinta
    }
}


void zigZagFilas(TMatriz m){
    for(int i = 0; i < M; i++){
        if(i % 2 == 0){
            for(int j = 0; j < N; j++){
                printf("%4d", m[i][j]);
                //              0  0
                //              0  1
            }
        }
        else{
            for(int j = N - 1; j >= 0; j--){
                printf("%4d", m[i][j]);
            }
        }
        printf("\n"); // cada fila en una linea distinta
    }

}

// MxN
void zigZagColumnas(TMatriz m){
    for(int j = 0; j < N; j++){ // fijo la columna
        // si es par la columna la recorro de arriba a abajo.
        if(j % 2 == 0){
            for(int i = 0; i < M; i++){
                printf("%4d", m[i][j]);
                //              0  0
                //              1  0
                //              2  0
                //              ....
                //              0  2
                //              1  2
                //              2  2
            }
        }
        else{
            for(int i = M - 1; i >= 0; i--){
                printf("%4d", m[i][j]);
                //              5  1
                //              4  1
                //              3  1
                //              2  1
                //              1  1
                //              0  1
                //              5  3
                //              4  3
            }
        }
        printf("\n");
    }
}


#include <stdlib.h>
void fillRandom(TMatriz m){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            m[i][j] = rand() % 99 + 1;
        }
    }
}


int main_ziza(){
    TMatriz m;
    printf("\nRellenando matriz de forma aleatorioa...\n");
    fillRandom(m);
    printf("Imprimiendo la matriz normalita...\n");
    imprimir(m);
    printf("\n\n");
    printf("Imprimiendo la matriz en zig zaf filas\n");
    zigZagFilas(m);
    printf("\n\n");
    printf("Imprimiendo la matriz en zig zog filos\n");
    zigZagColumnas(m);
    printf("ta luek\n");

}













////////////////////////////////////////////////////////////
#include <stdio.h>
#define N 10
typedef enum{Norte, Sur, Este, Oeste} TDireccion;

// ejercicio 2 y 3
typedef struct{
    int x, y;
}TPosicion;

typedef struct{
    TPosicion pos;
    TDireccion direccion;
    int unidades;
}TRobot;

typedef TRobot TRobots [N];

typedef struct{
    TRobots robots; // podre tener almacenados hasta N robots :)
    int numRobots; // cuantas posiciones hay ocupadaas en este vector
}TGrupoRobots;

// ejercicio 3
// ajco de practicas, hacedlo en plan ascooooo...

// ejercicio 2
void imprimirPosicion(TPosicion p){
    printf("(%d, %d)", p.x, p.y);
}

void imprimirRobot(TRobot r){
    char nombres[4][6] = {"NORTE", "SUR", "ESTE", "OESTE"};
    printf("Pos = ");
    imprimirPosicion(r.pos); // r.pos => TPosicion
    printf(", direccion = %5s, unidades = %2d",
           nombres[r.direccion], r.unidades);
}

void imprimeGrupo(TGrupoRobots gr){
    for(int i = 0; i < gr.numRobots; i++){
        printf("%2d: ", i);
        imprimirRobot(gr.robots[i]);
        printf("\n");
    }
}

int main_ejercicio2(){
    TGrupoRobots grupo = {
        {
            {{3, 4}, Norte, 3}, // grupo.robots[0]
            {{5, 8}, Sur, 4}, // grupo.robots[1]
            {{2, 9}, Este, 3}, // grupo.robots[2]
            {
             {0,   // grupo.robots[3].x
              0}, // grupo.robots[3].y
             Sur, // grupo.robots[3].direccion
             2}  // grupo.robots[3].unidades
        }, // grupo.robots
        4 // grupo.numRobots
    };
    printf("\n");
    imprimeGrupo(grupo);

    return 0;
}

int main_RAW(){
    TGrupoRobots grupo = {
        {
         {{3, 4}, Norte, 3}, // grupo.robots[0]
         {{5, 8}, Sur, 4}, // grupo.robots[1]
         {{2, 9}, Este, 3}, // grupo.robots[2]
         {
          {0,   // grupo.robots[3].x
            0}, // grupo.robots[3].y
          Sur, // grupo.robots[3].direccion
          2}  // grupo.robots[3].unidades
        }, // grupo.robots
        4 // grupo.numRobots
    };

    // nombres[0] =>     "NORTE"
    // nombres[1] =>     "SUR"
    char nombres[4][6] = {"NORTE", "SUR", "ESTE", "OESTE"};
    for(int i = 0; i < grupo.numRobots; i++){
        printf("(%d,%d)", grupo.robots[i].pos.x, grupo.robots[i].pos.y);

        printf(" %s ", nombres[grupo.robots[i].direccion]);

        // no podemos imprimir directamente el valor del enumerado
        // porque saldria el valor de constante asociado, 0 para Norte ...
        /*switch(grupo.robots[i].direccion){
        case Norte:
            printf("NORTE");
            break;
        case Sur:
            printf("SUR");
            break;
        case Este:
            printf("ESTE");
            break;
        case Oeste:
            printf("OESTE");
            break;
        }*/
        printf(" %d\n", grupo.robots[i].unidades);
    }

}


//////////////////////////////////////////////////////////////////////
/// //////////////////////////
/// /////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MINP 3
#define MAXP 50

typedef struct{
    int x, y;
}TCoordenada;

// Un TListaCoordenadas es un puntero a coordenada.
typedef TCoordenada * TListaCoordenadas;

typedef struct{
    TListaCoordenadas vertices;
    int numVertices; // cantidad de elementos que tiene el vector :)
}TPoligono;

// Ejercicio de la hoja 2.
TCoordenada leerCoordenada(int nVertice){
    TCoordenada leida;
    printf("Introduce el vertice %d x, y: ", nVertice);
    scanf("%d,%d", &leida.x, &leida.y);
    return leida;
}

// Ejercicio de la hoja 3.
// TPoligono poli;
// leerPoligono(&poli);
void leerPoligono(TPoligono *poligono){
    do{
        printf("Introduce el numero de vertices (%d - %d): ", MINP, MAXP);
        scanf("%d", &poligono->numVertices);
        if(poligono->numVertices < MINP){
            printf("Error, muy pocos\n");
        }
        else{
            if(poligono->numVertices > MAXP){
                printf("Error, demasiados\n");
            }
        }
    }while(poligono->numVertices < MINP || poligono->numVertices > MAXP);

    // No hago realloc porque ya se la cantidad e putos vertices que voy a necesitar!
    poligono->vertices = (TListaCoordenadas) malloc(sizeof(TCoordenada) * poligono->numVertices);

    // Esto estaria bien si admitiera repetidos!!!
    //for(int i = 0; i < poligono->numVertices; i++){
    //    poligono->vertices[i] = leerCoordenada(i + 1);
    //}

    int pos;
    TCoordenada leida;
    for(int i = 0; i < poligono->numVertices; i++){
        // para la coordenada leida tengo que comprobar que ya no esta en el vector.
        do{
            leida = leerCoordenada(i + 1);
            pos = -1;
            for(int k = 0; k < i && pos == -1; k++){ // busco hasta i-1, estamos intentando rellenar la posicion i, posiciones ya rellenadas desde 0 hasta i-1
                if(leida.x == poligono->vertices[k].x && leida.y == poligono->vertices[k].y){
                    pos = i;
                }
                if(pos != -1){
                    printf("Error, repetido.");
                }
            }
        }while(pos != -1); // mientras que lo haya encontrado
        poligono->vertices[i] = leida;
    }

}

// eje 1, devuelve le poligiono leido por el usuario,
// se pueden devolver structs.
// Alternativa al ejercicio de la hoja 3.

// int main(){
//      TPoligono poli;
//      poli = leerPoligono();

TPoligono leerPoligono(){
    TPoligono poligono;
    // igual que la de arriba quitando la -> y cambiandola por un .
    // PRUEBA A HACERLA SIN MIRAR :)

    return poligono;
}

#include <math.h>
// TCoordenada c1 = {2, 3}, c2 = {2, 8};
// printf("%.2f\n", calcularDistancia(c1, c2));
float calcularDistancia(TCoordenada c1, TCoordenada c2){
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

int main_poligono_ejercicio(){
    // Ejercicio de la hoja 1.
    // Forma 1.
    TPoligono p = {NULL, 0};
    // Forma 2.
    TPoligono poligono; // poligono.vertices, poligono.numVertices
    poligono.vertices = NULL;
    poligono.numVertices = 0;
    float distancia;

    leerPoligono(&poligono);

    for(int i = 0; i < poligono.numVertices; i++){
        if(i != poligono.numVertices - 1){
            distancia = calcularDistancia(poligono.vertices[i],
                                      poligono.vertices[i+1]);
        }
        else{ // si es el ultimo se calcula la distancia con el 0.
            distancia = calcularDistancia(poligono.vertices[i],
                                          poligono.vertices[0]);
        }
        printf("%d vertice: (%d, %d) %.2f\n",
               i + 1,
               poligono.vertices[i].x,
               poligono.vertices[i].y,
               distancia);
    }
    // EJERCICIO SI ME ABURRO, PRUEBA A METER EL CODIGO DE MOSTRAR
    // EL POLIGNO DENTRO DE UNA FUNCION E INVOCALA DESDE EL MAIN.

    free(poligono.vertices);
    return 0;
}



int main_0(){
    // Eje 1. Crea una lista de coordenadas dinamica
    // e incializao con los valores (0, 0) ... (4,4)
    // imprimela por pantalla y liberala.
    TListaCoordenadas lista;
    // creariamos un vector de 5 coordenadas.
    lista = (TListaCoordenadas) malloc(sizeof(TCoordenada) * 5);
    for(int i = 0; i < 5; i++){
        lista[i] = {i, i};
    }
    for(int i = 0; i < 5; i++){
        printf("(%d, %d) ", lista[i].x, lista[i].y);
    }
    free(lista);
}
