#include <stdio.h>


#define KTAM 10
typedef int TVectorEnteros [KTAM];

// cambia todos los valores que superan el valor limite por
// el nuevo valor, y devuelve la cantidad de valores sustituidos.
//       0   1   2   3   4
// ve = {2, 30, 12, 40, 45}
// limite = 25
// nuevo = 0


//       i   i   i   i   i
// 	 0   1   2   3   4
// ve = {2,  0, 12,  0,  0}
//       
//
int sustituirMayores(TVectorEnteros ve, int limite, int nuevo){
	int cambiados = 0;
	for(int i = 0; i < KTAM; i++){
		if(ve[i] > limite){
			ve[i] = nuevo;
			cambiados++;
		}
	}	
	return cambiados;
}

// devuelve la cantidad de valores pares/impares que tiene el vector.
void contarParImpar(TVectorEnteros ve, int *npar, int *nimpar){
	*npar = 0;
	*nimpar = 0;
	for(int i = 0; i < KTAM; i++){
		if(ve[i] % 2 == 0){
			*npar += 1;
		}
		else{
			*nimpar += 1;
		}
	}
}

void prevYpost(TVectorEnteros ve, int buscado){
	for(int i = 0; i < KTAM; i++){
		if(ve[i] == buscado){
			if(i - 1 >= 0){
				printf("%d ", ve[i - 1]);
			}
			else{
				printf("-1 ");
			}
			if(i + 1 < KTAM){
				printf("%d ", ve[i + 1]);
			}
			else{
				printf("-1 ");
			}
		}
	}
}

// decrementar los elementos en el valor pasado como parametro,
// saturando a 0, devuelve el numero de elementos saturados.

//	0	1	2	3	4	5
// 	------------------------------------------
// 	4	9	12	4	8	31
//	0	0	2	0	0	21
// 	valor = 10

//	4

int decrementar(TVectorEnteros ve, int valor){
	int saturados = 0;
	
	for(int i = 0; i < KTAM; i++){
		if(ve[i] >= valor){
			ve[i] -= valor;
		}
		else{
			ve[i]= 0;
			saturados++;
		}
	}
	return saturados;
}

// devuelve la primera posicion en la que aparece el valor
// buscado en el vector.

//       0  1    2  3  4 5  6
// 	12 32 	23 12 32 34 89
// pos  -1  -1  -1  -1 -1 5
//[buscado = 34] => devolvera 5

// devuelve -1 si no lo encuentra.
int buscarPosicion(TVectorEnteros ve, int buscado){
	int i, pos;
	pos = -1;
	i = 0;
	while(i < KTAM && pos == -1){
		if(ve[i] == buscado){
			pos = i;
		}
		else{
			i++;
		}
	}
	return pos;
}

// * Sustituir pos posicion...
#define KBUSCADOS 5
typedef int TBuscados [KBUSCADOS];

// Sustituye cada elemento del vector de buscados, por la posicion
// que ocupa en el vector ve, si no esta en el vector lo cambiara por -1.

//        0  1   2  3  4   5   6   7  8
// ve = {12, 3, 12, 4, 90, 12, 34, 5, 8}

// buscados = {90, 8, 12, 3, 100}
//              4  8   0  1   -1

void sustituye(TVectorEnteros ve, TBuscados buscados){
	int pos;
	for(int i = 0; i < KBUSCADOS; i++){
		pos = buscarPosicion(ve, buscados[i]);
		ve[i] = pos;
	}
}

void sustituyeNazi(TVectorEnteros ve, TBuscados buscados){
	int pos, i, j;
	for(i = 0; i < KBUSCADOS; i++){	
		// busca el valor buscados[i] en el vector ve[
		j = 0;
		pos = -1;
		while(j < KTAM && pos == -1){
			if(buscados[i] == ve[j]){
			//          0        0
			//          0        1
			//          0        2
			//          0        3
			//          0        4 => pos = 4
			// -----------------------------
			//          1        0
			//          1        1
			//          1        2
			//          ...
			//	    1        8 => pos = 8
			// -------------------------------
				pos = j;
			}
			else{
				j++;
			}
		}
		buscados[i] = pos;
	}
}

// devuelve la suma de los elementos del vector.
int sumar(TVectorEnteros ve){
	int suma, i;
	suma = 0;
	for(i = 0; i < KTAM; i++){
		suma += ve[i];
	}
	return suma;
}

// 0 1  2  3  4  5
// 2 4 12 44 23 12
//
// 4 2 44 12 12 23
void inter(TVectorEnteros ve){
	int aux;
	// paro en el penultimo
	for(int i = 0; i < KTAM - 1; i += 2){
		aux = ve[i];
		ve[i] = ve[i+1];
		ve[i+1] = aux;
	}
}

void inversa(TVectorEnteros ve){
	int i, j, aux;
	i = 0;
	j = KTAM - 1;
	while(i < j){ // 0 9, 1 8, 2 7, 3 6, 4 5
		aux = ve[i];
		ve[i] = ve[j];
		ve[j] = aux;
		i++;
		j--;
	}
}

// rellena el vector con los numeros de la serie de fibonacci.
void rellenar(TVectorEnteros ve){
	int i, sig, act, ant;
	
	ant = 0;
	act = 1;
	for(i = 0; i < KTAM; i++){
		ve[i] = act;
		sig = act + ant;
		ant = act;
		act = sig;
	}
}

void imprimir(TVectorEnteros ve){
	printf("<");
	for(int i = 0; i < KTAM; i++){
		printf("%d", ve[i]);
		if(i != KTAM - 1){
			printf(", ");
		}
	}
	printf(">");
}

#define KINVENTARIO 3
#define KTAMPIEZAS 10

typedef enum {Tuerca, Tornillo, Clavo} TPieza;
typedef int TInventario [KTAM];
typedef TPieza TListaPiezas [KTAMPIEZAS];

// pide las piezas al usuario, si no es una pieza la volvera a pedir.
// meteme una pieza 0 (0 = Tuerca,1 = Tornillo,2 = Clavo): 0
// meteme una pieza 1 (0 = Tuerca,1 = Tornillo,2 = Clavo): 2
// meteme una pieza 2 (0 = Tuerca,1 = Tornillo,2 = Clavo): 4
// meteme una pieza 2 (0 = Tuerca,1 = Tornillo,2 = Clavo): 0
// meteme una pieza 3 (0 = Tuerca,1 = Tornillo,2 = Clavo): 1
// ...
// meteme una pieza 9 (0 = Tuerca,1 = Tornillo,2 = Clavo): 2
void pedirPiezas(TListaPiezas piezas){
}

// hacer inventario
//		invens[0] => cantidad Tuercas
//		invnes[1] => cantidad de Tornillo
//		invens[2] => cantidad de Clavo.
void hacerInventario(TInventario invens, TListaPiezas piezas){

}

int main(){
	TVectorEnteros ve;
	
	rellenar(ve);
	imprimir(ve);
	return 0;
}
