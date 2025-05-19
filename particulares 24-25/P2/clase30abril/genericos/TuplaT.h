#ifndef _TUPLAT_H_
#define _TUPLAT_H_
#include <iostream>
using namespace std;

template <class T>
class TuplaT{
	private:
		T first, second;
	public:
		TuplaT();
		TuplaT(T f, T s);
		
		T getFirst() const;
		T getSecond() const;
		bool operator==(const TuplaT<T> &de) const;
		bool operator!=(const TuplaT<T> &de) const;
};
#endif
