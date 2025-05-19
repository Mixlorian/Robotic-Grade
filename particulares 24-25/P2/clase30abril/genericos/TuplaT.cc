#include "TuplaT.h"

template <class T>
// estamos usando el constructor por defecto del tipo T
TuplaT<T>::TuplaT()/*:first(), second()*/{
}

template <class T>
// estamos usando el constructor copia del tipo T
TuplaT<T>::TuplaT(T f, T s):first(f), second(s){

}

template <class T>
T TuplaT<T>::getFirst() const{
	return first;
}

template <class T>
T TuplaT<T>::getSecond() const{
	return second;
}


template <class T>
// estamos usando el operador == del tipo T
bool TuplaT<T>::operator==(const TuplaT<T> &de) const{
	return first == de.first && second == de.second;
}

template <class T>
bool TuplaT<T>::operator!=(const TuplaT<T> &de) const{
	return !(*this == de);
}

