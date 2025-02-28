// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "p1.h"
#include <iostream>
using namespace std;
#include <vector>
#include <cstdint>
#include <algorithm>


//Funciones para crear un registro de Evaluations utilizando memporia dinámica 
// para construir los datos de acuerdo a la cantidad de estudiantes y asignaturas
Evaluations mreserve(uint32_t students, uint32_t subjects, etype_t v){
    Evaluations e = empty_evaluations;
    if(students > 0 && subjects > 0 && v >= 0 && v <= 10){
        e.students = students;
        e.subjects = subjects;
        e.data = new student_t[students]; 
        for(uint32_t i = 0; i < students; i++){
            e.data[i] = new etype_t[subjects];
        }

        for(uint32_t i = 0; i < students; i++){
            for(uint32_t j = 0; j< subjects; j++){
                e.data[i][j]= v;
            }
        }
    }
    return e;
}

// Libera la memoria creada con memoria dinámica
void mfree(Evaluations& e){
    
    if(e.data != nullptr){
        for(uint32_t i = 0; i < e.students; i++){
            delete[] e.data[i];
        }
        delete[] e.data;
        e.data = nullptr;
        e.students = 0;
        e.subjects;
    }
}

//Visualiza en pantalla los datos de las notas en forma de matriz. Las filas son los estudiantes y las columnas las asignaturas.
void mshow(const Evaluations& e){
    if(e.data != nullptr){
        for(uint32_t i =0; i < e.students; i++){
            cout << "[ ";
            for(uint32_t j = 0; j < e.subjects; j++){
                cout << e.data[i][j] << " ";
            }
            cout << "]";
        }
    }
}

// Función para modificar la evaluación de un alumno en una determinada asignatura
void modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation){
    if(student_idx >= 0 && student_idx < e.students && subject_idx >= 0 && subject_idx < e.subjects && new_evaluation >= 0 && new_evaluation <= 10){
        e.data[student_idx][subject_idx] = new_evaluation;
    }
}

bool search_element(const std::vector<uint32_t> &st, uint32_t element){
    bool encontrado = false;
    for(int i = 0; i < st.size() && !encontrado; i++){
        if(st[i] == element){
            encontrado = true;
        }
    }
    return encontrado;
}

std::vector<uint32_t> get_right_elements(const std::vector<uint32_t> &v, uint32_t limit){
    std::vector<uint32_t> resultado;
    for(uint32_t idx : v){
        if(idx < limit){
            if(!search_element(resultado, idx)){
                resultado.push_back(idx);
            }
        }
    }
    return resultado;
}

// Función que filtra las evaluaciones creando un nuevo registro con una copia de las evaluaciones para determinados estudiantes y asignaturas.
Evaluations filter(const Evaluations& m, const std::vector<uint32_t> &student_idxs, const std::vector<uint32_t> &subject_idxs){
    Evaluations resultado = empty_evaluations;
    uint32_t fila, columna;

    vector<uint32_t> stu_idxs = get_right_elements(student_idxs, m.students);
    vector<uint32_t> sub_idxs = get_right_elements(subject_idxs, m.subjects);

    resultado = mreserve(stu_idxs.size(), sub_idxs.size());

    for(uint32_t i = 0; i < stu_idxs.size(); i++){
        fila = stu_idxs[i];
        for(uint32_t j = 0; j < sub_idxs.size(); j++){
            columna = sub_idxs[j];
            resultado.data[i][j] = m.data[fila][columna];
        }
        cout << endl;
    }
    return resultado;
}

// Función que devuelve el promedio de las evaluaciones por asignatura en forma de vector.
std::vector<etype_t> average_per_subject(const Evaluations& m){
    std::vector<etype_t> resultado;
    uint32_t suma;
    for(uint32_t j = 0; j < m.subjects; j++){ // fijo la columna
        suma = 0;
        for(uint32_t i = 0; i < m.students; i++){ // recorro la fila 
            suma += m.data[i][j];
        }
        resultado.push_back(suma / m.students);
    }
    return resultado;
}

// Función que devuelve el promedio de las evaluaciones por estudiante en forma de vector.
std::vector<etype_t> average_per_student(const Evaluations& m){
    std::vector<etype_t> resultado;
    uint32_t suma;
    for(uint32_t i = 0; i < m.students; i++){
        suma = 0;
        for(uint32_t j = 0; j < m.subjects; j++){
            suma += m.data[i][j];
        }
        resultado.push_back(suma / m.subjects);
    }

    return resultado;
}