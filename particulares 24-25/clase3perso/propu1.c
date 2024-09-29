#include <stdio.h>

int main(){

    int n1, n2; 
    printf("escribe un numero entero:");
    scanf("%d",&n1);
    printf("escribe otro numero entero:");
    scanf("%d",&n2);

    if(n1 > n2){
        printf("el numero %d es mayor que %d\n",n1,n2);
    }else{
        if(n2 == n1){
            printf("el numero %d es igual que %d\n",n1,n2); 
        }else{
        printf("el numero %d es mayor que %d\n",n2,n1);
        }
    }
    return 0;
}