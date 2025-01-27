#include <stdio.h>
#include <stdbool.h>

#define KCAPACIDAD 300
#define KTIPOHABITACION 50

typedef char TTipoHabitacion[KTIPOHABITACION+1];
typedef int TCapacidad[KCAPACIDAD];
typedef struct {
    int id;
    TTipoHabitacion Tipo;
    bool ocupada;
    int tarifaNoche;
}THabitacion;

#define KNOMBREHUESPED 50
#define KNUMEROIDENTIFICACION 10
typedef char TNombreHuesped [KNOMBREHUESPED+1];
typedef char TNumeroIdentificacion[KNUMEROIDENTIFICACION+1];
typedef struct{
    int dia,mes, anyo;
}TFecha;
typedef struct{
    TNombreHuesped nombre;
    TNumeroIdentificacion identificacion;
    TFecha chekin,checkout;
    int numeroHabitacion;
}THuesped;

