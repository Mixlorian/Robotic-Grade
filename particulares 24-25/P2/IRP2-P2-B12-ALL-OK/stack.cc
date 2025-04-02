#include "stack.h"
#include "list.h"
#include "lib/error.h"

// Una pila es una estrucura de datos los elementos siempre
// se insertan y se recuperan por el mismo extremo

StackPtr stackCreate (){
	StackPtr sp = nullptr;
	sp = new Stack; 
	sp->l.head = nullptr;
	return sp;
}

void stackPush(StackPtr s, Element x){
	if(s){
		listInsert(&(s->l), x, 1); 	
	}
}

Element stackTop(StackPtr s){
	Element e = ' ';
	if(s == nullptr || s->l.head == nullptr){
		set_error(1);
	}
	else{
		// -------------------
		// ListNodePtr ptr = listRetrieve(&(s->l), 1);
		// e = ptr->key;
		// ------------------
		
		// ------------------
		// e = listRetrieve(&(s->l), 1)->key;
		// ------------------
		
		e =  s->l.head->key;
	}
	return e;
}

Element stackPop(StackPtr s){
	Element e;
	if(s == nullptr || s->l.head == nullptr){
		set_error(1);
	}
	else{
		e = listRetrieve(&(s->l), 1)->key;
		listRemove(&(s->l), 1);
	}
	return e;
}

bool stackEmpty(StackPtr s){
	bool empty = false;
	if(s){
		if(s->l.head == nullptr){
			empty = true;
		}
	}
	return empty;
}


