#include <stdio.h>
#include <stdlib.h>


char *strcopy(char *org){
    char* cadena = NULL;
    int i;
    cadena = (char *) malloc(sizeof(char)*(strlen(org) + 1));
    i = 0;
    while(cadena[i] != '\0'){
        cadena[i] = org[i];
        i++;
    }
    cadena[i] = '\0';
    return cadena;
}