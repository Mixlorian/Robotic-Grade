// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "list.h"

// Constructor por defecto
ListPtr listCreate        (){
	ListPtr ptrList = new List;
	ptrList->head = nullptr;
	return ptrList;
}

ListNodePtr listNodeCreate(Element e){
	ListNodePtr pn = new ListNode;
	pn->key = e;
	pn->next = nullptr;
	return pn;
}

// Inicializacion de datos a valores seguros
void listInit             (ListPtr l){
	if(l != nullptr){
		l->head = nullptr;		
	}
}

// Insert
bool listInsert           (ListPtr l, Element x, Position i){
	bool inserted = false;
	ListNodePtr ptn, ptl, pta;
	if(l != nullptr){
		if(i >= 1){
			ptn = listNodeCreate(x);
			pta = nullptr;
			ptl = l->head;
			for(int c = 1; c < i && ptl; c++){
				pta = ptl;
				ptl = ptl->next;
			}
			if(pta != nullptr){
				pta->next = ptn;
			}
			else{
				l->head = ptn;
			}
			ptn->next = ptl;
			inserted = true;
		}
	}
	return inserted;
}

// Locate
Position listLocate       (ListPtr l, Element x){
	Position pos = NOPOS;
	ListNodePtr ptl;
	Position actual = 1;
	if(l != nullptr){
		ptl = l->head;
		while(ptl && pos == NOPOS){
			if(ptl->key == x){
				pos = actual;
			}
			else{
				ptl = ptl->next;
			}
			actual++;
		}
	}
	return pos;
}

// Retrieve
ListNodePtr listRetrieve  (ListPtr l, Position i){
	ListNodePtr ptr = nullptr;
	if(l != nullptr && i >= 1){
		ptr = l->head;
		for(int c = 1; c < i && ptr; c++){
			ptr = ptr->next;
		}	
	}
	return ptr;
}

// Elimina el elemento en la posicion p
bool listRemove           (ListPtr l, Position p){
	bool removed = false;
	ListNodePtr ptl, pta;
	
	if(l != nullptr && p >= 1){
		pta = nullptr;
		ptl = l->head;
		for(int i = 1; i < p && ptl; i++){
			pta = ptl;
			ptl = ptl->next;
		}	
		if(ptl){	
			if(pta){
				pta->next = ptl->next;
			}
			else{
				l->head = ptl->next;
			}
			delete ptl;
			removed = true;
		}
	}
	return removed;
}

// Vacia la lista
void listMakeNull         (ListPtr l){
	ListNodePtr ptr = nullptr;
	if(l){
		while(l->head){
			ptr = l->head;
			l->head = l->head->next;
			delete ptr;
		}
	}
}

// Primer elemento
ListNodePtr listFirst     (ListPtr l){
	ListNodePtr ptr = nullptr;
	if(l != nullptr){
		ptr = l->head;
	}
	return ptr;
}

// Devuelve el número de elementos en la lista
uint64_t listSize         (ListPtr l){
	uint64_t longitud;
	ListNodePtr ptl;
	longitud = 0;
	if(l != nullptr){
		ptl = l->head;
		while(ptl){
			longitud++;
			ptl = ptl->next;
		}
	}
	return longitud;
}