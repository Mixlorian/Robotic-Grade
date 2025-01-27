#include <stdio.h>
#define KROBOTS 5
#define ALTO_MAPA 20
#define ANCHO_MAPA 20

typedef struct{
    int x, y;
}TPosicion;

typedef enum{
    NORTE,
    SUR,
    ESTE,
    OESTE
}TDireccion;

typedef struct{
    char id;
    TPosicion posicion;
    TDireccion direccion;
    int unidades;
}TRobot;

typedef TRobot TRobots [KROBOTS];

typedef struct{
    TRobots robots;
    int numRobots;
}TGrupoRobots;

void leerRobots(TGrupoRobots *grupo);
void moverRobots(TGrupoRobots *grupo);
void imprimirRobots(TGrupoRobots grupo);

int main(){
    TGrupoRobots robots = {
                           {     //x  y
                            {'A', {8, 12}, ESTE, 2},
                            {'B', {5, 12}, ESTE, 5},
                            {'C', {3, 12}, OESTE, 2}
                           }
                           , 3};

    // leerRobots(&robots);
    moverRobots(&robots);
    imprimirRobots(robots);

    return 0;
}

void leerRobot(TRobot *robot, int n){
    printf("Introduce posicion inicial (x, y) del robot %d: ", n);
    scanf("%d %d", &robot->posicion.x, &robot->posicion.y);
    printf("Introduce direccion de movimiento del robot %d  (0-Norte 1-Sur 2-Este 3-Oeste): ", n);
    scanf("%u", &robot->direccion);
    printf("Introduce unidades de movimiento del robot %d: ", n);
    scanf("%d", &robot->unidades);
}

void leerRobots(TGrupoRobots *grupo){
    char letra = 'A';
    do{
        printf("Introduce el numero de robots (hasta 10): ");
        // acceso a campo de una estructura si tengo su direccion.
        scanf("%d", &grupo->numRobots);
    }while(grupo->numRobots < 0 || grupo->numRobots > 10);
    for(int i = 0; i < grupo->numRobots; i++){
        leerRobot(&grupo->robots[i], i);
        grupo->robots[i].id = letra;
        letra++;
    }
}

void moverRobot(TRobot *robot){
    int row_dest, col_dest;
    switch(robot->direccion){
        case NORTE:
            row_dest = robot->posicion.y - robot->unidades;
            col_dest = robot->posicion.x;
            break;
        case SUR:
            row_dest = robot->posicion.y + robot->unidades;
            col_dest = robot->posicion.x;
            break;
        case ESTE:
            col_dest = robot->posicion.x + robot->unidades;
            row_dest = robot->posicion.y;
            break;
        case OESTE:
            row_dest = robot->posicion.y;
            col_dest = robot->posicion.x - robot->unidades;
            break;
    }
    if(row_dest >= 0 && row_dest < ALTO_MAPA && col_dest >= 0 && col_dest < ANCHO_MAPA){
        robot->posicion.x = col_dest;
        robot->posicion.y = row_dest;
    }
}

void moverRobots(TGrupoRobots *grupo){
    for(int i = 0; i < grupo->numRobots; i++){
        moverRobot(&grupo->robots[i]);
    }
}

void printRobot(TRobot robot){
    printf("El robot %c se movera a la posicion (%d, %d)\n",
           robot.id, robot.posicion.x, robot.posicion.y);

}

bool colisionan(TRobot r1, TRobot r2){
    return r1.posicion.y == r2.posicion.y &&
           r1.posicion.x == r2.posicion.x;
}

void imprimirColisiones(TGrupoRobots grupo){
    for(int i = 0; i < grupo.numRobots; i++){
        for(int j = i + 1; j < grupo.numRobots; j++){
            if(colisionan(grupo.robots[i], grupo.robots[j])){
                printf("El robot %c y el %c COLISIONARÁN!!!\n", grupo.robots[i].id, grupo.robots[j].id);
            }
        }
    }
}

void rellenarMatriz(TGrupoRobots grupo, char matriz[][ANCHO_MAPA]){

}

void imprimirRobots(TGrupoRobots grupo){
    char car;
    for(int i = 0; i < grupo.numRobots; i++){
        printRobot(grupo.robots[i]);
    }
    imprimirColisiones(grupo);
    for(int i = 0; i < ALTO_MAPA; i++){
        for(int j = 0; j < ANCHO_MAPA; j++){
            car = '.';
            for(int k = 0; k < grupo.numRobots && car != '#'; k++){
                // ***
                if(grupo.robots[k].posicion.x == j && grupo.robots[k].posicion.y == i){
                    if(car == '.'){
                        car = grupo.robots[k].id; // aqui entro con el primero
                    }
                    else{
                        car = '#'; // aqui entro con el resto!!
                    }
                }
            }
            printf("%c ", car);
        }
        printf("\n");
    }
    // **
/*
    i   j   k   robots[k].posicion.x, robots[k].posicion.y
    ------------------
    0   0   0   10,12
    0   0   1   10,12
    0   0   2   1,12
    ------------------
    ...
    ------------------
    12   1  0   10,12   car = '.'
    12   1  1   10,12   car = '.'
    12   1  2   1,12    car = 'C'
    ------------------
    ...
    ------------------
    12  10  0   10,12   car = 'A'
    12  10  1   10,12   car = '#'
    12  10  2   10,12
    ------------------
    ...
    ------------------

*/

}



