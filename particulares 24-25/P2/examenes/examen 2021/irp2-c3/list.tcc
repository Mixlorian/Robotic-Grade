#ifndef _LIST_TCC_
#define _LIST_TCC_
#include "list.h"
#include "node.tcc"

namespace C3{

	template <typename U>
	ostream &operator<<(ostream &os, const List<U> &lista){
		os << "<";
		for(NodePtr<U> p = lista.first; p; p = p->get_next()){
			os << p->get_key();
			if(p->get_next()){
				os << ", ";
			}
		}
		os << ">";
		return os;
	}
 
	template <typename T>
	List<T>::List(){
		first = last = nullptr;	
		nNodes = 0;
	}

	template <typename T>
	List<T>::~List(){
		NodePtr<T> p;

		while((p = first)){
			first = first->get_next();
			delete p;
		}
		nNodes = 0;
	}

	template <typename T>
	uint32_t List<T>::length() const{
		return nNodes;	
	}

	// posicion desde 1.
	// posicion mas alla de la lista inserta al final de la puta lista.
	template <typename T>
	bool List<T>::insert_at(uint32_t p, const T& k){
		bool insertado = false;
		NodePtr<T> pta, ptl, ptn;
		uint32_t c;
		
		if(p > 0){
			pta = nullptr;
			ptl = first;
			c = 1;
			while(ptl && c < p){
				pta = ptl;
				ptl = ptl->get_next();
				c++;
			}
			insertado = true;
			ptn = new Node<T>(k);
			ptn->set_next(ptl);
			ptn->set_prev(pta);
			if(pta != nullptr){
				pta->set_next(ptn);
			}
			else{
				first = ptn;
			}
			if(ptl){
				ptl->set_prev(ptn);
			}
			else{
				last = ptn;
			}
			nNodes++;
		}
		return insertado;		
	}

	template <typename T>
	bool List<T>::insert_front(const T& k){
		return insert_at(1, k);
	}

	template <typename T>
	bool List<T>::insert_back(const T& k){
		return insert_at(nNodes + 1, k);
	}

	template <typename T>
	void List<T>::for_each(fn_t<T> f){
		for(NodePtr<T> p = first; p; p = p->get_next()){
			// le paso la direccion de cada uno de los nodos
			// de la lista.
			f(p);
		}
	}

	template <typename T>
	void List<T>::for_each_reverse(fn_t<T> f){
		for(NodePtr<T> p = last; p; p = p->get_prev()){
			// le paso la direccion de cada uno de los nodos
			// de la lista.
			f(p);
		}		
	}
}
#endif

