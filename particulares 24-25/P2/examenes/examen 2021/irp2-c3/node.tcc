#include "node.h"
#ifndef _NODE_TCC_
#define _NODE_TCC_
namespace C3 {
	template <typename T>
	Node<T>::Node(const T& k):key(k), next(nullptr), prev(nullptr){
		
	}

	template <typename T>
	Node<T>::~Node(){
		prev = next = nullptr;
	}

	template <typename T>
	T& Node<T>::get_key(){
		return key;
	}

	template <typename T>
	const T& Node<T>::get_key() const{
		return key;
	}
	
	template <typename T>
	NodePtr<T> Node<T>::get_next() const{
		return next; 
	}

	template <typename T>
	void Node<T>::set_next(NodePtr<T> n){
		next = n;
	}

	template <typename T>
	NodePtr<T> Node<T>::get_prev() const{
		return prev;
	}

	template <typename T>
	void Node<T>::set_prev(NodePtr<T> n){
		prev = n;
	}

	template <typename T>
	bool Node<T>::has_next() const{
		return next != nullptr; 
	}

	template <typename T>
	bool Node<T>::has_prev() const{
		return prev != nullptr;
	}
}
#endif

