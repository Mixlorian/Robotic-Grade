#include <stdio.h>

int main(){

    int i,o,valor;
    i = 8;

    while(i >= 1){
        printf("%d ",i);
        i = i-1;
    }
    printf("\n");
    printf("introduce un valor:");
    scanf("%d",&valor);
    
    o = 10;

    while (o >=0){
        printf("%d X\n ",valor);
        o--;
    }

    return 0;
}