#include "matrix2d.h"
#include <iostream>
using namespace std;

namespace C4 {

    Matrix2d::Matrix2d(size_t rows, size_t cols, T initval){
        m = vector<vector<T>>(rows, vector<T>(cols,initval));
    };

    void Matrix2d::print_matrix(){
        for(size_t i = 0; i < m.size(); i++){
            for(size_t j =0; j< m[0].size(); j++){
                cout << m[i][j] << "," ;
            }
            cout << endl;
        }
    };
    
    std::vector<T>& Matrix2d::operator[] (size_t r){
        return m[r];
    };
    Matrix2d Matrix2d::operator+ (const Matrix2d& m2){
        size_t rows = m.size();
        size_t cols = m[0].size();

        Matrix2d result(rows,cols,0);
        for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                result.m[i][j] = m[i][j] + m2.m[i][j];
            };
        };
        return result;
    }

}  // C4
