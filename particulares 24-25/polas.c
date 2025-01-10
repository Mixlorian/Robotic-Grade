#include <stdio.h>

int leerPositivo(){
    int n;
    do{
        printf("introduce un numero positivo:");
        scanf("%d",&n);
        if(n<0){
            printf("Tiene que ser un numero positivo");
        }
    } while (n<0);
    return n;
}


int main(){



    return 0;
}




#define KPISOS 50
#define KPROPIETARIOS 50
#define KRECIBOS 200
#define KDNI 9
#define KEMAIL 50
#define KTELEFONO 11
#define KNOMBRE 50

typedef char TTelefono[KTELEFONO + 1];
typedef char TEmail[KEMAIL +1];
typedef char TNimbre[KNOMBRE + 1];
typedef char TDNI [KDNI + 1];
typedef struct{
    int escalera, planta;
    char letra;
    int metros;
    TDNI dni;
}TPiso;
typedef TPiso TPisos [KPISOS];

typedef struct{
    int codigo;
    TConcepto concepto;
    TFecha emision, pago;
    float importe;
}TRecibo;

typedef TRecibo TRecibos[KRECIBOS];

typedef struct{
    TDNI dni;
    TTelefono telefono;
    TNombre nombre;
    TRecibos recibos;
    int numRecibos;
}TPropietario;
typedef TPropietario TPropietarios [KPROPIETARIOS];

typedef struct{
    TPropietarios propietarios;
    int numPropietarios;
    TPisos pisos;
    int numPisos;
}TComunidad;



