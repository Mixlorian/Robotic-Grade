#include <stdio.h>
#include <stdlib.h>

#define NUM_FILAS 4
#define NUM_COLUMNAS 5
typedef int TMatrizE [NUM_FILAS][NUM_COLUMNAS];

// devuelve un vector dinamico con los elementos impares
// de la matriz añadiendo un -1 al final de estos para saber
// cual es la ultima posicion del vector.
int *sacarImpares(TMatrizE m){
    int *vector = NULL;
    int k = 0;

    for(int i = 0; i < NUM_FILAS; i++){
        for(int j = 0; j < NUM_COLUMNAS; j++){
            if(m[i][j] % 2 != 0){
                vector = (int *) realloc(vector, sizeof(int) * (k + 1));
                vector[k] = m[i][j];
                k++;
            }
        }
    }
    vector = (int *) realloc(vector, sizeof(int) * (k + 1));
    vector[k] = -1;

    return vector;
}


#define TAM 50
typedef char TCadena [TAM];

#define MAX_AREAS 100
#define MAX_NOMBRE 50

typedef char TNombre [MAX_NOMBRE];
typedef struct{
    float x, y, z;
}TCentro;

typedef struct{
    TNombre nombre;
    TCentro centro;
    float tamanyo;
}TArea;

typedef TArea TAreas [MAX_AREAS];

typedef struct{
    TAreas areas;
    int numAreas; // posiciones ocupadas
}TListaAreas;

void buscarProximas(TListaAreas lista, float x){
    for(int i = 0; i < lista.numAreas; i++){
        if(abs(lista.areas[i].centro.x - x) < 2){
            printf("%s\n", lista.areas[i].nombre);
        }
    }
}

float calcularAreaPromedio(TListaAreas lista){
    float total = 0;
    for(int i = 0; i < lista.numAreas; i++){
        total += lista.areas[i].tamanyo;
    }
    return total / lista.numAreas;
}

void mostrarAreas(TListaAreas lista){
    for(int i = 0; i < lista.numAreas; i++){
        printf("Nombre: %s, Coordenadas: (%.2f, %.2f, %.2f), Tamano: %.2f\n",
               lista.areas[i].nombre, lista.areas[i].centro.x,
               lista.areas[i].centro.y, lista.areas[i].centro.z,
               lista.areas[i].tamanyo);
    }
}

void ordenar(TAreas areas, int numAreas){
    TArea aux;
    for(int i = 1; i < numAreas; i++){
        for(int j = numAreas - 1; j >= i; j--){
            if(areas[j].tamanyo < areas[j-1].tamanyo){
                aux = areas[j];
                areas[j] = areas[j-1];
                areas[j-1] = aux;
            }
        }
    }
}

void ordenarAreas(TListaAreas *lista){
    TArea aux;
    for(int i = 1; i < lista->numAreas; i++){
        for(int j = lista->numAreas - 1; j >= i; j--){
            if(lista->areas[j].tamanyo < lista->areas[j-1].tamanyo){
                aux = lista->areas[j];
                lista->areas[j] = lista->areas[j-1];
                lista->areas[j-1] = aux;
            }
        }
    }
}


int main(){
    TListaAreas lista = {
            .areas ={
                {"area_1", {8, 10, 4}, 90},
                {"area_2", {3, 2, 1}, 23},
                {"area_3", {3, 2, 1}, 32}
            },
            .numAreas = 3
    };
    buscarProximas(lista, 4);
    mostrarAreas(lista);
    // se lo paso todo dentro de una estructura
    ordenarAreas(&lista);
    // le paso por separado el vector y el tamaño :)
    ordenar(lista.areas, lista.numAreas);
    printf("areas ordenadas\n");
    mostrarAreas(lista);

}


// ME LO APRENDO
// leemos hasta que meta un .
void leerCadena(TCadena cadena){
    int i;
    char leido;
    i = 0;
    do{
        scanf("%c", &leido);
        if(leido != '.'){
            cadena[i] = leido;
            i++;
        }
    }while(leido != '.' && i < TAM - 1);
    cadena[i] = '\0';
}

// buffer = "hola."
// cadena = NULL;

//  i = 0

//  leido = 'h'
//            0
//  cadena = | |
//  cadena = |h|
//  i = 1

//  leido = 'o'
//            0 1
//  cadena = |h| |
//  cadena = |h|o|
//  i = 2

// leido = 'l'
//            0 1 2
//  cadena = |h|o| |
//  cadena = |h|o|l|
//  i = 3

// leido = 'a'
//            0 1 2 3
//  cadena = |h|o|l| |
//  cadena = |h|o|l|a|
//  i = 4

// leido = '.'
//            0 1 2 3
//  cadena = |h|o|l|a|

//            0 1 2 3 4
//  cadena = |h|o|l|a|\0

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

