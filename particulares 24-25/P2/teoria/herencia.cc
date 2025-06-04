#include <iostream>
#include <vector>
using namespace std;
/*
HERENCIA
- Mecanismo de reutilización de código.
- Cuando detectamos que varias clases tienen un comportamiento o naturaleza
comun usaremos herencia y agruparemos ese comportamiento o naturaleza comun
en una clase base o madre o superclase (factorizacion) compartida por todas las clases que deriven de ella, hijas o derivadas.
*/

class Personal{
	private:
		const string nombre; // atributo de instancia constante.
		double sueldo;
	public:
		Personal();
		Personal(string n, double s);
		string getNombre() const;
		// Enlazado dinamico!!
		// Se hereda siempre sera enlazado dinamico,
		// lo sobrescribamos como lo sobrescribamos.
		virtual double getSueldo() const;	
};

Personal::Personal():nombre(""){
	sueldo = 0;
}

// la unica forma de inicializar una constante es en la lista
// de inicializacion
Personal::Personal(string n, double s):nombre(n), sueldo(s){
	// nombre = n; // esto da error porque es const!!!
	// sueldo = s;
}

string Personal::getNombre() const{
	return nombre;
}

double Personal::getSueldo() const{
	return sueldo;
}

// class NOMBRE_DERIVADA : [public|private|protected] NOMBRE_BASE{
// 	CUERPO_DERIVADA
//};

// Un Bonificado es_un Personal va a contener todo lo que hay en Personal

// INDEPENDIENTEMENTE DEL TIPO DE HERENCIA:
// - LA CLASE DERIVADA SOLO PUEDE ACCEDER DIRECTAMENTE A PUBLIC Y PROTECTED
// HEREDADO, PARA ACCEDER A LO PRIVADO TENDRA QUE USAR LOS METODOS PUBLICS
// O PROTECTEDS HEREDADOS.
//	- LOS CONSTRUCTORES NO SE HEREDAN
//	- LA AMISTAD NO SE HEREDA
//	- LA SOBRECARGA DE OPERADORES NO SE HEREDA.

// EL TIPO DE HERENCIA CAMBIA EL AMBITO DE LO HEREDADO PARA OTRAS CLASES.
class Bonificado : public Personal{
	// Esto solo compila si existe un constructor sin parametros
	// en la clase base, porque c++ crea un constructor de oficio
	// por defecto, que implicitamente invoca al constructor
	// sin parametros de la clase base!!!
};


class Temporal : public Personal{
	private:
		int meses_contrato;
	public:
		Temporal(string n, double s, int mc);
		int getMesesContrato() const{
			return meses_contrato;
		}
};

// Cambiar el comportamiento de un metodo heredado!!
// ¿QUE PASA SI EXTISTE UN METODO EN LA CLASE DERIVADA CON
// EL MISMO NOMBRE QUE UN METODO QUE HAYA EN LA CLASE BASE?
// Su sueldo se calcula de forma aleatoria, como su sueldo base
// incrementado en un porcentaje aleatorio
class Suertudo : public Personal{
	public:
		Suertudo(string n, double s);
		double getSueldo() const;
};

Suertudo::Suertudo(string n, double s):Personal(n, s){

}

// - Sobrecarga en jerarquias de herencia:
// 	Ocultacion: misma signatura (parametros y tipo devuelto) que en
// la clase base con enlazado estatico.

//      Sobrescricutra: misma signatura (parametros y tipo devuelto) que en
// la base con enlazado dinamico (virtual en base)
double Suertudo::getSueldo() const{
	double calculado;
	int porcentaje = rand() % 101;
	// genero un numero aleatorio entre 0 y 100.
	
	
	// funcion recursiva infnita!!
	// calculado = getSueldo() * (1 + porcentaje/100.0);
	// Tengo que indicar que el metodo esta en el ambito
	// de la base!!
	calculado = Personal::getSueldo() * (1 + porcentaje/100.0);
	
	return calculado;
}



// En un constuctor nuestro que no indiquemos nada en la lista
// de inicializacion en la derivada, c++ invoca automaticamente al
// por defecto de la clase base, (si no existe en la base dara error)
Temporal::Temporal(string n, double s, int mc)/*:Personal()*/
:Personal(n, s){ // LLAMAMOS DE FORMA EXPLICITA AL CONSTR. DE LA BASE.
	// aunque estos dos campos son heredados
	// son privados en la base y no son directamente accesibles:
	/*nombre = n;
	sueldo = s;*/
	meses_contrato = mc;
}

