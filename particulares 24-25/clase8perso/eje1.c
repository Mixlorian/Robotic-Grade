#include <stdio.h>

int max2(int a, int b){
    int m;

    if(a > b){
        m = a;
    }else{
        m = b;
    }
    return m;
}
int max3(int a, int b, int c){
    int r;

    r = max2(a,b);
    r = max2(r,c);
    return r;
}

int main(){
    int n1,n2,n3,r;

    printf("Introduce 3 valores:");
    scanf("%d %d %d",&n1,&n2,&n3);

    r = max3(n1,n2,n3);
    printf("el mayor numero es %d",r);

    return 0;
}