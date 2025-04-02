// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "stack.h"
#include "list.h"
#include "lib/error.h"

StackPtr stackCreate (){
	StackPtr sp = nullptr;
	sp = new Stack; 
	sp->l.head = nullptr;
	return sp;
}

void     stackPush   (StackPtr s, Element x){
	if(s){
		listInsert(&(s->l), x, 1); 	
	}
}

Element  stackTop    (StackPtr s){
	Element e = ' ';
	if(s == nullptr || s->l.head == nullptr){
		set_error(1);
	}
	else{
		e =  s->l.head->key;
	}
	return e;
}

Element  stackPop    (StackPtr s){
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

bool     stackEmpty  (StackPtr s){
	bool empty = false;
	if(s){
		if(s->l.head == nullptr){
			empty = true;
		}
	}
	return empty;
}
