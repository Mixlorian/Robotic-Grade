#include <stdio.h>
#include <time.h>
#define Max_Rango 5

int main(){
    srand(time(NULL));

    int NumRandom,NumUsu,robotDestru;
    int numIntento = 1;

    NumRandom = (rand() % Max_Rango) +1;

    do
    {
        printf("Intento %d: Seleccione un interruptor(1-5):",numIntento);
        scanf("%d",&NumUsu);
        if(NumRandom != NumUsu){
            printf("Incorrecto!\n");
            numIntento++;
        }else{
            printf("Robot salvado!");
        }
        if(numIntento > 3){
            printf("Robot Destruido!");
            break;
        }

    } while (NumRandom != NumUsu);
    

    return 0;
}