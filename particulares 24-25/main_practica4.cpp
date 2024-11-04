#include <stdio.h>
#include <stdbool.h>

// Ejercicio 6.
typedef enum{Aspirina, Ibuprofeno, Paracetamol}TMedicamento;
#define NUM_MEDICAMENTOS 3
#define INI_ASPIRINA 100
#define INI_PARACETAMOL 75
#define INI_IBUPROFENO 120

/*
Cantidad disponible final de medicamentos:
Aspirina: 20
Ibuprofeno: 0
Paracetamol: 35
*/
void imprimirMedicamentos(int stock[]){

}

// actualizar el medicamento med con la cantidad can
// indicada, por ejemplo si med es 0, tendre que quitarle
// a la posicion 0 del vector el valor can
// Devuelve cierto si se puedo actualizar el medicamento
// falso si no, si can es mayor de lo que hay, se devolvera falso.
bool actualizarMedicamentos(int stock[], int med, int can){

}

int main(){
    bool underflowStock;
    int medicamento, cantidad;
    int stock[NUM_MEDICAMENTOS] = {INI_ASPIRINA, INI_IBUPROFENO, INI_PARACETAMOL};
    printf("Introduce los datos de los medicamentos (-1 para finalziar):");
    do{
        scanf("%d", &medicamento);
        if(medicamento != -1){
            scanf("%d", &cantidad);
            underflowStock = actualizarMedicamentos(stock, medicamento, cantidad);
        }
    }while(medicamento != -1 && underflowStock == false);
    imprimirMedicamentos(stock);
}


// Ejercicio 2.
typedef enum {Norte, Sur, Este, Oeste} TDireccion;

bool esCorrecta(TDireccion dir){
    bool b;
    b = dir >= Norte && dir <= Oeste;
    return b;
}

// cuando solo devuelvo un valor hago return de ese valor.
TDireccion leerDireccion(int num){
    TDireccion dir;
    do{
        printf("Introduce dirección de movimiento del robot %d (0-Norte 1-Sur 2-Este 3-Oeste):", num);
        scanf("%u", &dir);
    }while(!esCorrecta(dir));
    return dir; // devuelvo el valor
}
// cuando tengo que devolver mas de un valor, le paso
// variables para rellenarlas.
void leerPosicion(int *x, int *y, int num){
    do{
        printf("Introduce posicion inicial (x,y) del robot num: ", num);
        scanf("%d %d", x, y);
    }while(*x < 0 || *y < 0);
}

void leerRobot(int *x, int *y, int *u, TDireccion *d, int n){
    leerPosicion(x, y, n);
    *d = leerDireccion(n);
    printf("Introduce unidades de movimiento del robot %d: ", n);
    scanf("%d", u);
}

void modificarPosicion(int *x, int *y, int u, TDireccion d){
    switch(d){
        case Norte:
            *y -= u;
        break;
        case Sur:
            *y += u;
        break;
        case Este:
            *x += u;
        break;
        case Oeste:
            *x -= u;
        break;
    }
}

// Cuando pasamos un vector a una funcion no se indica el tamaño.
// Si modificamos cualquier vector se verá modificado el vector
// que le he pasado, porque realmente lo que paso es la direccion
// de comienzo del vector.
void leerRobots(int x[], int y[], TDireccion dirs[], int us[]){
    for(int i = 0; i < 5; i++){
        // x[i] es un int, el valor que hay
        // en la posicion i en el vector.
        // leerRobot(x[i], y[i], us[i], dirs[i], i + 1);
        leerRobot(&x[i], &y[i], &us[i], &dirs[i], i + 1);
    }
}

void imprimirRobots(int x[], int y[]){
    for(int i = 0; i < 5; i++){
        printf("El robot se movera a la posicion (%d, %d)\n", x[i], y[i]);
    }
}

// i j j j j
//   i j j j
//     i j j
//       i j
// 0 1 2 3 4
// =========
// 3 2 3 4 2

void comprobarColisiones(int x[], int y[]){
    for(int i = 0; i < 5; i++){
        // i = 0, j = 1, j = 2
        // i = 1, j = 2
        for(int j = i + 1; j < 5; j++){
            if(x[i] == x[j] && y[i] == y[j]){
//          if(x[0] == x[1] && y[0] == y[1]){
//          if(x[0] == x[2] && y[0] == y[2]){
//          if(x[0] == x[3] && y[i] == y[3]){
//          if(x[0] == x[4] && y[i] == y[4]){

//          if(x[1] == x[2] && y[1] == y[2]){
//          if(x[1] == x[3] && y[1] == y[3]){
//          if(x[1] == x[4] && y[1] == y[4]){

//          if(x[2] == x[3] && y[2] == y[3]){
//          if(x[2] == x[j] && y[2] == y[4]){

//          if(x[3] == x[4] && y[3] == y[4]){

                printf("El robot %d y %d COLISIONAN\n", i + 1, j + 1);
            }
        }
    }
}

void modificarPosiciones(int x[], int y[], TDireccion dirs[], int us[]){
    for(int i = 0; i < 5; i++){
        modificarPosicion(&x[i], &y[i], us[i], dirs[i]);
    }
    // estas dos llamandas las podria haber hecho en el main.
    imprimirRobots(x, y);
    comprobarColisiones(x, y);
}


int main2(){
    int x[5];
    int y[5];
    TDireccion dirs[5];
    int unidades[5];

    // no se pone & en la llamada!!
    leerRobots(x, y, dirs, unidades);
    imprimirRobots(x, y);

    modificarPosiciones(x, y, dirs, unidades);
    return 0;
}

/*
int main2(){
    int x, y, u;
    TDireccion d;
    leerRobot(&x, &y, &u, &d, 1);
    printf("x=%d,y=%d,u=%d,d=%u\n", x, y, u, d);
    modificarPosicion(&x, &y, u, d);
    printf("x=%d,y=%d,u=%d,d=%u\n", x, y, u, d);

}
*/





