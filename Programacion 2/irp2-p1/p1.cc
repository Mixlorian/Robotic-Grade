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
            e.data[i] = new etype_t[subjects]
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