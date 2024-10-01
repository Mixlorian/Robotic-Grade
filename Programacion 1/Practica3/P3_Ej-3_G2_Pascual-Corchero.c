#include <stdio.h>


int main(){


    int n;
    char caracter = '0';

    do
    {
        printf("Introduce un numero positivo y mayor que 0: ");
        scanf("%d",&n);
    } while (n <= 0);

    do
    {
        printf("Introduce un caracter:");
        scanf(" %c",&caracter);
    } while (caracter >= '0' && caracter <= '9');


    for(int i = 1; i <= n ; i++){
        printf("%d",i);
        for(int o = 1;o <= i;o++){
            printf("%c",caracter);
        }
        for(int a = 1; a <= i; a++){
            printf("%d",a);
        }
        printf("\n");
    }
    return 0;
}