#include <stdio.h>
#include <stdbool.h>

int sdp(int n){
	int s = 0;
	for(int i = 1; i < n; i++){
		if(n % i == 0){
			s += i; // s = s + i
		}
	}
	return s;
}

// true o false
// la funcion devuelve cierto si es perfecto falso si no
// un numero es perfecto si es  igual a la suma de sus divisores propios
bool esPerfecto(int num){
	int sdpnum;
	bool es;
	sdpnum = sdp(num); // sdpnum = sdp(6) n = 6

	if(sdpnum == num){
		es = true;
	}
	else{
		es = false;
	}
	return es;
	
	// return sdpnum(num) == num;
}

// imprime amigos o no amigos en funcion de si
// a y b son amigos
// dos numeros a y b son amigos si la suma de los divisores propios
// de a es igual a b y viceversa.
// 224 280
void sonAmigos(int a, int b){
	int sda, sdb;
	sda = sdp(a); // sda = sdp(224) n = 224
	sdb = sdp(b); // sdb = sdp(280) n = 280
	if(sda == b && sdb == a){
		printf("amigos\n");
	}
	else{
		printf("no amigos\n");
	}
	
}


int main(){
	printf("%d\n", sdp(8)); // => 1 + 2 + 4
	printf("%d\n", sdp(6)); // => 1 + 2 + 3
	
	
	sonAmigos(224, 280); // a = 224, b = 289
	
	
	if(esPerfecto(6)){  // num = 6
		printf("es perfecto\n");
	}
	if(esPerfecto(24)){  // num = 24

	}

}
