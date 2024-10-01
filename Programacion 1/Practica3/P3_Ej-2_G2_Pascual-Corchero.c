#include <stdio.h>


int main(){

    int NumPuntos, NumPaquetes;

    printf("Cuantos puntos de entrega tiene asignados el robot? ");
    scanf("%d",&NumPuntos);

    for(int i = 1 ; i <= NumPuntos ; i++){
        printf("-- Punto %d --\n",i);
        printf("Cuantos paquetes entrega en este punto? ");
        scanf("%d",&NumPaquetes);
        for(int a = 1; a <= NumPaquetes; a++){
            printf("Entregando paquete...\n");
            if(a == 3 && a != NumPaquetes){
                printf("Verificando bateria...\n");
            }
        }
    }
    
    return 0;
}