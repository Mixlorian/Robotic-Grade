#include <stdio.h>

/*
Ejercicio 1.
Implementa un programa capaz de almacenar los datos de hasta 20 productos,
de cada producto se conocerá su nombre (maximo 50 caracteres), el precio
de venta al publico y su stock (inicialmente será 0).
El programa tendra un menu con dos opciones:
    1. Rellenar n productos.
    2. Imprimir los productos.
    3. Salir.

En la opcion 1 primero se pedirá la cantidad de productos a rellenar, este
tendra que ser un valor entre 0 y 20. A continuacion se pedira para cada
producto su nombre, su precio y su stock, estos dos ultimos mayores que 0.

En la opcion 2 se imprimiran todos los productos.

Nota: Debeis usar una variable para saber cuantas posiciones del vector
estarán ocupadas.
*/

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
        printf("Introduce la matricula para el robot %d: ", i);
        scanf(" %s", robots[i].matricula);
        do{
            printf("Introduce la posicion, fila y columna separados por un espacio para el robot %d: ", i);
            scanf("%d %d", &leida.row, &leida.col);
        }while(leida.row < 0 || leida.col < 0);
        robots[i].coords = leida;
    }
    // matricula (row, col)
    // imprimir los rabots

    return 0;
}

typedef struct{
    int capacidad, litros;
}Deposito;

// vector de 5 depositos!
int main_3(){
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

    // queremos que el introduzca los litros de los 5 depositos
    // si es mayor que la capacidad o es menor que 0, los volvera a pedir.
    // modificar directamente el vector!
    for(int i = 0; i < 5; i++){
        do{
            printf("Introduce la cantidad de litros [0..%d]: ", depositos[i].capacidad);
            scanf("%d", &depositos[i].litros);
        }while(depositos[i].litros > depositos[i].capacidad || depositos[i].litros < 0);
    }

    // bucle para imprimir todos los depositos
    // [0]: litros/capadidad
    // [1]: litros/capacidad
    // ...
    // [4]: litros/capacidad

    for(int i = 0; i <= 4; i++){
        printf("[%d]: %d/%d\n", i, depositos[i].litros, depositos[i].capacidad);
    }
    
    // pedir un total de litros al usuario
    // y llenar los depositos con esa cantidad empezando desde 0
    // iremos vertiendo los litros introducidos en los depositos del vector
    // hasta que se acaben los depositos o se nos acaben los litros
    // si al final de recorrer el vector quedan litros sin usar, lo mostraremos por pantalla.
    int total_vertido, i, disponible;
    printf("Introduzca la cantidad de litros: ");
    scanf("%d", &total_vertido);
    i = 0;
    while(i < 5 && total_vertido > 0){
        disponible = depositos[i].capacidad - depositos[i].litros;
        if(disponible >= total_vertido){
            depositos[i].litros += total_vertido;
            total_vertido = 0;
        }
        else{ // si no cabe todo, llena ese y le quitas lo que he llenado al total
            total_vertido -= disponible;
            depositos[i].litros = depositos[i].capacidad;
        }
        i++;
    }
    if(total_vertido > 0){
        printf("Quedaron por verter %d litros\n", total_vertido);
    }
    return 0;;
}



typedef struct{
    int h, m;
}Hora;


int main_2(){
    int kat[3];

    Hora horas[5];

    // 12 13 14 15 16

    for(int i = 0; i < 5; i++){
        horas[i].h = i + 12;
        horas[i].m = 0;
    }

    // {12:00, 13:00, 14:00, 15:00, 16:00}
    printf("{");
    for(int i = 0; i < 5; i++){
        printf("%02d:%02d", horas[i].h, horas[i].m);
        if(i != 4){
            printf(", ");
        }
    }
    printf("}");

    // kat => int []
    // kat[0] => int

    // horas => Hora []
    // horas[0] => Hora
    // horas[0].h => int
    // horas[0].m => int

    return 0;
}


typedef struct{
    int x, y;
}Punto;

typedef Punto VectorPuntos [10];

int main_1(){
    Punto p1, p2;

    // nombre_variable.nombre_campo
    p1.x = 12;
    p1.y = 34;
    p2.x = p1.x + 10; // p2.x = 22
    p2.y = p1.y * 2;  // p2.y = 64

    printf("(%d, %d) (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);

    Punto puntos[4] = {{2, 3}, {1, 2}, {3, 2}, {3, 21}};

    printf("(%d, %d)\n", puntos[0].x, puntos[0].y);
    printf("(%d, %d)\n", puntos[1].x, puntos[1].y);
    printf("(%d, %d)\n", puntos[2].x, puntos[2].y);
    printf("(%d, %d)\n", puntos[3].x, puntos[3].y);

    // puntos => Punto []
    // puntos[0] => Punto
    // puntos[0].x => int
    // puntos[0].y => int

    for(int i = 0; i <  4; i++){
        printf("(%d, %d)\n", puntos[i].x, puntos[i].y);
    }

    return 0;
}
