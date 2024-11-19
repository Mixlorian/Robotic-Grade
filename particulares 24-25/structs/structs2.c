#include <stdio.h>

typedef char TCadena [50];

typedef struct{
    int row, col;
}Coordenada;

typedef struct{
    Coordenada coords;
    TCadena matricula;
}Robot;

int main(){
    Robot robots[5];
    Coordenada leida;

    // leer los robots
    // Introduce la matricula para el rabot 0:
    // Introduce la posicion, fila y columna separados por un espacio para el rabot 0: -2 3
    // Introduce la posicion, fila y columna separados por un espacio para el rabot 0: 4 3

    for(int i = 0; i < 5; i++){
        printf("Introduce la matricula para el rabot %d:", i);
        scanf("%s", robots[i].matricula);
        do{     
            printf("Introduce la posicion, fila y columna separados por un espacio para el rabot %d:",i);
            scanf("%d %d",leida.col,leida.row);
        } while (leida.col < 0 ||leida.row < 0);
        robots[i].coords = leida;
    }
    for(int i = 0; i < 5; i++){
        printf("%s (%d,%d)",robots[i].matricula, robots[i].coords.col,robots[i].coords.row);
    }
    return 0;
}