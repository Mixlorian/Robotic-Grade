#include <stdio.h>

typedef enum{triangulo = 1, cuadrado = 2, circulo = 3} TForma;
int main(){

    float base, altura,lado,radio;
    TForma figura;

    printf("Figura [1 para triangulo rectangulo, 2 para cuadrado,3 para circulo]:");
    scanf("%u",&figura);
    if(figura <= 0 || figura >3){
        printf("error");
    }


    printf("base:");
    scanf("%d",&base);
    if(base < 0){
        printf("error");
    }
    printf("altura:");
    scanf("%d",&altura);
    if(altura < 0){
        printf("error");
    }



    switch (figura)
    {
    case triangulo:
        printf("base:");
        scanf("%d",&base);
        if(base < 0){
            printf("error");
        }else{
            
        }
        break;
    case cuadrado:
        /* code */
        break;
    case circulo:
        /* code */
        break;
    
    default:
        break;
    }
    return 0;
}