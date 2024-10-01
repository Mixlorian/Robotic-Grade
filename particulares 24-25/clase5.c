#include <stdio.h>

typedef enum {PERAS = 1,MANZANAS, MELONES} TProducto;

int main() {
   
    const float PRECIO_PERAS = 12.0;
    const float PRECIO_MANZANAS = 13.4;
    const float PRECIO_MELONES = 16.2;

    TProducto producto;
    int cantidad;
    float dineroEntregado, precioTotal = 0.0;

    
    printf("Tabla de precios:\n");
    printf("1. Peras = %.2f\n", PRECIO_PERAS);
    printf("2. Manzanas = %.2f\n", PRECIO_MANZANAS);
    printf("3. Melones = %.2f\n", PRECIO_MELONES);
    
    printf("Introduce [1 peras, 2 manzanas, 3 melones]: ");
    scanf("%d", &producto);
    
    printf("Introduce la cantidad: ");
    scanf("%d", &cantidad);

    switch (producto) {
        case PERAS:
            precioTotal = PRECIO_PERAS * cantidad;
            break;
        case MANZANAS:
            precioTotal = PRECIO_MANZANAS * cantidad;
            break;
        case MELONES:
            precioTotal = PRECIO_MELONES * cantidad;
            break;
        default:
            printf("Producto no válido\n");
    }

    printf("Introduce dinero entregado: ");
    scanf("%f", &dineroEntregado);

    if (dineroEntregado >= precioTotal) {
        printf("Cambio: %.2f\n", dineroEntregado - precioTotal);
    } else {
        printf("No habeis pagao\n");
    }

    return 0;
}