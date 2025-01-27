/*
    Ejercicio 4. Enero 2024

productos.txt
=====================================================
3
101 camiseta 19.99 2 proveedor1 proveedor2
202 pantalón 29.99 3 proveedor3 proveedor4 proveedor5
303 gorra 9.99 1 proveedor1
=====================================================
*/
#include <stdio.h>
#include <stdlib.h>
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

typedef struct{
    TProducto *productos;
    int numProductos;
}TListaProductos;
/*
=====================================================
productos.txt
=====================================================
3
101 camiseta 19.99 2 proveedor1 proveedor2
202 pantalón 29.99 3 proveedor3 proveedor4 proveedor5
303 gorra 9.99 1 proveedor1
=====================================================
*/

int main_producto(){
    TProducto leido;
    FILE *file;
    TListaProductos lista;
    lista.numProductos = 0;
    lista.productos = NULL;
    file = fopen("productos.txt", "r");
    if(file != NULL){
        fscanf(file, "%d", &lista.numProductos);
        lista.productos = (TProducto *) malloc(sizeof(TProducto) * lista.numProductos);
        for(int i = 0; i < lista.numProductos; i++){
            // leo el producto y lo almacen en TProducto
            // leo codigo
            fscanf(file, "%d", &leido.codigo);
            // leo cadena (sin espacios)
            fscanf(file, "%s", leido.nombre);
            // leo un real
            fscanf(file, "%f", &leido.precio);
            // leo un entero (tam)
            fscanf(file, "%d", &leido.numProveedores);
            // creo un vector con este tam
            leido.proveedores = (TNombreProveedor *) malloc(sizeof(TNombreProveedor) * leido.numProveedores);
            // los siguientes elementos (leo tam elementos)
            // van en el vector!!
            for(int j = 0; j < leido.numProveedores; j++){ // las cadenas que me quedan por leer en esta linea :)
                fscanf(file, "%s", leido.proveedores[j]);
            }
            lista.productos[i] = leido;
        }
        fclose(file);
        // ===================================================
        // PROPUESTO
        // ===================================================
        // IMPRIME LOS PRODUCTOS POR PANTALLA (EN EL FORMATO DE ABAJO)
        // ===================================================

    }
    return 0;
}

/*
=====================================================
PROPUESTO
=====================================================
productos.txt
=====================================================
3
101 camiseta 19.99 proveedor1 proveedor2 <fin>   =========> leo una cadena y si no es "<fin>" la tendria que guardar en el vector de proveedores.
202 pantalón 29.99 proveedor3 proveedor4 proveedor5 <fin>
303 gorra 9.99 <fin>
=====================================================
*/


// funcion recursiva que comprueba si los caracteres que ocupan posiciones impares de ambas cadenas
// desde la posicion i pasada como parametro son iguales:
//          0123456789
//  cad1 = "acfg rtasn\0
//  cad2 = "acfg rtasn\0

//         01234
// cad1 = "acfg"
// cad2 = "adfghdafda"

//         iiiii
//         012345
// cad1 = "acfgKK"
// cad2 = "adfhr"

bool igualesImpares(char cad1[], char cad2[], int i){
    bool son;
    if(cad1[i] == '\0' || cad2[i] == '\0'){ // he ido recorriendo la cadena y no he encontrado ninguno distinto
        son = true;
    }
    else{
        if(i % 2 != 0){// si es impares
            if(cad1[i] == cad2[i]){
                son = igualesImpares(cad1, cad2, i + 1);
            }
            else{
                son = false;
            }
        }
        else{
            son = igualesImpares(cad1, cad2, i + 1);
        }
    }
    return son;
}
/*
gmc(cadena = "ABED", i = 0)
    mayor = gmc("ABED", 1)
    ----------------------
    mayor = 'E'
    return 'E'
gmc(cadena = "ABED", i = 1) => 'E'
    mayor = gmc("ABED", 2)
    ----------------------
    mayor = 'E'
    return 'E'
gmc(cadena ="ABED", i = 2) => 'E'
    mayor = gmc("ABED", 3)
    ------------------------------
    mayor = 'D'
    mayor = 'E'
    return 'E'
gmc(cadena ="ABED", i = 3) => 'D'
    mayor = gmc("ABED", 4)
    ----------------------
    mayor = '\0'
    mayor = 'D'
    return 'D'
gmc(cadena ="ABED", i = 4)
    mayor = '\0'
    return '\0'
*/
// iiiii
// 01234
// ACBD\0
// * Devuelve el mayor caracter encontrado desde la posicion i hasta el final de la cadena.
char getMayorCaracter(char cadena[], int i){
    char mayor;
    if(cadena[i] == '\0'){
        mayor = '\0';
    }
    else{
        mayor = getMayorCaracter(cadena, i + 1);
        if(cadena[i] > mayor){
            mayor = cadena[i];
        }
    }
    return mayor;
}

