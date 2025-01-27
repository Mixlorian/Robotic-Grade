#include <stdio.h>
#include <math.h>
#define KCONTADORES 5
#define KTAM 50
typedef char TCadena [KTAM];
typedef int TContadores [KCONTADORES];

// contadores[0] = el numero de as
// contadores[1] = el numero de es
// contadores[2] = el numero de is
// contadores[3] = el numero de os
// contadores[4] = el numero de us
void contarVocales(TCadena cadena, TContadores contadores){
	int i;
	// 	contadores
	//	0	1	2	3	4
	//	===================================
	// 	2	0	0	1	0
	for(i = 0; i < KCONTADORES; i++){
		contadores[i] = 0;
	}
	//	cadena
	//	0	1	2	3	4	5
	//	===================================================
	//	a 	b 	r	a 	z	o	\0
	i = 0;
	while(cadena[i] != '\0'){
		switch(cadena[i]){
			case 'a':
			case 'A':
				contadores[0]++;
				break;
			case 'e':
			case 'E':
				contadores[1]++;
				break;
			case 'i':
			case 'I':
				contadores[2]++;
				break;
			case 'o':
			case 'O':
				contadores[3]++;
				break;
			case 'u':
			case 'U':
				contadores[4]++;
				break;
		}
		i++;
	}
}

// para cada coordenada muestra el numero de veces que aparece en el
// vector
//
//	i	j	j	j	j	j
//		i	j	j	j	j
//			i	j	j	j
//				i 	j	j
//					i	j
//						i
//	0	1	2	3	4	5
//	------------------------------------------
//cx	1	2	1	1	2	3
//cy	2	8	2	2	8	4
//	

// (1,2) esta 3 veces
// (2,8) esta 2 veces
// (3,4) esta 1 veces

void mostrarRepeticiones(int cx[], int cy[], int cuantasCoords){
	int veces;
	for(int i = 0; i < cuantasCoords; i++){
		// primero miro si esta en las posiciones anteriores
		veces = 0;
		for(int j = 0; j < i && veces == 0; j++){
			if(cx[i] == cx[j] && cy[i] == cy[j]){
				veces++;
			}
		}
		// si no esta en las posiciones anteriores lo busco
		// en las siguientes
		if(veces == 0){
			veces = 1;
			for(int j = i + 1; j < cuantasCoords; j++){
				if(cx[i] == cx[j] && cy[i] == cy[j]){
					veces++;
				}
			}
			printf("(%d,%d) esta %d veces\n", cx[i], cy[i], veces);
		} 
	}
}


// muestra las coordenadas mas cercanas entre si.
// 
//	muestra las posiciones de los dos robots mas cercanos en el 
//	vector.
//	
//	0	1	2	3	4
//	-----------------------------------
//cx	10	20	40	35	22	
//cy	10	20	40	35	22
//
//	(20, 20) y (22, 22)
//
double distancia(double cx1, double cy1, double cx2, double cy2){
	double d = 0;
	d = sqrt(pow(cx1 - cx2, 2) + pow(cy1 - cy2, 2));
	return d;
}

void mostrarMasCercamos(int cx[], int cy[], int cuantasCoords){
	double dactual, dmenor = -1;
	int pos1, pos2;
	
	dmenor = distancia(cx[0], cy[0], cx[1], cy[1]); // cojo esta distancia como menor!!
	pos1 = 0; // las coordenadas mas cercanas de momento son la 0 y la 1.
	pos2 = 1;
	for(int i = 0; i < cuantasCoords; i++){
		// i = 0, j = 1, 2, 3, 4
		// i = 1, j = 2, 3, 4
		// i = 2, j = 3, 4
		// i = 3, j = 4
		for(int j = i + 1; j < cuantasCoords; j++){
			// calculo la distancia entra la coordenada i y la coordenada j.
			dactual = distancia(cx[i], cy[i], cx[j], cy[j]);
			if(dactual < dmenor){
				// si mejoro la distanciamenor la actualizo
				dmenor = dactual;
				pos1 = i;
				pos2 = j;
			}
		}
	}
	printf("(%d, %d) y (%d, %d) son las mas cercanas y estan a %lf distancia\n", cx[pos1], cy[pos1], cx[pos2], cy[pos2], dmenor);			
}

