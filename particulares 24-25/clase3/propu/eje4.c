#include <stdio.h>

int main(){

    float a,b,c,r1,r2,discriminante;
    printf("Coef. de la ecuacion (a b c):");
    scanf("%f %f %f", &a,&b,&c);

    discriminante = b*b-4*a*c;
    printf("Ecuacion: %.2f·x^2 + %.2f·x + %.2f\n",a,b,c);

    if(a==0 && b==0){
        printf("Hay infinitas soluciones");
    }
    if(a==0 && b!=0){
        printf("hay una unica solucion real");
    }
    if(a!=0 && discriminante < 0){
        printf("no hay soluciones reales");
    }
    if(a!=0 && discriminante >0){
        printf("hay dos soluciones posibles");
    }

    return 0;
}