////////////////////////////////////////////////////////////////////////////
// PROPUESTA (PISTA CUANDO NO TE SALGA PIENSA EN COMO FUNCIONA LA DE ARRIBA)
////////////////////////////////////////////////////////////////////////////
// Devuelve la primera posicion del caracter buscado desde la posicion i
// -1 si no aparece.
int buscarCaracterRecursiva(char cad[], int i, char buscado){
    int pos;


    return pos;
}

// ESTUDIAR Y ANALIZAR LA FUNCION
// cmpRecursivo("ABC", "ABC", 0)
// cmpRecursovi("ABXRCE", "ABCRC", 0) // devuelve 'X' - 'C'

//                  i        i
// cmpRecursivo("ABCDR", "ABC", 0) devuelve mayor que 0 porque ABCDR va despues que ABC
/*
< 0 si cad1 < cad2
> 0 si cad1 > cad2
= 0 si cad1 = cad2
*/
// si no voy a modificar las cadenas puedo poner const, para luego desde el main pasar literales cadena "esto es un literal"
int cmpRecursivo(const char cad1[], const char cad2[], int i){
    int r;
    if(cad1[i] == '\0' || cad2[i] =='\0'){
        r = cad1[i] - cad2[i];
    }
    else{
        if(cad1[i] == cad2[i]){ // los caracteres que son iguales no deciden... tengo que pasar al siguiente
            r = cmpRecursivo(cad1, cad2, i + 1);
        }
        else{
            r = cad1[i] - cad2[i];
        }
    }
    return r;
}
int main_recursivas(){
    printf("%d\n", cmpRecursivo("ABC", "ABC", 0));
    printf("%d\n", cmpRecursivo("ABXRCE", "ABCRC", 0)); // devuelve 'X' - 'C'
    return 0;
}

#include <string.h>
// crea una cadena con el mismo contenido que la cadena que me pasan como parametro.
char* strdup(const char *cad){
    int tam;
    char *nueva = NULL;

    tam = strlen(cad);
    nueva = (char *) malloc(sizeof(char) * (tam + 1));
    for(int i = 0; i < tam + 1; i++){ // porque asi ya copio el \0
        nueva[i] = cad[i];
    }
    return nueva;
}

// PROPUESTO INTERESNATE ES NO RECORRER LA CADENA CAD MAS DE UNA VEZ
// => NO PUEDES UTILIZAR STRLEN, NO PUEDES RECURROR LA CADENA CAD INICIALMENTE PARA SABER CUANTOS CHARS TIENE.

// PROPUESTO!!!
// añade al final de la cad2 la cad1.
void strcat_b12(char *cad1, const char *cad2){

}

//     k        i
//         0123
// cad1 = "hola"
// res[0] = cad1[0]
// res[1] = cad1[1]
// res[2] = cad1[2]
// res[3] = cad1[3]

// cad2 = "pepe"
// res[4] = cad2[0]
// res[5] = cad2[1]
// res[6] = cad3[2]
// res[7] = cad4[3]

// res[8] = '\0'

// devuelve una cadena nueva con el contenido de cad1 y el contenido de cad2
char *join_chars(const char *cad1, const char *cad2){
    char *res;
    int tam1, tam2, i, k;

    tam1 = strlen(cad1);
    tam2 = strlen(cad2);
    res = (char *) malloc(sizeof(char) * (tam1 + tam2 + 1));

    // recorro la cad1 y la copio en res
    k = 0;
    for(int i = 0; i < tam1; i++){
        res[k] = cad1[i];
        k++;
    }
    // recorro la cad2 y la copio en res
    for(int i = 0; i < tam2; i++){
        res[k] = cad2[i];
        k++;
    }
    res[k] = '\0';

    return res;
}

// devuelve la cad y su inversa en la misma cadena
// cad = "hola"
// devuleva "holaaloh"
char *join_pal(const char *cad){

}

// Crea una cadena nueva con el resultado de concatenera n veces el caracter cad1
// ncad("hose", 3) => "hosehosehose"
char *ncad(const char *cad1, int n){
    char *res;

    return res;
}

// Devuelve una cadena donde se han borrado todas las veces que aparece el caracter c de la cadena cad
//      - puediendo recorrer la cadena mas de una vez.
//      - no recorrer la cadena mas de una vez.
char *borrar(char *cad, char c){

}

int main(){

    return 0;
}




