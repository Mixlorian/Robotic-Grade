#include <stdio.h>

typedef enum {PIRAMIDE, CUADRADO} TFigura;
/*
Figura (0 = PIRAMIDE, 1 = CUADRADO): 3
Figura (0 = PIRAMIDE, 1 = CUADRADO): 1
N: -2
N: 7
*******
*     *
*     *
*******
*     *
*     *
*******
¿Quieres dibujar otra figura (s/n)? x
¿Quieres dibujar otra figura (s/n)? s
Figura (0 = PIRAMIDE, 1 = CUADRADO): 0
N: 4
*******
 *****
  ***
   *
¿Quieres dibujar otra figura (s/n)? n
adios.
*/
TFigura pedirFigura(){
    TFigura leida;
    do{
        printf("Figura (0 = PIRAMIDE, 1 = CUADRADO): ");
        scanf("%u", &leida);
    }while(leida != PIRAMIDE && leida != CUADRADO);
    return leida;
}

// pide el numero de lineas debe ser un numero positivo
// si no lo volvera a pedir.

int pedirN(){
    int n;
    do{
        printf("N: ");
        scanf("%d", &n);
    }while(n < 0);
    return n;
}

// imprime por pantalla n veces c
// impNC(4, '*') => ****
void impNC(int n, char c){
    for(int i = 1; i <= n; i++){
        printf("%c", c);
    }
}
// n = 4
/*              espacios            *
*******         0                   7
 *****          1                   5
  ***           2                   3
   *            3                   1
*/
// llamando a la funcio para generar la linea.
void imprimirPiramide(int n){
    int asteriscos = 2 * n - 1;

    for(int linea = 1; linea <= n; linea++){ // linea = 1, 2, 3, 4
        impNC(linea - 1, ' ');
        impNC(asteriscos, '*');
        printf("\n");
        asteriscos -= 2;
    }

}

/*
*******     linea = 1
*     *
*     *
*******     linea = 4
*     *
*     *
*******     linea = 7 = n
*/
void imprimirCuadrado(int n){
    int linea;
    for(linea = 1; linea <= n; linea++){
        if(linea == 1 || linea == n || linea == n/2 + 1){
            impNC(n, '*');
        }
        else{
            printf("*");
            impNC(n - 2, ' ');
            printf("*");
        }
        printf("\n");
    }
}
// en funcion de la figura llama al imprimr de una figura u otra.
void imprimirFigura(TFigura f, int n){
    switch(f){
    case PIRAMIDE:
        imprimirPiramide(n);
        break;
    case CUADRADO:
        imprimirCuadrado(n);
        break;
    }
}

int main(){
    TFigura figura;
    int n;

    figura = pedirFigura();
    n = pedirN();
    imprimirFigura(figura, n);

    return 0;
}



/*
#include <stdio.h>
// EJERCICIO 3.
// Esta funcion pide 3 valores positivos al usuario
// que deben ser distintos entre si y mayores que 0.¡'''''
// Ejemplo de ejecucion.
// Introduce 3 valores: 2 3 -2
// Introduce 3 valores: 3 4 4
// Introduce 3 valores: 5 1 9
void pedir3(int *a, int *b, int *c){
    // Aqui tu codigo
    do{
        printf("Introduce 3 valores: ");
        scanf("%d %d %d", a, b, c); // scanf("%d %d %d", &n1, &n2, &n3);
    }while(*a < 0 || *b < 0 || *c < 0 || *a == *b || *b == *c || *a == *c);
}
// pedir3(&n1, &n2, &n3); => pedir3(a = &n1, b = &n2, c = &n3)


// Analiza lo que hace esta funcion!
// - Recibe dos variables!!
//      Intercambia esas dos variables si la primera es menor que la segunda.
void swap(int *v1, int *v2){
    int aux;
    if(*v1 < *v2){
        aux = *v1;
        *v1 = *v2;
        *v2 = aux;
    }
}

//    int n1 = 20, n2 = 23;
//    swap(&n1, &n2);
//    printf("%d %d\n", n1, n2);


// Ordena las variables de menor a mayor.
// usando la funcion anterior
void ordenar3(int *a, int *b, int *c){
    // aqui tu codigo
}
//
int main(){
    // aqui tu codigo.


}
*/

/*
// EJERCICIO 2. Completa las siguientes funciones
// Funcion que lee un valor positivo
// introducido por el usuario y devuelve dicho
// valor.
int leerPositivoIndice(int i){
    int leido;
    do{
        printf("Introduce un valor positivo (%d): ", i);
        scanf("%d", &leido);
    }while(leido < 0);
    return leido;
}
int leerPositivo(){
    int leido;
    do{
        printf("Introduce un valor positivo: ");
        scanf("%d", &leido);
    }while(leido < 0);
    return leido;
}
void sumar_dir(int a, int b, int *s){
    *s = a + b;
}
// Realiza el main para que llamando a la funcion
// anterior, leas dos valores positivos y muestres
// la suma por pantalla. Para realizar la suma
// debes usar la funcion sumar_dir aqui definida
int main(){
    int valor1, valor2, sumaTotal;    
    // Aqui tu codigo.
    valor1 = leerPositivoIndice(1);
    valor2 = leerPositivoIndice(2);
    sumar_dir(valor1, valor2, &sumaTotal);
    printf("%d + %d = %d\n", valor1, valor2, sumaTotal);
    return 0;
}
*/

/*
// EJERCICIO 1. INDICA LA SALIDA POR PANTALLA.
// NO LO EJECUTES PRIMERO HAZTE UNA TRACITA BROOH.
#include <stdio.h>
void f(int *s, int valor){
    *s += valor;
}
int main(){
    int *p, *q, *r;
    int a, b;
    a = 12;
    b = 32;

    p = &a;
    q = p;
    *q = *p + 12;
    f(q, *p);
    b = *p + *q;
    r = p;
    p = &b;
    *p = *r + *q;
    printf("%d %d %d %d %d %d\n",
           *p, *q, *r, a, b);
    f(p, *q);
    printf("%d %d\n", a, b);
}
*/
