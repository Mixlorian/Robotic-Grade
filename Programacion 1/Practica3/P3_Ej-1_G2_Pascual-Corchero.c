#include <stdio.h>

#define SCargado '#'
#define SVacio '-'

int main(){

    int bateria,SC,SV,i;

    do
    {
        printf("Introduce el nivel de carga de la bateria (0-100%%):");
        scanf("%d",&bateria);
        if(bateria < 0 || bateria > 100){
            printf("Por favor, introduce un valor entre 0 y 100.\n");
        }
    } while (bateria < 0 || bateria > 100);
    
    SC = bateria / 10;
    printf("|");
    for(i=0; i < SC ;i++){
        printf("%c",SCargado);
    }
    SV = 10 - SC;
    for(i=0; i < SV ; i++){
        printf("%c",SVacio);
    }
    printf("|%d%%",bateria);

    return 0;
}