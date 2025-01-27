#include <stdio.h>

int becil(int n){
    int sumaDivisores = 0;

    for(int i = 1; i <=n; i++){
        if(n%i == 0){
            sumaDivisores = sumaDivisores + i;
        }
    }

    return sumaDivisores;
}
int main(){

    int n,sd;
    printf("Valor:");
    scanf("%d",&n);

    sd = becil(n);
    printf("la suma de los divisores: %d\n", sd);
/*
    int divisor = 1;
    while(divisor <= n){
        if(n % divisor == 0){
            printf("%d ",divisor);
        }
        divisor++;
    }*/
    
    return 0;
}