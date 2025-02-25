#include <iostream>
#include <vector>
using namespace std;
using Collection = vector<string>;

int main(){


    //pide n un numero n positivo
    int n;
    do{
        cout<<"introduce un numero positivo: ";
        cin>>n;
        cin.get();
    }while(n<0);

    //pide n cadenas y metelas en el vector, permite que tiene espacios
    string leida;
    Collection cadenas;

    for(int i=1;i <= n;i++){
        cout << "introduce una cadena " << i << ":";
        getline(cin, leida);
        cadenas.push_back(leida);    
    }

    //Imprime las cadenas del vector, cada una en una linea
    cout << "Las cadenas introducidas son: " << endl;
    for(string s : cadenas){
        cout << s << endl;
    }
    // Pide un caracter entre estos # . , al usuario 
    char c;
    do{
        cout << "Introduce un caracter [# , .]:";
        cin>> c;

    }while(c != '#' && c != '.' && c != ',')

    // Une todas las cadenas del vector en una sola cadena
    // usando el caracter anterior como separador
    string resultado = " ";
    for(int i = 0; i < cadenas.length(); i++){
        resultado = resultado + cadenas[i];
        if(i != cadena.size() -1){
            resultado = resultado + c;
        }
    }
    cout << "juntitas" << resultado << endl;



}