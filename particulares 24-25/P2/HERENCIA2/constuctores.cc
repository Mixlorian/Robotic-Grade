#include <iostream>
using namespace std;


class Unidad{
	private:
		int x, y;
		int vida;
	public:
		// sin cosntructores!!
		int getX() const;
		int getY() const;
		int getVida() const;
		void setXY(int vx, int vy);
		void reset();
};

int Unidad::getVida() const{
	return vida;
}

int Unidad::getX() const{
	return x;
}

int Unidad::getY() const{
	return y;
}

void Unidad::setXY(int vx, int vy){
	x = vx;
	y = vy;
}

void Unidad::reset(){
	x = 0;
	y = 0;
	vida = 0;
}

int main(){
	Unidad u1, u2;  // constructor de oficio, C++ nos proporciona
			// un constructor sin parametros => es el
			// constructor por defecto.
	cout << u1.getX() << endl;
	cout << u1.getY() << endl;
	cout << u1.getVida() << endl;
}