// copia en dst la cadena org
// dst = {}
// org = {'m', 'a', 's', '\0'}
void copiar(char dst[], char org[]){
//	dst[0] = org[0];
//	dst[1] = org[1];
//	dst[2] = org[2];
//	dst[3] = '\0';	
	int i;
	i = 0;
	while(org[i] != '\0'){
		dst[i] = org[i];
		i++;
	}
	dst[i] = '\0';
}

// copia al final de dst la cadena org.
void copiarAtEnd(char dst[], char org[]){
	int i, j;
	// ponemos la i al final de la cadena destino.
	i = 0;
	while(dst[i] != '\0'){
		i++;
	}
	// copio los caracteres a partir de la posicion i.
	j = 0;
	while(org[j] != '\0'){
		dst[i] = org[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

// devuelve cierto si la cadena es correcta.
// 3 vocales mayusculas 
// un guion
// n digitos pares (n cualquier numero mayor que 1)
// un guion
// 2 digitos impares
// un quion
// 3 consonantes mayusculas.

// AEA-86688-31-ZZX
bool esCorrecta(TCadena cadena){
	
}

// -1 si c1 < c2
// 0 si c1 = c2
// 1 si c1 > c2
int cmpCads(char c1[], char c2[]){

}

//	
// 	i i i
//	0 1 2 3 4 5 6 7 8 9 
//	e e p r e f e e r s \0
//	j

// 	i i i i
//	0 1 2 3 4 5 6 7 8 9 
//	p e p r e f e e r s \0
//	j j
//

// 	i i i i i i
//	0 1 2 3 4 5 6 7 8 9 
//	p r p r e f e e r s \0
//	j j j
//

int borrarCaracter(char c[], char b){
	int i, j, veces;
	
	veces = 0;
	i = 0;
	while(c[i] != '\0'){
		if(c[i] == b){
			i++; // si es igual me lo salto
		}
		else{
			// si no es igual lo guardo!!
			c[j] = c[i];
			i++;
			j++;
		}
	}
	c[j] = '\0';
	
	
	return veces;
	
}


#define DESCARGADA '#'
#define CARGADA '*'
typedef char TBateria [10];

// 0123456789
// ******####	=> 4

// devuelve el numero de celdas cargadas
int cargaBateria(TBateria bateria){
	int cargadas = 0;
	for(int i = 0; i < 10; i++){
		if(bateria[i] == DESCARGADA){
			bateria[i] = CARGADA;
			cargadas++;
		}
	}	
	return cargadas;
}

// eficientemente!!.
// ******####	=> 
// ######

int descargaBateria(TBateria bateria){
	int descargadas, i;
	descargadas = 0;
	i = 0;
	while(i < 10 && bateria[i] == CARGADA){
		descargadas++;
		bateria[i] = DESCARGADA;
	}
	return descargadas;
}

//	0123456789
//	*******###
//
//	si cdescargadas = 3
//
//	0123456789
//	****######
//
void descargaBateria(TBateria bateria, int cdescargadas){
	i = 9;
	while(i >= 0 && cdescargadas > 0){
		if(bateria[i] == CARGADA){
			bateria[i] = DESCARGADA;
			cdescargadas--;
		}
		i--;
	}
}

int main(){
	int cx[] = {1, 2, 1, 1, 2, 3};
	int cy[] = {2, 8, 2, 2, 8, 4};
	mostrarRepeticiones(cx, cy, 6);

	int cx2[] = {10,	20,	40,	35,	22};	
	int cy2[] = {10,	20,	40,	35,	22};
	
	
	mostrarMasCercamos(cx2, cy2, 5);
	


}



