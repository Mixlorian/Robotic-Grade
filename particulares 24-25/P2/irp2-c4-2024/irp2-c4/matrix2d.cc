#include "matrix2d.h"
#include <iostream>
using namespace std;

namespace C4 {

    Matrix2d::Matrix2d(size_t rows, size_t cols, T initval){
        for(i = 0; i < rows; i++){
            for(j =0; j< cols; j++){
                m[i][j]=initval;
            }
        }
    };

    void Matrix2d::print_matrix(){
        for(i = 0; i < rows; i++){
            for(j =0; j< cols; j++){
                cout << m[i][j] << "," ;
            }
            cout << endl;
        }
    };
    
    std::vector<T>& Matrix2d::operator[] (size_t r){
        if(r >= rows)
    };
    Matrix2d operator+ (const Matrix2d& m2);

}  // C4
