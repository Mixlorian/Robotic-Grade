
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

namespace C4 {

    using T = int32_t;

    template <typename T>
    class Matrix2d {
        public:
            Matrix2d(size_t rows, size_t cols, T initval);

            void print_matrix();
            vector<T>& operator[] (size_t r);
            Matrix2d operator+ (const Matrix2d& m2);
            T& operator() (size_t r, size_t c);

        private:
            std::vector<std::vector<T>> m;
    };

    template <typename T>
    Matrix2d<T>::Matrix2d(size_t rows, size_t cols, T initval){
        m = vector<vector<T>>(rows, vector<T>(cols,initval));
    };

    template <typename T>
    void Matrix2d<T>::print_matrix(){
        for(size_t i = 0; i < m.size(); i++){
            for(size_t j =0; j< m[0].size(); j++){
                cout << m[i][j] << "," ;
            };
            cout << endl;
        };
    };

    template <typename T>
    vector<T>& Matrix2d<T>::operator[] (size_t r){
        return m[r];
    };

    template <typename T>
    T& Matrix2d<T>::operator()(size_t row, size_t col){
        return m[row][col];
    };

    template <typename T>
    Matrix2d<T> Matrix2d<T>::operator+ (const Matrix2d& m2){
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