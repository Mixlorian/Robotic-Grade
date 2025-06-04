#include "C.h"

namespace C3{

int C::nextId = 1;

C::C(){
	id = C::getNextId();
}

int C::getId() const{
	return id;
}

int C::getNextId(){
	// este metodo tiene this? no tiene this porque es static
	// no tiene oboet implicito
	return C::nextId++;
}

}
