#include <stdio.h>

typedef enum {Carne = 1, Verdura = 2, Pan = 3} TAlimento;
typedef enum {AsadoLento,AsadoRapido,CoccionVapor,
                VaporRapido,Horneado,Preca,Estandar} TModo;

int main(){

    int cant,temp;
    TAlimento alimento;
    TModo modo;

    printf("Introduce el tipo de alimento (1-Carne, 2-Verdura, 3-Pan): ");
    scanf("%u",&alimento); 
    printf("Introduce la cantidad de alimento en gramos: ");
    scanf("%d",&cant);
    printf("Introduce la temperatura inicial del alimento en C: ");
    scanf("%d",&temp);

    switch (alimento)
    {
    case Carne:
        if(cant >= 300){
            if(temp < 5){
                modo = AsadoLento;
            }else{
                modo = AsadoRapido;
            }
        }
        break;
    case Verdura:
        if(cant < 200){
            if(temp > 10){
                modo = VaporRapido;
            }else{
                modo = CoccionVapor;
            }
        }
        break;
    case Pan:
        if(cant > 400 && temp < 15){
            modo = Preca;
        }else{
            modo = Horneado;
        }
        break;
            
    default:
        modo = Estandar;
        break;
    }

    switch (modo)
    {
    case AsadoLento:
        printf("Modo Asado Lento seleccionado.");
        break;
    case AsadoRapido:
        printf("Modo Asado Rapido seleccionado.");
        break;
    case VaporRapido:
        printf("Modo Vapor Rapido seleccionado.");
        break;
    case CoccionVapor:
        printf("Modo Coccion al Vapor seleccionado");
        break;
    case Preca:
        printf("Modo Horneado con Precalentamiento seleccionado.");
        break;
    case Horneado:
        printf("Modo Horneado seleccionado.");
        break;
    case Estandar:
        printf("Modo Estandar de Coccion");
        break;
    }


    return 0;
}