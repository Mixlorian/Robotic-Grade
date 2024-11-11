#include <stdio.h>

#define KTAM 50
typedef char TCadena [KTAM];

void invertir(TCadena org, TCadena dst){
    int i = 0;
    int j = 0;

    while(org[i] != '/0'){
        i++;                    //Sacas el tamaño de la cadena origen
    }
    i--;            //quitamos el ultimo ya que es el barra cero
    j=0;
    while(i >=0){
        dst[j] = org[i];        //Mientras que la i sea menor que 0 copiamos cadena
        j++;
        i--;
    }
        dst[i] = '\0';
}
void leerPosiciones(int x[], int y[],int *ncuantos){
    *ncuantos =0;
    int valorx,valory;
    printf("Introduce las posiciones del robot (-1 to finish)");
    do{
        scanf("%d", valorx);
        if(valorx != -1){
            scanf("%d", valory);
            x[*ncuantos] = valorx;
            y[*ncuantos] = valory;
            (*ncuantos)++;
        }
    } while (valorx != -1 && ncuantos < 10);  
}
void imprimirPosiciones(int x[], int y[], int ncuantos){
    printf("<");
    for (int i = 0; i < ncuantos; i++){
        printf("(%d, %d)",&x[i],&y[i]);
        if(i != ncuantos -1){
            printf(", ");
        }
    }   
    printf(">");
}
void codificar(TCadena org, TCadena dst, int c){
    char alcar; 
    int i = 0;
    int j = 0;
    int k = 0;

    while(org[i] != '\0'){
        dst[j] = org[i];
        j++;
        i++;
        k++;
        if(k == c){
            k = 0;
            alcar = rand() % ('Z' - 'A' + 1) + 'A';
            dst[j] = alcar;
            j++;
        }

    }
    dst[j] = '\n';
}
void strXcpy(TCadena org, TCadena dst, int nveces){
    int j = 0;
    int k = 0;
    for(int i = 0; i <= nveces; i++){
        while(org[j] != '\0'){
            dst[k] = org[j];
            k++;
            j++;
        }
        j = 0;
        dst[k] = '\0';
    }
    
}
int main(){

    int x[10], y[10], ncuantos;
    leerPosiciones(x,y,&ncuantos);
    imprimirPosiciones(x,y,ncuantos);
}