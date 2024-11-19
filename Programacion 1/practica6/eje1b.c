#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUMERO_ROBOTS 10 
#define TAMANO_MAPA 20
#define CASILLA_VACIA '.'
#define CASILLA_COLISION '#'

typedef enum {NORTE, SUR, ESTE, OESTE} TDireccion;

typedef struct {
    int x;
    int y;
} TPosicion;

typedef struct {
    TPosicion posicion;
    TDireccion direccion;
    int distanciaMovimiento;
    char id;
} TRobot;

typedef struct {
    TRobot robots[MAX_NUMERO_ROBOTS];
    int numRobots;
} TGrupoRobots;

typedef char TMapa[TAMANO_MAPA][TAMANO_MAPA];

void inicializarMapa(TMapa mapa);
void marcarColisiones(TMapa mapa, TGrupoRobots grupo);
void mostrarMapa(TMapa mapa, TGrupoRobots grupo);
bool esPosicionValida(TPosicion posicion);

// Prototipos de las funciones:
void inicializarRobots(TGrupoRobots* grupo);
void moverRobots(TGrupoRobots* grupo);
void mostrarPosicionesFinales(TGrupoRobots grupo);
void verificarColisiones(TGrupoRobots grupo);
void leerDatosRobot(TRobot *, int);
TDireccion leerDireccion(int);
TPosicion calcularSiguientePosicion(TPosicion, TDireccion, int);
bool hayColision(TPosicion, TPosicion);

int main() {
    TGrupoRobots grupo;
    TMapa mapa;

    printf("Introduce el número de robots (hasta 10): ");
    scanf("%d", &(grupo.numRobots));

    inicializarRobots(&grupo);
    moverRobots(&grupo);
    mostrarPosicionesFinales(grupo);
    verificarColisiones(grupo);

    inicializarMapa(mapa);
    marcarColisiones(mapa, grupo);
    mostrarMapa(mapa, grupo);

    return 0;
}

void inicializarRobots(TGrupoRobots* grupo) {
    for (int i = 0; i < grupo->numRobots; i++) {
        grupo->robots[i].id = 'A' + i; 
        leerDatosRobot(&(grupo->robots[i]), i+1);
    }
}

void moverRobots(TGrupoRobots* grupo) {
    TPosicion nuevaPosicion;
    for (int i = 0; i < grupo->numRobots; i++) {
        TPosicion nuevaPosicion = calcularSiguientePosicion(grupo->robots[i].posicion, grupo->robots[i].direccion, grupo->robots[i].distanciaMovimiento);
        if (esPosicionValida(nuevaPosicion)) {
            grupo->robots[i].posicion = nuevaPosicion;
        }
    }
}

void mostrarPosicionesFinales(TGrupoRobots grupo) {
    for (int i = 0; i < grupo.numRobots; i++) {
        printf("El robot %d se moverá a la posición (%d, %d)\n", i+1, grupo.robots[i].posicion.x, grupo.robots[i].posicion.y);
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


TPosicion calcularSiguientePosicion(TPosicion pos, TDireccion dir, int movimiento) {
    TPosicion nuevaPos;

    nuevaPos = pos;
    switch (dir) {
        case NORTE :
            nuevaPos.y = pos.y - movimiento;
            break;
        case SUR :
            nuevaPos.y = pos.y + movimiento;
            break;
        case ESTE :
            nuevaPos.x = pos.x + movimiento;
            break;
        case OESTE :
            nuevaPos.x = pos.x- movimiento;
    }
    return nuevaPos;
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

bool esPosicionValida(TPosicion posicion) {
    return posicion.x >= 0 && posicion.x < TAMANO_MAPA && posicion.y >= 0 && posicion.y < TAMANO_MAPA;
}

void inicializarMapa(TMapa mapa) {
    for (int i = 0; i < TAMANO_MAPA; i++) {
        for (int j = 0; j < TAMANO_MAPA; j++) {
            mapa[i][j] = CASILLA_VACIA;
        }
    }
}

void marcarColisiones(TMapa mapa, TGrupoRobots grupo) {
    for (int i = 0; i < grupo.numRobots; i++) {
        for (int j = i + 1; j < grupo.numRobots; j++) {
            if (hayColision(grupo.robots[i].posicion, grupo.robots[j].posicion)) {
                mapa[grupo.robots[i].posicion.y][grupo.robots[i].posicion.x] = CASILLA_COLISION;
            }
        }
    }
}

void mostrarMapa(TMapa mapa, TGrupoRobots grupo) {
    for (int i = 0; i < grupo.numRobots; i++) {
        if (esPosicionValida(grupo.robots[i].posicion)) {
            if (mapa[grupo.robots[i].posicion.y][grupo.robots[i].posicion.x] == CASILLA_VACIA) {
                mapa[grupo.robots[i].posicion.y][grupo.robots[i].posicion.x] = grupo.robots[i].id;
            }
        }
    }

    for (int i = 0; i < TAMANO_MAPA; i++) {
        for (int j = 0; j < TAMANO_MAPA; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}