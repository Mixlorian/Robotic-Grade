#include <stdio.h>

#define KNOMBRE_CHEF 50
#define KNOMBRE_PLATO 50
typedef char TNombreChef[KNOMBRE_CHEF+1];
typedef char TNombrePlato[KNOMBRE_PLATO+1];
typedef struct{
    int ID;
    TNombreChef Nombre_Chef;
    TNombrePlato especial;
}TChef;
#define KCATEGORIA 30
typedef char TCategoria[KCATEGORIA+1];

typedef struct {
    TNombrePlato nombre;
    TCategoria Categoria;
    int Tiempo_Preparacion;
}TPlato;
typedef struct{
    int idChef;
    TNombrePlato platoPreparado;
    int puntos;
}TRonda;
#define KPLATOS 30
#define KRONDAS 100
#define KCHEFS 50
typedef TPlato TListaPlatos[KPLATOS];
typedef TChef TListaChef[KCHEFS];
typedef TRonda TListaRondas[KRONDAS];
typedef struct {
    TListaPlatos platos;
    int numPlatos;
    TListaRondas rondas;
    int numRondas;
    TListaChef chefs;
    int numChefs;
}TConcurso;







