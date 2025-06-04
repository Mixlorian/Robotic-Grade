#ifndef _MATRIX2D_H_
#define _MATRIX2D_H_
#include <iostream>
#include <vector>
using namespace std;

namespace C4{

template <typename T>
class Matrix2d{
	template <typename U>
	friend ostream &operator<<(ostream &os, const Matrix2d<U> &ma);
	private:
		vector<vector<T>> m;
	public:
		Matrix2d(size_t rows, size_t cols, T initval);
		std::vector<T> &operator[](size_t r);
		Matrix2d<T> operator+(const Matrix2d<T> &m2) const;
		T &operator()(int i, int j);
		Matrix2d<T> &operator+=(const Matrix2d<T> &m2);
		bool operator==(const Matrix2d<T> &m2) const;
		bool operator!=(const Matrix2d<T> &m2) const;
};

}

#include "matrix2d.tcc"

#endif
