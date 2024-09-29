#include <stdio.h>


int main(){

    int n1,n2,n3;

    printf("escribe 3 numeros consecutivos:");
    scanf("%d %d %d",&n1,&n2,&n3);
    if(n1 - 1 == n2){
        if(n2 - 1 == n3){
            printf("Los numeros %d %d %d son consecutivos\n",n1,n2,n3);
        }else{
            printf("Los numeros %d %d %d NO son consecutivos\n",n1,n2,n3);
        }
    }else{
        if(n1 + 1 == n2){
            if(n2 + 1 == n3){
                printf("Los numeros %d %d %d son consecutivos\n",n1,n2,n3);
            }else{
                printf("Los numeros %d %d %d NO son consecutivos\n",n1,n2,n3);
            }
        }
    }

    return 0;
}