// devuelvo una cadena con todas las letras minusculas.
char *extraerLetrasBad(TCadena cadena){
    char *letras = NULL;
    int i, cuantas;

    // I. primer bucle para ver cuantas letras tengo para poder saber de cuanto tengo
    // que crear el vector destino.
    i = 0;
    cuantas = 0;
    while(cadena[i] != '\0'){
        if(cadena[i] >= 'a' && cadena[i] <= 'z'){
            cuantas++;
        }
        i++;
    }

    // II. Creo el vector de caracteres destino con la cantidad de letras que me hacen falta.
    letras = (char *) malloc(sizeof(char) * (cuantas + 1)); // + 1 para el \0

    // III. otro bucle, para ahora si, guardar los caracteres en el destino.
    i = 0;
    cuantas = 0;
    while(cadena[i] != '\0'){
        if(cadena[i] >= 'a' && cadena[i] <= 'z'){
            letras[cuantas] = cadena[i]; // ahora cada letra lo guardo en el vector de letras.
            cuantas++;
        }
        i++;
    }
    letras[cuantas] = '\0';
    return letras;
}

// SUPER IMPORTANTE!!
char *extraerLetras(TCadena cadena){
    char *letras = NULL;
    int i, cuantas;
    i = 0;
    cuantas = 0;
    while(cadena[i] != '\0'){
        if(cadena[i] >= 'a' && cadena[i] <= 'z'){
            // añado una posicion mas a las que ya tenia.
            letras = (char *) realloc(letras, sizeof(char) * (cuantas + 1));
            // la guardo en el vector
            letras[cuantas] = cadena[i];
            cuantas++;
        }
        i++;
    }
    letras = (char *) realloc(letras, sizeof(char) * (cuantas + 1));
    letras[cuantas] = '\0';
    return letras;
}

#define M 9
#define N 9
typedef char TMatriz [M][N];

// poco eficiente pero easy!
void impPalabra(TMatriz matriz){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matriz[i][j] >= 'A' && matriz[i][j] <= 'Z'){
                printf("%c", matriz[i][j]);
            }
        }
    }
}

