#include <iostream>
#include <vector>
using namespace std;
/*
- sobrecarga de operadores.
*/
#include <cmath>
class Punto{
    // esta funcion pasa a ser amiga de la clase y ahora puede
    // acceder a la parte privada de la clase.
    friend double operator-(const Punto &pto1, const Punto &pto2);
    //friend bool operator==(const Punto &izq, const Punto &der);
    private:
        int x, y;
    public:
        //Punto();
        Punto(int vx = 0, int vy = 0);
        int getX() const;
        int getY() const;
        void setX(int vx);
        void setY(int vy);
        double calcularDistancia(const Punto &pto) const;
        // le sumo a la x y a la y el valor t.
        void trasladarXY(int t);
        // la x con la x y la y con la y.
        Punto sumar(const Punto &pto) const;
        void trasladarX(int t);
        void trasladarY(int t);

        // SOBRECARGA DEL OPERADOR COMO FUNCION MIEMBROS.
        // el operando de la izquierda es implicito
        bool operator==(const Punto &der) const;
        bool operator!=(const Punto &der) const;
};

class Poligono{
    private:
        Punto *ptos;
        int numPuntos;
    public:
        Poligono(int np);
        Poligono(const Poligono &pol);
};


bool Punto::operator!=(const Punto &der) const{
    return !(*this == der);
}

// CUALES DE LAS SOBRECARS QUE HEMOS IMPLEMENTADO HOY EN ESTA
// CLASE MARAVILLOSA DE MIERDA, NO PUEDEN SER FUNCION PUTO MIEMBRO.
//      int + Punto
//      ostream << Punto
//
// Si meto un operador como metodo de clase, el operando de la
// izquierda tendria que ser de tipo Punto, porque va a ser this.
// y this es de tipo Punto *


// this es izquierdo
// der es del derecho.
bool Punto::operator==(const Punto &der) const{
    return x == der.x && y == der.y;
}

void Punto::trasladarXY(int t){
        x += t;
        y += t;
}
void Punto::trasladarX(int t){
        x += t;
}
void Punto::trasladarY(int t){
        y += t;
}

Punto Punto::sumar(const Punto &pto) const{
        return Punto(x + pto.x, y + pto.y);
/*
        Punto resultado;
        resultado.x = x + pto.x;
        resultado.y = y + pto.y;
        return ressltado;
*/
}

double Punto::calcularDistancia(const Punto &pto) const{
    double distancia = 0;
        distancia = sqrt(pow(x - pto.x, 2) + pow(y - pto.y, 2));
    return distancia;
}
/*
Punto::Punto(){
    x = 0;
    y = 0;
}*/
Punto::Punto(int vx, int vy){
    x = vx;
    y = vy;
}
int Punto::getX() const{
    return x;
}
int Punto::getY() const{
    return y;
}
void Punto::setX(int vx){
    x = vx;
}
void Punto::setY(int vy){
    y = vy;
}

// sobrecarga operador
//  como funcion
//      - van a aparecer de forma explicita todos los operandos.
//  como metodo
//      - uno de los operandos estará implicito.
//      - restriccion: el operando de la izquierda
//      tiene que ser del tipo de la clase que  lo
//      contiene.

// no es un metodo, this is a fucking free fuction.
Punto operator+(const Punto &izq, const Punto &der){
    Punto nuevo(izq.getX() + der.getX(), izq.getY() + der.getY());
    return nuevo;
}

// El que sobrecargue punto + int no implica que la sobrecarga
// int + punto este hecha, tendre que implementarla si la quiero tambien.
Punto operator+(const Punto &izq, int der){
    Punto nuevo(izq.getX() + der, izq.getY() + der);
    return nuevo;
}

Punto operator+(int izq, const Punto &der){
    return der + izq; // este llama al de arriba.
}

// asociamos llamadas de izquierda a derecha
// y todas las variables devuelven
// sobrecarga del operador salida.
ostream & // devuelvo la variable que entro!!!
operator<<(ostream &os, const Punto &pto){
    os << "(" << pto.getX() << ", " << pto.getY() << ")";
    return os;
}
// LA RESTA DE DOS PUNTOS
// COMO FUNCION Y QUIERO DEVUELVA LA DISTANCIA ENTRE DOS PUNTOS NAZIS.
/*
double operator-(const Punto &pto1, const Punto &pto2){
    double distancia;

    distancia = sqrt(pow(pto1.getX() - pto2.getX(), 2) +
                     pow(pto1.getY() - pto2.getY(), 2));

    return distancia;
}
*/
// TAMBIEN PODEMOS HACER LA FUNCION AMIGA DE LA CLASE.
// ahora puedo quitar los geters aun asi los puedo dejar je je.
double operator-(const Punto &pto1, const Punto &pto2){
    double distancia;
    distancia = sqrt(pow(pto1.x - pto2.x, 2) +
                     pow(pto1.y - pto2.y, 2));

    return distancia;
}

/*
bool operator==(const Punto &izq, const Punto &der){
    return izq.x == der.x && izq.y == der.y;
}
*/

int main(){
    Punto pto1, pto2;
    Punto p1(0, 3), p2(0, 10);

    cout << p1.calcularDistancia(p2) << endl;
    cout << p1 - p2 << endl;

    Punto resultado;

    resultado = p1.sumar(p2);
    // Esto no funciona porque los operadores
    // no son capaces de trabajar con nuestros tipos de datos.
    resultado = p1 + p2 + pto1 + pto2;
    // resultado = p1.sumar(p2.sumar(pto1.sumar(pto2)));
    // para que la setnencia de arriba funciones tenemos
    // que sobrecargar el operador + para que
    // sea capaz de trabajar con dos puntos.
    cout << resultado.getX() << " " << resultado.getY() << endl;//7

    // C++ en su afan de que todo funciones aplica las cooerciones
    // conversiones implicita =>  encuentra que puede construir
    // un punto a partir de un entero.
    resultado = p1 + 10; // Punto + int
    // Punto(int vx = 0, vy = 0) => Punto(10, 0)
    cout << resultado.getX() << " " << resultado.getY() << endl; // 0 13
    resultado = 10 + p1; // int + Punto
    // Punto(10, 0)

    cout << p1 << " - " << p2 << " - " << pto1 << " - " << pto2 << endl;
    // cout << " - " << p2
    // cout << p2 ...
    // cout => ostream
    // p1 => Punto
    // operador <<

    if(pto1.getX() == pto2.getX() && pto1.getY() == pto2.getY()){
        cout << "son puto iguales" << endl;
    }
    else{
        cout << "no son igasldfj" << endl;

    }

    if(pto1 == pto2){

    }

    return 0;
}
