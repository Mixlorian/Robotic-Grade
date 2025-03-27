#include "list.h"

// Constructor por defecto
ListPtr listCreate(){
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

// Locate
Position listLocate(ListPtr l, Element x){
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
/*		
		for(int i = 1; ptl && pos == NOPOS; i++){
			if(ptl->key == x){
				pos = actual;
			}
			else{
				ptl = ptl->next;
			}
		}
*/		
	}
	return pos;
}

bool listInsert(ListPtr l, Element x, Position i){
	bool inserted = false;
	ListNodePtr ptn, ptl, pta;
	
	if(l != nullptr){
		if(i >= 1){
			ptn = listNodeCreate(x);
			inserted = true;
			if(l->head == nullptr){
				l->head = ptn;
			}
			else{
				pta = nullptr;
				ptl = l->head;
				for(int c = 1; c < i && ptl; c++){
					pta = ptl;
					ptl = ptl->next;
				}
				if(pta == nullptr){
					ptn->next = l->head;
					l->head = ptn;
				}
				else{
					if(ptl == nullptr){
						pta->next = ptn;
						ptn->next = nullptr;
					}
					else{
						pta->next = ptn;
						ptn->next = ptl;
					}
				}
			}
		}
	}
	return inserted;
}

bool listInsertOK(ListPtr l, Element x, Position i){
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

void listInit(ListPtr l){
	if(l != nullptr){
		l->head = nullptr;		
	}
}

uint64_t listSize(ListPtr l){
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



// Primer elemento
// devuelve la direccio del primer nodo de la lista.
ListNodePtr listFirst(ListPtr l){
	ListNodePtr ptr = nullptr;
	if(l != nullptr){
		ptr = l->head;
	}
	return ptr;
}

ListNodePtr listRetrieve(ListPtr l, Position i){
	ListNodePtr ptr = nullptr;
	if(l != nullptr && i >= 1){
		ptr = l->head;
		for(int c = 1; c < i && ptr; c++){
			ptr = ptr->next;
		}	
	
	}
	return ptr;
}

bool listRemove(ListPtr l, Position p){
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

void listMakeNull(ListPtr l){
	ListNodePtr ptr = nullptr;
	
	if(l){
		ptr = l->head;
		while(ptr){
			l->head = l->head->next;
			delete ptr;
			ptr = l->head;
		}
	}
}

void listMakeNullOK(ListPtr l){
	ListNodePtr ptr = nullptr;
	
	if(l){
		while(l->head){
			ptr = l->head;
			l->head = l->head->next;
			delete ptr;
		}
	
	}

}












