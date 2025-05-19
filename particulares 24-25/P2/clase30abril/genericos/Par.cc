#include <iostream>
using namespace std;


template <class T, class V>
class Par{
	private:
		T first;
		V second;
	public:
		Par(const T &f, const V &s):first(f), second(s){
		}
		/*Par(const T &f, const V &s){
		// este llama al cpd de T y V, asegurate de que los vas a tener.
			first = f;
			second = s;
		}*/
		T getFirst() const{
			return first;
		}
		V getSecond() const{
			return second;
		}
};

class Elemento{
	private:
		int e;
	public:
		Elemento(int ve){
			e = ve;
		}
		int getElemento() const{
			return e;
		}
};

int main(){
	Par<int, float> par(12, 32.3);
	Par<Elemento, char> p(Elemento(12), 'A');
	
	cout << p.getFirst().getElemento() << endl;
	cout << p.getSecond() << endl;
	
	return 0;
}
