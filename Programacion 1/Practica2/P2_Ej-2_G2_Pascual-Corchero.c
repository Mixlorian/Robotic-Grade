#include <stdio.h>

int main(){

    int n1,n2,aux;

    printf("escribe 2 numeros:");
    scanf("%d %d",&n1,&n2);

    if(n1 > n2){
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    printf("Estos son los 2 numeros en orden creciente: %d %d",n1,n2);

    return 0;
}