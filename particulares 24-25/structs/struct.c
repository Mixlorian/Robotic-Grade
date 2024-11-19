#include <stdio.h>

typedef struct {
    int x,y;
}Punto;

typedef Punto VectorPuntos [10];

int main_1(){
    Punto p1,p2;

    p1.x = 12;
    p1.y = 34;
    p2.x = p1.x + 10;
    p2.y = p1.y * 2;

    printf("(%d, %d) (%d, %d)\n",p1.x,p1.y, p2.x,p2.y);


    return 0;
}


typedef struct{
    int capacidad, litros;
}Deposito;

// vector de 5 depositos!
int main(){
    Deposito depositos[5];
    Deposito leido = {0, 0};

    // queremos que el usuario introduzca la capacidad de 5 depositos
    // si es negativa o supera el valor de 100 la volvera a pedir.
    // los litros incialmente son 0.

    for(int i = 0; i < 5; i++){
        //
        do{
            printf("Introduce capacidad del deposito %d: ", i);
            scanf("%d", &leido.capacidad);
        }while(leido.capacidad < 0 || leido.capacidad > 100);
        depositos[i] = leido; //se hace copia bit a bit.
    }

    for(int i = 0; i < 5; i++){
        //
        do{
            printf("Introduce capacidad del deposito %d: ", i);
            scanf("%d", &depositos[i].litros);
        }while(depositos[i].litros > depositos[i].capacidad || depositos[i].litros < 0);
    }

    for(int i = 0; i < 5; i++){
        printf("litros: %d / capacidad: %d", depositos[i].capacidad, depositos[i].litros);
    }

    int total_vertido;
    

    return 0;;
}