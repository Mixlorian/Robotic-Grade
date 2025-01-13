#include <stdlib.h>
#include <stdio.h>

//################## IMPORTANTE ##################################
char **crearMatriz(int filas, int columnas){
    char **m;
    m = (char **) malloc(sizeof(char *) * filas);
    for(int i = 0; i < filas; i++){
        m[i] = (char *) malloc(sizeof(char) * columnas);
    }
    return m;
}
// SUPER IMPORTANTE!!
char *leerCadenaDinamica(){
    char *cadena = NULL; // DIRECCION 0 (NO GUARDO DIRECCION ALGUNA).
    int i;
    char leido;
    i = 0;
    do{
        scanf("%c", &leido); // leido = matriz[p][q];
        if(leido != '.'){
            // añado un caracter al final de la cadena.
            cadena = (char *) realloc(cadena, sizeof(char) * (i + 1)); // una posicion mas para la cadena
            cadena[i] = leido;
            i++;
        }
    }while(leido != '.' && i < TAM - 1);
    cadena = (char *) realloc(cadena, sizeof(char) * (i + 1)); // una posicion mas para la cadena
    cadena[i] = '\0';
    return cadena;
}

char *guardarPalabra(TMatriz matriz){
    char *cadena = NULL;
    int k = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] >= 'A' && matriz[i][j] <= 'Z'){  // >= 'A' && <= 'Z'
                cadena = (char *) realloc(cadena, sizeof(char) * (k + 1));
                cadena[k] = matriz[i][j];
                k++;
            }
        }
    }
    cadena = (char *) realloc(cadena, sizeof(char) * (k + 1));
    cadena[k] = '\0';
    return cadena;
}

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

//################# CREAR NUMERO RANDOM ######################pragma endregion
int aleatorio = rand(); //numero desde 0 hasta 32767
//Ajustando el rango min y max
int aleatorio;
int min = 0, max = 10;
aleatorio = (rand()%(max-min+1))+min;

// Como escribimos del 1 al 5 en el fichero, de nombre daatosNavidad.txt, cada numero en una linea?
// Solo cambia que tenemos que indicar el fichero destino.
FILE *file = fopen("datosNavidad.txt", "w"); // fichero para escritura!!
if(file != NULL){
    for(int i = 1; i <= 5; i++){
        fprintf(file, "%d\n", i);
    }
    fclose(file);
}