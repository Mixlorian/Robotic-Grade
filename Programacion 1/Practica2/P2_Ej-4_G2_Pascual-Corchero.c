#include <stdio.h>

typedef enum {Rocoso = 1, Arenoso = 2, Montanoso = 3} TTerreno;


int main(){

    TTerreno terreno;
    int velo,visi;

    printf("Introduce el tipo de terreno (1-Rocoso, 2-Arenoso, 3-Montanoso): ");
    scanf("%u",&terreno);
    printf("Introduce la velocidad del viento en km/h: ");
    scanf("%d",&velo);
    printf("Introduce la visibilidad en porcentaje (0-100): ");
    scanf("%d",&visi);

    switch (terreno)
    {
    case Rocoso:
        if(velo < 40){
            printf("Modo Explotacion Lenta seleccionado");
        }else{
            printf("Modo Operacion Estandar seleccionado");
        }
        break;
    case Arenoso:
        if(visi < 30){
            if(velo > 50){
                printf("Modo Suspension Total seleccionado");
            }else{
                printf("Modo Suspension seleccionado");
            }
        }else{
            printf("Modo Operacion Estandar seleccionado");
        }
        break;
    case Montanoso:
        if(visi > 70){
            if(velo > 60){
                printf("Modo Precaucion seleccionado");
            }else{
                printf("Modo Escalada seleccionado");
            }
        }else{
            printf("Modo Operacion Estandar seleccionado");
        }
        break;   
    default:
        printf("Tipo de terreno no reconocido seleccionado");
        break;
    }

    return 0;
}