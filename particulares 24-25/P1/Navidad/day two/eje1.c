#include <stdio.h>
#include <stdlib.h>
    // Escribir un vector dinamico en un fichero, es igual que escribir un vector estatico.!!

    // LEER UN VECTOR DINAMICO DEL FICHERO!!
    // Opcion 1: En la primera linea aparezca el tamaño del vector.
    //          1.1 - Hacemos una primera lectura para leer el tamaño
    //          1.2 - Reservamos con malloc
    //          1.3 - Leemos el resto de elementos del fichero y los almaceno en el vector.
    void leerVectorMalloc(int *v, char fichero[]){
        int numVec;
        FILE *file =fopen(fichero,"r");
        if(file != null){
            fscanf(fichero,"%d",&numVec);
            v = (int*)malloc(sizeof(int)*numVec);
            for(i = 0; i < numVec; i++){
                fscanf(fichero,"%d",v[i]);
            }
            fclose(file);
        }
    }

    // Opcion 2: No sabemos a priori cuantos elementos hay en el vector.
    //          while(!feof(file)){ // mientras que no llegue al fin del fichero.
    //              para cada elemento leido, tengo que reservar una posicion mas en el vector con realloc
    //              almacenar el valor leido en esa posicion!!
    void leerVectorRealloc(int *v,char fichero[]){
        int numVec;
        FILE *file=fopen(fichero,"r");
        if(file!= null){
            while (!feof(file)){
                v = (int*)realloc(v,sizeof(int)*(numVec+1));
                fscanf(fichero,"%d",v[numVec]);
                numVec++;
            }
        }
    }

    // MATRIZ DE EXAMEN
    //          Leer una matriz de un fichero
    //          Muy parecido al leerMatriz que acabamos de hacer, porque en la primera linea del fichero
    //          vamos a tener la dimension de la matriz, creas la matriz y leemos el resto de elementos del fichero
    //          y los almaceno en la matriz.


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


