#include <stdio.h>
// Escribir un vector dinamico en un fichero, es igual que escribir un vector estatico.!!

// LEER UN VECTOR DINAMICO DEL FICHERO!!
// Opcion 1: En la primera linea aparezca el tamaño del vector. => [malloc]
//          1.1 - Hacemos una primera lectura para leer el tamaño
//          1.2 - Reservamos con malloc
//          1.3 - Leemos el resto de elementos del fichero y los almaceno en el vector.

//  N
//  elem1, elem2, ..., elemN

/*
    prog datos.txt

    argv[0] = "prog"
    argv[1] = "datos.txt"

*/
/*
#include <stdlib.h>
int main(int argc, char *argv[]){
    FILE *f;
    int n, i;
    int *v;
    if(argc != 2){
        printf("Error en parametros\n");
    }
    else{
        printf("Cantidad de argumentos %d\n", argc);
        printf("<%s> <%s>\n", argv[0], argv[1]);
        f = fopen(argv[1], "r");
        if(f != NULL){
            fscanf(f, "%d", &n);
            v = (int *) malloc(sizeof(int) * n);
            for(int i = 0; i < n; i++){
                // fscanf(f, "%d", &v[i]);
                fscanf(f, "%d", v + i); // nazi...
            }
            fclose(f);
            printf("vector leido del fichero:\n");
            for(int i = 0; i < n; i++){
                printf("%d ", v[i]);
            }
            printf("\n");
            free(v);
        }
        else{
            printf("%s no existe\n", argv[1]);
        }
    }
    return 0;
}
*/
// Opcion 2: No sabemos a priori cuantos elementos hay en el vector. =>  [realloc]
//          while(!feof(file)){ // mientras que no llegue al fin del fichero.
//              para cada elemento leido, tengo que reservar una posicion mas en el vector con realloc
//              almacenar el valor leido en esa posicion!!
/*
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "enteros.txt"
int main(){
    FILE *file;
    int leido, n;
    int *v;

    file = fopen(FILENAME, "r");
    if(file == NULL){
        printf("El fichero %s no existe\n", FILENAME);
    }
    else{
        v = NULL;
        n = 0;
        fscanf(file, "%d", &leido);
        while(!feof(file)){
            // proceso el elmento que he leido (guardarlo)
            v = (int *) realloc(v, sizeof(int) * (n + 1));
            v[n] = leido;
            n++;
            // intento leer el siguiente antes de volver a preguntar.
            fscanf(file, "%d", &leido);
        }
        fclose(file);
        for(int i = 0; i < n; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
        free(v);
    }
    return 0;
}
*/

// MATRIZ DE EXAMEN
//          Leer una matriz de un fichero
//          Muy parecido al leerMatriz que acabamos de hacer, porque en la primera linea del fichero
//          vamos a tener la dimension de la matriz, creas la matriz y leemos el resto de elementos del fichero
//          y los almaceno en la matriz.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **datos;
    int m, n;
}TMatriz;


// !!!aprendtela y usala!!!
// esta sirve siempre.
int **reservar(int filas, int columnas){
    int **m;
    int i;
    m = (int **) malloc(sizeof(int *) * filas);
    for(i = 0; i < filas; i++){
        m[i] = (int *) malloc(sizeof(int) * columnas);
    }
    return m;
}

// recibe la direccion de la matriz y la cantidad de filas :)
void liberar(int **m, int filas){
    for(int i = 0; i < filas; i++){
        free(m[i]);
    }
    free(m);
}



TMatriz crearMatriz_1(int m, int n){
    TMatriz matriz;

    matriz.m = m;
    matriz.n = n;
    matriz.datos = reservar(m, n);
    /*matriz.datos = (int **) malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++){
        matriz.datos[i] = (int *) malloc(sizeof(int) * n);
    }*/
    return matriz;
}

void crearMatriz_2(TMatriz *matriz){
    matriz->datos = reservar(matriz->m, matriz->n);
/*    matriz->datos = (int **) malloc(sizeof(int *) * matriz->m);
    for(int i = 0; i < matriz->m; i++){
        matriz->datos[i] = (int *) malloc(sizeof(int) * matriz->n);
    }*/
}

