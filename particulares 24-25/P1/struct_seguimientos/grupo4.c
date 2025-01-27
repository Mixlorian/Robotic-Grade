#include <stdio.h>

#define KTAMN 30
#define KTAMC 50
typedef char TNombre[KTAMN+1];
typedef char TCreador[KTAMC+1];
typedef struct{
    int dia, mes,anyo;
}TFecha;
typedef struct {
    int Id;
    TNombre Nombre_Obra;
    int Anyo;
    TCreador Creador;
    TFecha Fecha;
    float precio;
}TObra;

#define KID_LABORAL 10
#define KNOMBRE_EMPLEADO 50
#define KOBRAS_CARGO 10
typedef char TIDEmpleado[KID_LABORAL+1];
typedef char TNombreEmpleado[KNOMBRE_EMPLEADO+1];
typedef int TObrasCargo[KOBRAS_CARGO];
typedef struct {
    TNombreEmpleado Nombre_Empleado;
    TIDEmpleado ID;
    TObrasCargo obras;
    int numObrasCargo;
}TEmpleado;

#define KNOMBRE_EXPOSICION 50
#define KOBRAS_EXPUESTAS 20
typedef int TObrasExpuestas [KOBRAS_EXPUESTAS];
typedef char TNombreExpo[KNOMBRE_EXPOSICION+1];
typedef struct{
    TNombreExpo Nombre_Expo;
    TObrasExpuestas Obras;
    int numExpuestas;
    int Aforo_Max;
    TFecha inicio,fin;
}TSalaExpo;

#define KEXPOSICIONES 5
#define KEMPLEADOS_MUSEO 50
#define KNOMBRE_MUSEO 30
#define KOBRAS 500
#define KNOMBRE_DIRECTOR 50
typedef char TNombreMuseo[KNOMBRE_MUSEO + 1];
typedef char TNombreDirector[KNOMBRE_DIRECTOR +1];
typedef TEmpleado TEmpleados[KEMPLEADOS_MUSEO];
typedef TObra TObras[KOBRAS];
typedef TSalaExpo TSalasExpo [KEXPOSICIONES];
typedef struct{
    TNombreMuseo Nombre_Museo;
    int anyoInaguracion;
    TNombreDirector Nombre_Director;
    TEmpleados empleados;
    int numEmpleados;
    TObras obras;
    int numObras;
    TSalaExpo exposiciones;
    int numExposiciones;
}TMuseo;



int main(){


    return 0;
}