#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUMERO_ROBOTS 10 

typedef enum {NORTE, SUR, ESTE, OESTE} TDireccion;

typedef struct {
    int x;
    int y;
} TPosicion;

typedef struct {
    TPosicion posicion;
    TDireccion direccion;
    int distanciaMovimiento;
} TRobot;

typedef struct {
    TRobot robots[MAX_NUMERO_ROBOTS];
    int numRobots;
} TGrupoRobots;

// Prototipos de las funciones:
void inicializarRobots(TGrupoRobots* grupo);
void moverRobots(TGrupoRobots* grupo);
void mostrarPosicionesFinales(TGrupoRobots grupo);
void verificarColisiones(TGrupoRobots grupo);
void leerDatosRobot(TRobot *, int);
TDireccion leerDireccion(int);
void calcularSiguientePosicion(int*, int*, TDireccion, int);
bool hayColision(TPosicion, TPosicion);

int main() {
    TGrupoRobots grupo;

    printf("Introduce el número de robots (hasta 10): ");
    scanf("%d", &(grupo.numRobots));

    inicializarRobots(&grupo);
    moverRobots(&grupo);
    mostrarPosicionesFinales(grupo);
    verificarColisiones(grupo);

    return 0;
}

void inicializarRobots(TGrupoRobots* grupo) {
    for (int i = 0; i < grupo->numRobots; i++) {
        leerDatosRobot(&(grupo->robots[i]), i+1);
    }
}

void moverRobots(TGrupoRobots* grupo) {
    for (int i = 0; i < grupo->numRobots; i++) {
        calcularSiguientePosicion(&(grupo->robots[i].posicion.x), &(grupo->robots[i].posicion.y), grupo->robots[i].direccion, grupo->robots[i].distanciaMovimiento);
    }
}

void mostrarPosicionesFinales(TGrupoRobots grupo) {
    for (int i = 0; i < grupo.numRobots; i++) {
        printf("El robot %c se moverá a la posición (%d, %d)\n", i+1, grupo.robots[i].posicion.x, grupo.robots[i].posicion.y);
    }
}

void verificarColisiones(TGrupoRobots grupo) {
    for (int i = 0; i < grupo.numRobots; i++) {
        for (int j = i + 1; j < grupo.numRobots; j++) {
            if (hayColision(grupo.robots[i].posicion, grupo.robots[j].posicion)) {
                printf("El robot %c y el robot %c COLISIONARÁN!!!\n", i+1, j+1);
            }
        }
    }
}

void leerDatosRobot(TRobot* robot, int id) {
    printf("Introduce posición inicial (x,y) del robot %d:\n", id);
    scanf("%d %d", &(robot->posicion.x), &(robot->posicion.y));
    robot->direccion = leerDireccion(id);
    printf("Introduce unidades de movimiento del robot %d:\n", id);
    scanf("%d", &(robot->distanciaMovimiento));
}


void calcularSiguientePosicion(int* pos_x, int* pos_y, TDireccion dir, int movimiento) {
    switch (dir) {
        case NORTE :
            *pos_y -= movimiento;
            break;
        case SUR :
            *pos_y += movimiento;
            break;
        case ESTE :
            *pos_x += movimiento;
            break;
        case OESTE :
            *pos_x -= movimiento;
    }
}


TDireccion leerDireccion(int id) {
    TDireccion dir;
    
    do {
        printf("Introduce dirección de movimiento del robot %d (0-Norte 1-Sur 2-Este 3-Oeste):\n", id);
        scanf("%u", &dir);
    } while (dir != NORTE && dir != SUR && dir != ESTE && dir != OESTE);
    
    return dir;
}


bool hayColision(TPosicion posicion1, TPosicion posicion2) {
    return posicion1.x == posicion2.x && posicion1.y == posicion2.y;
}