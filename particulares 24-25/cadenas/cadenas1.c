#include <stdio.h>
#define KCONTADORES 5
#define KTAM 50

typedef char TCAdena [KTAM];
typedef int TContadores [KCONTADORES];

void contarVocales(TCAdena cadena, TContadores contadores){
    int i;

    for(i = 0; i <KCONTADORES; i++){contadores[i]=0;}
    
    i = 0;
    while(cadena[i] != '\0'){
        switch (cadena[i])
        {
        case 'a':
        case 'A':
            contadores[0]++;
            break;
        case 'e':
        case 'E':
            contadores[1]++;
            break;
        case 'i':
        case 'I':
            contadores[2]++;
            break;
        case 'o':
        case 'O':
            contadores[3]++;
            break;
        case 'u':
        case 'U':
            contadores[4]++;
            break;

        default:
            break;
        }
        i++;
    }
}

void mostrarRepeticiones(int cx[],int cy[], int cuantasCoords){
    int veces;
    for(int i = 0; i < cuantasCoords; i++){
        veces = 1;
    }
}