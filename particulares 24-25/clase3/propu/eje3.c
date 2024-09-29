#include <stdio.h>

int main(){
    int edad;

    printf("Escriba su edad:");
    scanf("%d",&edad);
    if(edad >= 0 && edad <= 12){
        printf("nino");
    }else{
        if(edad >= 13 && edad <= 17){
            printf("adolescente");
        }else{
            if(edad >= 18 && edad <= 64){
                printf("mayor");
            }else{
                printf("adulto mayor");
            }
        }
    }
    return 0;
}