#include <stdio.h>

typedef enum {tornillo = 1, clavo = 2, tuerca = 3} TPieza;

int main(){

    TPieza Pieza = 0;

    printf("Introduce el tipo de pieza (1-Tornillo, 2-Clavo, 3-Tuerca):");
    scanf("%u",&Pieza);

    switch (Pieza)
    {
    case tornillo:
        printf("Seleccionar destornillador");
        break;
    case clavo:
        printf("Seleccionar martillo");
        break;
    case tuerca:
        printf("Seleccionar llave");
        break;
        
    default:
        printf("Pieza desconocida");
        break;
    
        break;
    }
    return 0;
}