#include <ctime>

int main(){
	srand(time(NULL));
	Personal *e;
	int r = rand();
	
	cout << "aleatorio: " << r << endl;
	if(r % 2 == 0){
		e = new Suertudo("jose", 1500);
	}
	else{
		e = new Temporal("jose temporal", 1000, 12);
	}
	
	// De que tipo es e?
	// 	cuando compilo seguro que e es de tipo Empleado
	
	// 	cuando ejecuto, cambiara de una ejecucion a otra
	
	// Esto siempre funcionara porque todos los emplleados tiene
	// sueldo porque esta definido en la base, y todos lo heredan.
	cout << e->getSueldo() << endl;
	
	// RESTRICCION: MEDIANTE EL PUNTERO DE TIPO BASE (O REFERENCIA)
	// SOLO PUEDO INVOCAR A UN METODO SI ESTA DEFINIDO EN LA BASE.
	// A CUAL SE INVOCA YA DEPENDE DEL TIPO DE ENLACE Y SI EL METODO
	// SE SOBRESCRIBIO O SE OCULTO EN LA DERIVADA!!
	
	// Esto puede no funcionar, porque Personal no tiene el metodo
	// getMesesContrato()
	
	// Como podemos comprobar si el puntero esta apuntando a un
	// objeto de tipo temporal.
	
	// * CASTEO TRADICIONAL (CONVECTIONAL CAST)
	// SIEMPRE COMPILA
	// ESTE CASTEO SE HACE EN TIEMPO DE COMPILACION
	// me aseguro de que puedo hacer la conversion,
	// la conversion en el contexto es segura.
	if(typeid(*e) == typeid(Temporal)){ // RTTI
		// conversion insegura
		// Casteo convencional
		cout << ((Temporal *)e)->getMesesContrato() << endl;
	}
	else{
		cout << "con suerte" << endl;
	}
	
	// CASTEO DINAMICO, SE HACE EN TIEMPO DE EJCUCION
	// NECESITA COMPROBAR SI EL PUNTEOR ESTA APUNTADO AL OBJETO.
	// Devuelve nullptr si el casteo no se pudo realizar.
	// El casteo comprueba si el tipo destino es valido
	// SOLO SI HAY AL MENOS UNA FUNCION VIRTUAL EN LA JERARQUIA,
	// PORQUE SI NO DURANTE LA COMPILACION NO SE GENERA LA INFORMACION
	// NECESARIA PARA PODER HACER LA COMPROBACION DE TIPO DURANTE LA EJEC.
	Temporal *te = dynamic_cast<Temporal *>(e);
	if(te){
		cout << "Es temporal " << te->getMesesContrato() << endl;
	}	
	delete e;
	
	class Parra{};
	// ESTO NO COMPILA PORQUE NO HAY UNA RELACION DE HERENCIA.
	// Temporal *te2 = dynamic_cast<Parra *>(e);
	
	class Parrita : public Parra{
	};
	
	class Parrita2 : public Parra{
	};
	
	Parra *mi_parra = new Parrita();
	
	// ESTO NO COMPILA PORQUE LA CLASE BASE NO TIENE NINGUN
	// METODO VIRTUAL.
	// Parrita *mi_parrita = dynamic_cast<Parrita *>(mi_parra);
	
	// ESTE NO COMPILA PORQUE NO HAY RELACION DE HERENCIA ENTRE CLASES.
	// Temporal *te2 = static_cast<Parra *>(e);

	// ESTE SE HACE EN TIEMPO DE COMPILACION
	// PUEDE SER QUE NO SEA SEGURO.
	Parrita *mi_parrita = static_cast<Parrita *>(mi_parra);
		
	// ESTE SIEMPRE SE HACE SI HAY RELACION DE HERENCIA
	// NO ES SEGURO, ESTA CONVERSION SE HACE... PERO NO ES CORRECTA
	// PORQUE ESTA APUNTANDO A OTRA DERIVADA NO A LA QUE LE 
	// HE INDICADO.
	Parrita2 *mi_parrita2 = static_cast<Parrita2 *>(mi_parra);
	
	
	return 0;
}

