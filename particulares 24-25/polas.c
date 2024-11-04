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