int main_matriz_basico(){
/*   int **datos;
    int m, n;*/

    TMatriz matriz;
    FILE *fich;
    fich = fopen("matriz.txt", "r");
    if(fich != NULL){
        fscanf(fich, "%d %d", &matriz.m, &matriz.n);
        /*matriz = crearMatriz_1(matriz.m, matriz.n);
        crearMatriz_2(&matriz);*/
        matriz.datos = reservar(matriz.m, matriz.n);

        for(int i = 0; i < matriz.m; i++){
            for(int j = 0; j < matriz.n; j++){
                fscanf(fich, "%d", &matriz.datos[i][j]);
            }
        }
        fclose(fich);
        printf("Matriz leida del fichero\n");
        for(int i = 0; i < matriz.m; i++){
            for(int j = 0; j < matriz.n; j++){
                printf("%4d", matriz.datos[i][j]);
            }
            printf("\n");
        }

        liberar(matriz.datos, matriz.m);
        matriz.datos = NULL;
        matriz.m = 0;
        matriz.n = 0;
    }
    else{
        printf("No existe el fichero matriz.txt\n");
    }


    return 0;
}
/*
En nuestro fichero ahora hay dos matrices del mismo tamaño y cuadradas.
El tamaño de las matriz esta en la primera linea.
3
1 2 3 3 2 1
4 4 4 5 5 5
9 9 9 8 8 8

Tenemos que leer las dos matrices, trasponerlas y sumarlas.
Mostrad la suma por pantalla.

mat1 = mat1 + mat2
*/
void sumar(int **mat1, int **mat2, int N){
    // -----------
    // PROPUESTO 1
    // -----------

}
// intercambia filas por columnas!
void trasponer(int **m, int N){
    // -----------
    // PROPUESTO 2
    // -----------

}

int main_matrices(){
    int **mat1, **mat2;
    int N;
    FILE *file;

    file = fopen("matrices.txt", "r");
    if(file != NULL){
        fscanf(file, "%d", &N);
        mat1 = reservar(N, N);
        mat2 = reservar(N, N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                fscanf(file, "%d", &mat1[i][j]);
            }
            for(int j = 0; j < N; j++){
                fscanf(file, "%d", &mat2[i][j]);
            }
        }
        fclose(file);
        sumar(mat1, mat2, N); // mat1 = mat1 + mat2
        trasponer(mat1, N);
        // por hacerlo distinto guardo el resultado en un fichero.
        file = fopen("suma_matrices.txt", "w");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                fprintf(file, "%d", mat1[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);

        liberar(mat1, N);
        liberar(mat2, N);
    }
    return 0;
}

/*
    Ejercicio 4. Enero 2024
*/
#define KNOMBRE_PRODUCTO 30
#define KNOMBRE_PROVEEDOR 30
typedef char TNombreProducto [KNOMBRE_PRODUCTO + 1];
typedef char TNombreProveedor [KNOMBRE_PROVEEDOR + 1];

typedef struct{
    int codigo;
    TNombreProducto nombre;
    float precio;
    // un vector de cadenas, (en cada posicion un vector de 31 chars)
    TNombreProveedor *proveedores;
    int numProveedores;
}TProducto;

typedef TProducto TProductos [KNOMBRE_PRODUCTO];
typedef struct{
    TProducto *productos;
    int numProductos;
}TListaProductos;

int main(){
    TProducto leido;
    FILE *file;
    TListaProductos lista;
    lista.numProductos = 0;
    lista.productos = NULL;


    file = fopen("productos.txt", "r");
    if(file != NULL){
        fscanf(file, "%d", &lista.numProductos);
        for(int i = 0; i < lista.numProductos; i++){
            // leo el producto y lo almacen en TProducto
            // leo codigo
            // leo cadena
            // leo un real
            // leo un entero (tam)
            // creo un vector con este tam
            // los siguientes elementos (leo tam elementos)
            // van en el vector!!

            lista.productos[i] = leido;
        }
        fclose(file);
        // imprime luego los productos por pantalla!
    }

    return 0;
}