/*
#include <ctime>
int main(){
	srand(time(NULL));
	// vector dinamico de direcciones de Empleado, estas pueden
	// ser dinamicas o estaticas.
	vector<Personal *> empleados;
	Personal e("josete", 2000);
	Personal *pe = new Personal("josesin", 1200);
	
	empleados.push_back(&e); // direccion de un empleado dinamico.
	empleados.push_back(pe); // direccion dinamica.
	empleados.push_back(new Personal("joseson", 1300));
	
	for(Personal *empleado : empleados){
		cout << empleado->getNombre() << endl;
		cout << empleado->getSueldo() << endl;
	}
	
	// POLIMORFISMO SIMPLE:
	// En c++ el polimorfismo se implementa mediante punteros!!
	// Un puntero o referencia a objeto base puede recibir objetos
	// de tipo derivado!! => ya que todas las derivadas tienen
	// todo lo necesario para comportarse como una base, porque
	// lo han heredado de la base.
	empleados.push_back(new Bonificado());
	empleados.push_back(new Temporal("josele", 1200, 12));
	empleados.push_back(new Suertudo("jose lucky", 1200));
	
	cout << "los sueldos polimorficos" << endl;
	// 2000, 1200, 1300, 2000,
	for(Personal *empleado : empleados){
		cout << empleado->getNombre() << endl;
		// Cuando llega a Suertudo tengo dos metodos
		// getSueldo el dela base y el de la derivada
		// Ademas el tipo del puntero es de tipo Personal
		// pero el tipo del objeto a cual apunta el puntero
		// es de tipo Suertudo.
		
		// EN COMPILACION, NO SABEMOS A QUE OBJETO VA A APUNTAR
		// ESE PUNTERO, SI ENLAZAMOS (DECIDIMOS A QUE METODO
		// INVOCAR EN TIEMPO DE COMPILACION), INVOCAREMOS AL DE LA
		// BASE => ES EL COMPORTAMIENTO POR DEFECTO DE C++ =>
		// ENLAZADO ESTATICO!!!!
		cout << empleado->getSueldo() << endl;
	
		// SI QUEREMOS UN COMPORTAMIENTO DINAMICO, ES DECIR,
		// QUE SE INVOQUE AL TIPO DEL OBJETO AL CUAL APUNTA EL PUNTERO
		// DURANTE LA EJECUCION Y NO DEL TIPO DEL PUNTERO,
		// TENDREMOS QUE AÑADIR EL MODIFICADOR virtual EN 
		// LA DEFINICION DEL METODO DE LA CLASE BASE.
	
	}

	delete pe;// por cada new mio un delete!
	delete empleados[2];
	delete empleados[3];
	delete empleados[4];
	return 0;
}
*/

/*
// MEIN EJEMPLO EINS!! MIRADLO DETENIDAMENTE,
// EL ENLAZADO CON EL METODO GETSUELDO ERA STATIC!!!
#include <ctime>
int main(){
	srand(time(NULL));
	//Personal p1; 	// No tengo un constructor sin parametros 
			// no tengo un connstructor de oficio porque c++
			// detecta que ya tengo otro constructor.
			// Si lo defino de forma explicta si que funcionaria!!
			
	Personal p2("jose", 1200);
	cout << p2.getNombre() << endl;
	cout << p2.getSueldo() << endl;
	// cout << p2.getMesesContrato() << endl; NO FUNCIONA HACIA ARRIBA
	
	// Temporal temp("jose", 1200); // los constructores no se heredan!!!

	Bonificado bnok2; // Este es el por defecto que da c++

	Temporal t1("juan", 2890, 9);
	// El metodo añadido!
	cout << t1.getMesesContrato() << endl;
	// Los metodos heredados!
	cout << t1.getNombre() << endl;
	cout << t1.getSueldo() << endl;

	Suertudo suerte("jose", 1000);
	vector<string> meses = {"enero", "febrero", "marzo", "abril"};
	double s = 0, a;
	for(string m : meses){
		cout << "Sueldo en " << m << ": ";
		a = suerte.getSueldo();
		s += a;
		cout << a << endl;
	}
	cout << "sueldo medio: " << s / meses.size() << endl;

		
	return 0;
}
*/