char *guardarPalabra(TMatriz matriz){
    char *cadena = NULL;
    int k = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] >= 'A' && matriz[i][j] <= 'Z'){
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

char *guardarPalabraB12(TMatriz matriz){
    char *nueva = NULL;
    int fil, col, incFil, incCol;
    int i, j, k;
    // I. Recorro por columnas para encontrar el primer caracter
    fil = -1;
    col = -1;
    for(j = 0; j < N && fil == -1; j++){
        for(i = 0; i < M && fil == -1; i++){
            if(matriz[i][j] >= 'A' && matriz[i][j] <= 'Z'){
                fil = i;
                col = j;
            }
        }
    }
    if(fil == -1){
        printf("No hemso encontrado ningun caracter mayuscula\n");
    }
    else{
        // II. Miro donde esta el segundo para saber la direccion hacia la que tengo que ir
        if(matriz[fil + 1][col] >= 'A' && matriz[fil + 1][col] <= 'Z'){
            incFil = 1;
            incCol = 0;
        }
        else{
            if(matriz[fil][col + 1] >= 'A' && matriz[fil][col + 1] <= 'Z'){
                incFil = 0;
                incCol = 1;
            }
            else{
                if(matriz[fil + 1][col + 1] >= 'A' && matriz[fil + 1][col + 1] <= 'Z'){
                    incFil = 1;
                    incCol = 1;
                }
                else{
                    incFil = -1;
                    incCol = 1;
                }
            }
        }
        // III. Avanzo en esa direccion hasta que se acabe la cadena.
        nueva = NULL;
        k = 0; // posicion por la que voy guardando en la cadena.
        i = fil;
        j = col;
        while(i < M && j < N && matriz[i][j] >= 'A' && matriz[i][j] <= 'Z'){
            nueva = (char *) realloc(nueva, sizeof(char) * (k + 1));
            nueva[k] = matriz[i][j];
            k++;
            i += incFil;
            j += incCol;
        }
        nueva = (char *) realloc(nueva, sizeof(char) * (k + 1));
        nueva[k] = '\0';
    }
    return nueva;
}

int main_matrices(){
    TMatriz matriz1 = {
        {'?', '*', '3', '*', '-', '*', '*', '*', '*'},
        {'*', '.', '.', '*', '*', '-', 'T', '*', '*'},
        {'@', '*', '1', '.', '*', 'S', '*', '*', '*'},
        {'7', '*', '*', '*', 'A', '.', '*', '-', '*'},
        {')', '*', '(', 'K', '*', '.', '.', '+', '*'},
        {'3', '*', '-', '*', '.', '*', '.', '*', '*'},
        {'?', '*', '-', '*', '3', '*', '*', '.', '-'}
    };
    char *resultado = guardarPalabraB12(matriz1);
    printf("%s\n", resultado);

    TMatriz matriz2 = {
        {'?', '*', '3', '*', '-', '*', '*', '*', '*'},
        {'*', '.', '.', '*', '*', '-', '.', '*', '*'},
        {'@', '*', '1', '.', '*', '.', '*', '*', '*'},
        {'7', '*', '*', '*', '.', '.', '*', '-', '*'},
        {')', '*', '(', 'K', 'A', 'S', 'T', '+', '*'},
        {'3', '*', '-', 'Y', 'X', '*', '.', '*', '*'},
        {'?', '*', '-', 'Y', '3', 'X', '*', '.', '-'}
    };
    resultado = guardarPalabraB12(matriz1);
    printf("%s\n", resultado);
}


// la base para cambiar 0 por 8 => invertir(1230) => 8321
void invertirAndChange(int n, int *invertido){
    if(n < 10){
        if(n == 0){
            *invertido = *invertido * 10 + 8;
        }
        else{
            *invertido = *invertido * 10 + n;
        }
    }
    else{
        if(n % 10 == 0){
            *invertido = *invertido * 10 + 8;
        }
        else{
            *invertido = *invertido * 10 + n % 10;
        }
        invertirAndChange(n / 10, invertido);
    }
}

// cambia todas las veces que aparece el nuevo por el viejo.
// printf("%d\n", examen(1323, 3, 5, 0);
int examen(int n, int viejo, int nuevo, int res){
    if(n < 10){
        if(n == viejo){
            res = res * 10 + nuevo;
        }
        else{
            res = res * 10 + n;
        }
    }
    else{
        if(n % 10 == viejo){
            res = res * 10 + nuevo;
        }
        else{
            res = res * 10 + n % 10;
        }
        res = examen(n / 10, viejo, nuevo, res);
    }
    return res;
}


// printf("%d\n", divisores(8, 1));
int divisores(int n, int divisor){
    if(n == divisor){
        return 1;
    }
    else{
        if(n % divisor == 0){
            return 1 + divisores(n, divisor + 1);
        }
        else{
            return divisores(n, divisor + 1);
        }
    }
}


// invertirGPT
int invertirGPT(int n, int resultado){
    if(n < 10){
        if(n == 0){
            resultado = resultado * 10 + 8;
        }
        else{
            resultado = resultado * 10 + n;
        }
    }
    else{
        if(n % 10 == 0){
            resultado = resultado * 10 + 8;
        }
        else{
            resultado = resultado * 10 + n % 10;
        }
        resultado = invertirGPT(n / 10, resultado);
    }
    return resultado;
}
/*
    igpt(n = 1234, resultado = 0)
        resultado = igpt(123, 0*10 + 4)
        return 4321

    igpt(n = 123, resultado = 4)
        resultado = igpt(12, 4*10 + 3)
        return 4321

    igpt(n = 12, resultado = 43)
        resultado = igpt(1, 43*10 + 2)
        ----
        resultado = 4321
        return 4321


    igpt(n = 1, resultado = 432)
        resultado = 432*10 + 1

        return 4321




*/
void invertir(int n, int *invertido){
    if(n < 10){
        *invertido = *invertido * 10 + n;
    }
    else{
        *invertido = *invertido * 10 + n % 10;
        invertir(n / 10, invertido);
    }
}




// !!!!!!!!!!!MODIFICACION PARA QUE DEVUELVA EL MISMO NUMERO PERO CAMBIANDO LOS 0 POR 8!!!!
int igual(int n){
    int res;
    if(n < 10){
        res = n % 10;
    }
    else{
        res = igual(n/10) * 10 + n % 10;
    }
    return res;
}

int main_numero(){
    int numeroInvertido = 0;

    invertir(1245, &numeroInvertido);
    printf("\n%d\n", numeroInvertido);

    int resultado;
    resultado = igual(1234);
    printf("\n%d\n", resultado);


    return 0;
}



int main_matriz_examen(){
    TMatriz matriz = {
        {'?', '*', '3', '*', '-', '*', '*', '*', '*'},
        {'*', '.', 'P', '*', '*', '-', '*', '*', '*'},
        {'@', '*', '1', 'A', '*', '<', '*', '*', '*'},
        {'7', '*', '*', '*', 'T', '.', '*', '-', '*'},
        {')', '*', '(', '*', '*', 'A', '.', '+', '*'},
        {'3', '*', '-', '*', 'v', '*', 'T', '*', '*'},
        {'?', '*', '-', '*', '3', '*', '*', 'A', '-'}
    };
    impPalabra(matriz);
    char *resultado = guardarPalabra(matriz);
    printf("%s\n", resultado);
    free(resultado);
}


int main_cadenas(){
    TCadena cadena;
    printf("Introduce una cadena de caracteres (maximo %d): ", TAM);
    leerCadena(cadena);
    printf("[%s]", cadena);

    char *cadDin;
    printf("Introduce una cadena de caracteres (no hay maximo): ") ;
    cadDin = leerCadenaDinamica();
    printf("%s\n", cadDin);

    free(cadDin);
    return 0;
}
