#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ICONOS 10
#define TAMANIO_PATRON 5
#define TAMANIO_NOMBRE 50
#define CARGAR 'c'
#define MOSTRAR 'm'
#define MODIFICAR_PIXEL 'p'
#define LISTAR 'l'
#define SALIR 's'

typedef struct {
    char patron[TAMANIO_PATRON][TAMANIO_PATRON];
    char nombre[TAMANIO_NOMBRE];
} TIcono;

typedef struct {
    TIcono iconos[MAX_ICONOS];
    int cantidad;
} TColeccionIconos;

// Prototipos de funciones
int buscarIcono(TColeccionIconos coleccion, char nombre[]);
void cargarIcono(TColeccionIconos *coleccion);
void mostrarIcono(TColeccionIconos coleccion);
void modificarPixelIcono(TColeccionIconos *coleccion);
void listarNombresIconos(TColeccionIconos coleccion);

int main() {
    char comando;
    TColeccionIconos coleccion;

    do {
        printf("\nComando (c)argar, (m)mostrar, modificar (p)ixel, (l)istar, (s)alir: ");
        scanf(" %c", &comando);
        switch (comando) {
            case CARGAR:
                cargarIcono(&coleccion);
                break;
            case MOSTRAR:
                mostrarIcono(coleccion);
                break;
            case MODIFICAR_PIXEL:
                modificarPixelIcono(&coleccion);
                break;
            case LISTAR:
                listarNombresIconos(coleccion); 
                break;
            case SALIR:
                printf("Programa terminado.\n");
                break;
            default:
                printf("Comando desconocido.\n");
        }
    } while (comando != SALIR);
    return 0;
}

void cargarIcono(TColeccionIconos* col) {
    if (col->cantidad >= MAX_ICONOS) {
        printf("Límite de iconos alcanzado.\n");
    } else {      
        printf("Introduce el nombre del icono: ");
        scanf("%s", col->iconos[col->cantidad].nombre);
        
        printf("Introduce el patrón del icono (5x5):\n");
        for (int i = 0; i < TAMANIO_PATRON; i++) {
            for (int j = 0; j < TAMANIO_PATRON; j++) {
                scanf(" %c", &col->iconos[col->cantidad].patron[i][j]);
            }
        }
        col->cantidad++;
    }
}

void mostrarIcono(TColeccionIconos col) {
    char nombre[TAMANIO_NOMBRE];
    int indice;

    printf("Introduce el nombre del icono a mostrar: ");
    scanf("%s", nombre);
    
    indice = buscarIcono(col, nombre);

    if (indice == -1) {
        printf("Icono no encontrado.\n");
    } else {
        for (int i = 0; i < TAMANIO_PATRON; i++) {
            for (int j = 0; j < TAMANIO_PATRON; j++) {
                printf("%c", col.iconos[indice].patron[i][j]);
            }
            printf("\n");
        }
    }
}

int buscarIcono(TColeccionIconos col, char nombre[]) {
    int indice = -1;
    for (int i = 0; i < col.cantidad; i++) {
        if (strcmp(col.iconos[i].nombre, nombre) == 0) {
            indice = i;
        }
    }
    return indice;
}

void modificarPixelIcono(TColeccionIconos* col) {
    char nombre[TAMANIO_NOMBRE];
    int indice, x, y;
    char pixel;
    bool posicion_valida;

    printf("Introduce el nombre del icono a modificar: ");
    scanf("%s", nombre);
    
    indice = buscarIcono(*col, nombre);

    if (indice == -1) {
        printf("Icono no encontrado.\n");
    } else {
        printf("Introduce la posición x,y (0-4) a modificar: ");
        scanf("%d,%d", &x, &y);

        posicion_valida = x >= 0 && x < TAMANIO_PATRON && y >= 0 && y < TAMANIO_PATRON;
        if(posicion_valida) {
            printf("Introduce el nuevo carácter: ");
            scanf(" %c", &pixel);
    
            col->iconos[indice].patron[x][y] = pixel;
        } else {
            printf("Posición no válida\n");
        }
    }
}

void listarNombresIconos(TColeccionIconos col) {
    if (col.cantidad == 0) {
        printf("No hay iconos cargados en el sistema.\n");
    } else {
        printf("Iconos disponibles:\n");
        for (int i = 0; i < col.cantidad; i++) {
            printf("%d. %s\n", i + 1, col.iconos[i].nombre);
        }
    }
}