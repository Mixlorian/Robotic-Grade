#include <stdio.h>

/*

*/

#define KTAM 50
typedef char TCadena [KTAM];

// copia en la cadena dst, la cadena org invertida.
//               i
//        01234567
// org = "catalina\0"
//      dst =" "anilatac"
//
//     j        i
// dst[0] = org[7]
// dst[1] = org[6]
// ..
// dst[7] = org[0]
void invertir(TCadena org, TCadena dst){
    int i, j;

    i = 0;
    while(org[i] != '\0'){
        i++;
    }
    i--;

    j = 0;
    while(i >= 0){
        dst[j] = org[i];
        //  0        7
        //  1        6
        i--;
        j++;
    }
    dst[j] = '\0';
}

#include <stdlib.h>
// cada c caracteres hay que meter una letra mayuscula aleatoria

//            x   x
//        01234567890123
// org = "viva maricrist"   c = 4
// dst = "vivaX marYicriTst"
void codificar(TCadena org, TCadena dst, int c){
    char alcar;
    int i, j, copiados;


    i = 0;
    j = 0;
    copiados = 0;
    while(org[i] != '\0'){
        dst[j] = org[i];
        i++;
        j++;
        copiados++;
        if(c == copiados){
            copiados = 0;
            alcar = rand() % ('Z' - 'A' + 1) + 'A';
            dst[j] = alcar;
            j++;
        }
    }
    dst[j] = '\0';

    // codigo de partida que copia la cadena dst en la cadena org
    //i = 0;
    //j = 0;
    //while(org[i] != '\0'){
    //    dst[j] = org[i];
    //    i++;
    //    j++;
    //}
    //dst[j] = '\0';
    //
}

// copia en la cadena dst la cadena org, nveces veces

//       ii
//       ii
//       ii
// org ="LA" nveces =3

//        jjjjjj
// dst = "LALALA"

//     j        i
// dst[0] = org[0]  k = 1
// dst[1] = org[1]
/// -------------------
// dst[2] = org[0]  k = 2
// dst[3] = org[1]
/// -------------------
// dst[4] = org[0]  k = 3
// dst[5] = org[1}
// ---------------------

void strXcpy(TCadena org, TCadena dst, int nveces){
    int i, j;

    j = 0;
    for(int k = 1; k <= nveces; k++){
        i = 0;
        while(org[i] != '\0'){
            dst[j] = org[i];
            i++;
            j++;
        }
        dst[j] = '\0';
    }
}



/*
Funcion que lee posiciones de los robots hasta que el usuario
mete -1 o se superan las posiciones maximas del vector (10)
Cuando acaba la funcion en ncuantos tendremos que dejar
la cantidad deposiciones leidas.

Introduzca las posiciones del robot (-1 to finish):
2 3
2 9
9 2
10 23
-1
*/
void leerPosiciones(int x[], int y[], int *ncuantos){
    int valorx, valory;
    printf("Introduzca las posiciones del robot (-1 to finish): ");
    *ncuantos = 0;
    do{
        scanf("%d", &valorx);
        if(valorx != -1){
            scanf("%d", &valory);
            x[*ncuantos] = valorx;
            y[*ncuantos] = valory;
            (*ncuantos)++;
        }
    }while(*ncuantos < 10 && valorx != -1);
}

// <(3, 4), (1, 3), (2, 8)>
void imprimirPosiciones(int x[], int y[], int ncuantos){
    printf("<");
    for(int i = 0; i < ncuantos; i++){
        printf("(%d, %d)", x[i], y[i]);
        if(i != ncuantos - 1){
            printf(", ");
        }
    }
    printf(">");
}

//  i
// balancin

//j
// lancin
bool esSufijo(TCadena c1, TCadena c2){
    int i, j;


    i = 0;
    while(c1[i] != '\0'){
        i++;
    }

    j = 0;
    while(c2[j] != '\0'){
        j++;
    }

    while(i >= 0 && j >= 0 && c1[i] == c2[j]){
        i--;
        j--;
    }

    return j == -1;
}

int main(){
    int x[10], y[10], ncuantos;
    leerPosiciones(x, y, &ncuantos);
    imprimirPosiciones(x, y, ncuantos);

    TCadena dst;
    codificar("la casa es blanca", dst, 2);

    printf("%s\n", dst);
}




