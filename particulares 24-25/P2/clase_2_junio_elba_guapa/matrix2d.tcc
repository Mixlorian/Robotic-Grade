#include "matrix2d.h"

namespace C4{

template <typename U>
ostream &operator<<(ostream &os, const Matrix2d<U> &ma){
    for(int i = 0; i < ma.m.size(); i++){
        for(int j = 0; j< ma.m[i].size(); j++){
            os << ma.m[i][j] << ",";
        }
        os << endl;
    }
    return os;
}

template <typename T>
Matrix2d<T>::Matrix2d(size_t rows, size_t cols, T initval){
    m = vector<vector<T>>(rows, vector<T>(cols,initval));
}

template <typename T>
std::vector<T> &Matrix2d<T>::operator[](size_t r){
    return m[r];
}

// PROPUESTO:
// Si las matrices no son compatibles en tamaño
// se rellenaran con 0s.

// no lo pone ni de coña
template <typename T>
Matrix2d<T> Matrix2d<T>::operator+(const Matrix2d<T> &m2) const{
    int rows = m.size(), rows2 = m2.m.size(), 
        cols = m[0].size(), cols2 = m2.m[0].size();
    Matrix2d<T> res(max(rows, rows2), max(cols,m2.cols),0);
    int v1,v2;
    for(int i = 0; i < min(rows, rows2); i++){
        for(int j = 0; j < min(cols, cols2); j++){
            v1 = v2 = 0;
            if(i < m.size() && j < m[0].size()){
                v1 = m[i][j];
            }
            if(i < m2.m.size() && j < m2.m[0].size()){
                v2 = m2.m[i][j];
            }
            res.m[i][j] = v1 + v2;
        }
    }
    return res;
}


// m(3, 4) = 12;
template <typename T>
T &Matrix2d<T>::operator()(int i, int j){
    // return m[i][j];
    if(i >= 0 && i < m.size() && j >= 0 && j < m[0].size()){
        return m[i][j];
    }
    else{
        T error;                //esto es una variable local
        return error;           // la variable no exite fuera de la funcion
    }
}

template <typename T>
Matrix2d<T> & 
Matrix2d<T>::operator+=(const Matrix2d<T> &m2){
    *this = *this + m2;
    //Matrix2d = Matrix2d + Matrix2d
    return *this;
}

template <typename T>
bool Matrix2d<T>::operator==(const Matrix2d<T> &m2) const{
    bool iguales = false;

    if(m.size() == m2.m.size() && m[0].size() == m2.m[0].size()){
        iguales = true;
        for(int i = 0; i < m.size() && iguales; i++){
            for(int j = 0; j < m[0].size() && iguales; j++){
                if(m[i][j] != m2.m[i][j]){
                    iguales = false;
                }
            }
        }
    }

    return iguales;
}

template <typename T>
bool Matrix2d<T>::operator!=(const Matrix2d<T> &m2) const{
    return !(*this == m2);
}


}


