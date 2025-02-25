
#ifndef P1_H
#define P1_H

#include <iostream>
using namespace std;
#include <vector>
#include <cstdint>

// -- Typdefs: ------------------------------------------------------------
/** El tipo de los elementos de la matriz de bajo nivel. */
using etype_t  = uint32_t;
/// El tipo de la fila de la matriz de bajo nivel
using student_t    = etype_t*;
//! El tipo matriz de bajo nivel.
using matrix_t = student_t*;

// Estructura que contiene los datos de la matriz de evaluaciones
struct Evaluations {
    uint32_t students;
    uint32_t subjects;
    matrix_t data;
};

// Constante que representa un dato de tipo Evaluations que no tiene información
// (con la matriz nula y número de estudiantes y de asignaturas con el valor 0)
const Evaluations empty_evaluations = {0, 0, nullptr};

// Funciones a implementar:

// Funciones para crear un registro de Evaluations utilizando memoria dinámica
// para construir los datos de acuerdo a la cantidad de estudiantes y asignaturas
Evaluations mreserve(uint32_t students, uint32_t subjects, etype_t v=0);

// Libera la memoria creada con memoria dinámica
void mfree(Evaluations& e);

//Visualiza en pantalla los datos de las notas en forma de matriz. Las filas son los estudiantes y las columnas las asignaturas.
void mshow(const Evaluations& e);

// Función para modificar la evaluación de un alumno en una determinada asignatura
void modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation);



// Función que filtra las evaluaciones creando un nuevo registro con una copia de las evaluaciones para determinados estudiantes y asignaturas.
Evaluations filter(const Evaluations& m, const std::vector<uint32_t> &student_idxs, const std::vector<uint32_t> &subject_idxs);

// Función que devuelve el promedio de las evaluaciones por asignatura en forma de vector.
std::vector<etype_t> average_per_subject(const Evaluations& m);

// Función que devuelve el promedio de las evaluaciones por estudiante en forma de vector.
std::vector<etype_t> average_per_student(const Evaluations& m);

#endif // P1_H

// Funciones para crear un registro de Evaluations utilizando memoria dinámica
// para construir los datos de acuerdo a la cantidad de estudiantes y asignaturas
Evaluations mreserve(uint32_t students, uint32_t subjects, etype_t v){
    Evaluations e = empty_evaluations;
    if(students > 0 && subjects > 0 && v >= 0 && v <= 10){
        e.students = students;
        e.subjects = subjects;
        e.data = new student_t [students]; // student_t *
        // e.data = new uint32_t * [students];
        for(uint32_t i = 0; i < students; i++){
            e.data[i] = new etype_t [subjects];
            // e.data[i] = new uint32_t [subjects];
        }

        for(uint32_t i = 0; i < students; i++){
            for(uint32_t j = 0; j < subjects; j++){
                e.data[i][j] = v;
            }
        }
    }
    return e;
}

// Libera la memoria creada con memoria dinámica
void mfree(Evaluations& e){
    if(e.data != nullptr){
        for(int i = 0; i < e.students; i++){
            delete [] e.data[i];
        }
        delete [] e.data;
        e.data = nullptr;
        e.students = 0;
        e.subjects = 0;
    }
}

//Visualiza en pantalla los datos de las notas en forma de matriz. Las filas son los estudiantes y las columnas las asignaturas.
void mshow(const Evaluations& e){
    if(e.data != nullptr){
        for(uint32_t i = 0; i < e.students; i++){
            cout << "[ ";
            for(uint32_t j = 0; j < e.subjects; j++){
                cout << e.data[i][j] << " ";
            }
            cout << "]" << endl;
        }
    }
}

// Función para modificar la evaluación de un alumno en una determinada asignatura
void modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation){
    if(student_idx >= 0 && student_idx < e.students && subject_idx >= 0 && subject_idx < e.subjects && new_evaluation >= 0 && new_evaluation <= 10){
        e.data[student_idx][subject_idx] = new_evaluation;
    }	}


#include <algorithm>

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
            //if(find(stu_idxs.begin(), stu_idxs.end(), idx) == stu_idxs.end()){
            //    stu_idxs.push_back(idx);
            //}
            // si ya tengo almacenada la fila 2, no la almaceno.
            if(!search_element(resultado, idx)){
                resultado.push_back(idx);
            }
        }
    }
    return resultado;
}

// students_idxs = <3, -1, 2>
// subjects_idxs = <0, 1, 5>
// Función que filtra las evaluaciones creando un nuevo registro con una copia de las evaluaciones para determinados estudiantes y asignaturas.
Evaluations filter(const Evaluations& m, const std::vector<uint32_t> &student_idxs, const std::vector<uint32_t> &subject_idxs){
    Evaluations resultado = empty_evaluations;
    uint32_t fila, columna;

    vector<uint32_t> stu_idxs = get_right_elements(student_idxs, m.students);
    vector<uint32_t> sub_idxs = get_right_elements(subject_idxs, m.subjects);

 /*
    vector<uint32_t> stu_idxs, sub_idxs;

    for(uint32_t idx : student_idxs){
        if(idx < m.students){
            //if(find(stu_idxs.begin(), stu_idxs.end(), idx) == stu_idxs.end()){
            //    stu_idxs.push_back(idx);
            //}
            if(!search_element(stu_idxs, idx)){
                stu_idxs.push_back(idx);
            }
        }
    }

    for(uint32_t idx : subject_idxs){
        if(idx < m.subjects){
            //if(find(stu_idxs.begin(), stu_idxs.end(), idx) == stu_idxs.end()){
            //    stu_idxs.push_back(idx);
            //}
            if(!search_element(stu_idxs, idx)){
                stu_idxs.push_back(idx);
            }
        }
    }
*/

    resultado = mreserve(stu_idxs.size(), sub_idxs.size());

    for(uint32_t i = 0; i < stu_idxs.size(); i++){
        fila = stu_idxs[i];
        for(uint32_t j = 0; j < sub_idxs.size(); j++){
            columna = sub_idxs[j];
            resultado.data[i][j] = m.data[fila][columna];
            // cout << m.data[fila][columna] << " "; // en vez de imprimirlo lo almacenamos en i, j
            //          	    3               0
            //                  3               1
            //                  3               5
        }
        cout << endl;
    }

    // Contamos cuantos indices validos hay en student_idxs (recorrer el vector y comprobar que estan entre 0 y e.students - 1)


    // Contamos cuantos indices validos hay en subjects_idxs (recorrer el vector y comprobar que estan entre 0 y e.subjects - 1)

    // Mas de 0 en los dos.

    // Creamos una matriz que tenga tantas filas y tantas columnas como los dos anteriores (usa la primera funcion)

    // Recorro student_idxs
    // 	Si es valido
    //		 Recorro los subjects_ids
    //			si es valido
    //				Lo almaceno en su posicion en la matriz.


    return resultado;
}

// Función que devuelve el promedio de las evaluaciones por asignatura en forma de vector.
std::vector<etype_t> average_per_subject(const Evaluations& m){
    std::vector<etype_t> resultado;
    uint32_t suma;
    for(uint32_t j = 0; j < m.subjects; j++){ // fijo la columna
        suma = 0;
        for(uint32_t i = 0; i < m.students; i++){ // recorro la fila :) je je
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

/*
 * Copyright (C) 2024
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


int main() {
    // Crear una matriz de evaluaciones para 3 estudiantes y 4 asignaturas
    Evaluations evaluations = mreserve(3, 4);

    // Rellenar algunas notas de ejemplo
    modify_evaluation(evaluations, 0, 0, 7);  // Estudiante 0, Asignatura 0: nota 7
    modify_evaluation(evaluations, 0, 1, 5);  // Estudiante 0, Asignatura 1: nota 5
    modify_evaluation(evaluations, 0, 2, 9);  // Estudiante 0, Asignatura 2: nota 9
    modify_evaluation(evaluations, 0, 3, 6);  // Estudiante 0, Asignatura 3: nota 6

    modify_evaluation(evaluations, 1, 0, 4);  // Estudiante 1, Asignatura 0: nota 4
    modify_evaluation(evaluations, 1, 1, 8);  // Estudiante 1, Asignatura 1: nota 8
    modify_evaluation(evaluations, 1, 2, 6);  // Estudiante 1, Asignatura 2: nota 6
    modify_evaluation(evaluations, 1, 3, 7);  // Estudiante 1, Asignatura 3: nota 7

    modify_evaluation(evaluations, 2, 0, 9);  // Estudiante 2, Asignatura 0: nota 9
    modify_evaluation(evaluations, 2, 1, 6);  // Estudiante 2, Asignatura 1: nota 6
    modify_evaluation(evaluations, 2, 2, 5);  // Estudiante 2, Asignatura 2: nota 5
    modify_evaluation(evaluations, 2, 3, 8);  // Estudiante 2, Asignatura 3: nota 8

    // Mostrar la matriz completa
    std::cout << "Matriz de evaluaciones completa:" << std::endl;
    mshow(evaluations);

    // Calcular promedios por asignatura
    std::vector<etype_t> subject_avgs = average_per_subject(evaluations);
    std::cout << "\nPromedios por asignatura:" << std::endl;
    for (size_t i = 0; i < subject_avgs.size(); ++i) {
        std::cout << "Asignatura " << i << ": " << subject_avgs[i] << std::endl;
    }

    // Calcular promedios por estudiante
    std::vector<etype_t> student_avgs = average_per_student(evaluations);
    std::cout << "\nPromedios por estudiante:" << std::endl;
    for (size_t i = 0; i < student_avgs.size(); ++i) {
        std::cout << "Estudiante " << i << ": " << student_avgs[i] << std::endl;
    }

    // Ejemplo de filtrado de matriz (seleccionar estudiantes y asignaturas específicos)
    std::vector<uint32_t> selected_students = {0, 2};
    std::vector<uint32_t> selected_subjects = {1, 3};

    Evaluations filtered_evaluations = filter(evaluations, selected_students, selected_subjects);

    std::cout << "\nMatriz filtrada (estudiantes 0 y 2, asignaturas 1 y 3):" << std::endl;
    mshow(filtered_evaluations);

    // !!!AÑADIDOS!!!
    // LA MATRIZ ORIGINAL ES DE 3 X 4
    std::vector<uint32_t> selected_students2 = {0, 2, 0, 200};      // 0 2
    std::vector<uint32_t> selected_subjects2 = {1, 3, 3, 0, 12, 3}; // 1 3 0

    std::cout << endl;
    Evaluations sfinter_evaluations2 = filter(evaluations, selected_students2, selected_subjects2);
    mshow(sfinter_evaluations2);

    uint32_t corbi = 300;
    std::vector<uint32_t> selected_students3 = {200, 200};      // 0 2
    std::vector<uint32_t> selected_subjects3 = {corbi, corbi}; // 1 3 0

    cout << "======" << endl;
    Evaluations anal_evaluations2 = filter(evaluations, selected_students3, selected_subjects3);
    mshow(anal_evaluations2);
    cout << anal_evaluations2.students << endl;
    cout << anal_evaluations2.subjects << endl;
    cout << "======" << endl;

    // Liberar memoria
    mfree(evaluations);
    mfree(filtered_evaluations);

    std::vector<uint32_t> devil_anal_andres_sub = {200, 200};      // 0 2
    std::vector<uint32_t> devil_anal_andres_stu = {0}; // 1 3 0

    cout << "====" << endl;
    Evaluations oral_andrew_evaluations2 = filter(evaluations, devil_anal_andres_stu, devil_anal_andres_sub);
    mshow(oral_andrew_evaluations2);
    cout << oral_andrew_evaluations2.students << endl;
    cout << oral_andrew_evaluations2.subjects << endl;
    cout << "====" << endl;

    // mreserve proof
    Evaluations limon = mreserve(0, 4);
    cout << "students: " << limon.students << endl;
    cout << "subjects: "  << limon.subjects << endl;
    cout << (limon.data == nullptr) << endl; // imprime 1 si es nullptr

    Evaluations naranja = mreserve(2, 4, 12);
    cout << "students: " << naranja.students << endl;
    cout << "subjects: "  << naranja.subjects << endl;
    cout << (naranja.data == nullptr) << endl; // imprime 1 si es nullptr

    Evaluations pomelo = mreserve(1, 1, 10);
    cout << "students: " << pomelo.students << endl;
    cout << "subjects: "  << pomelo.subjects << endl;
    cout << (naranja.data == nullptr) << endl; // imprime 1 si es nullptr
    mshow(pomelo);

    // modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation){

    // si
    modify_evaluation(pomelo, 0, 0, 8);
    mshow(pomelo); // [8]
    cout << endl;

    // no
    modify_evaluation(pomelo, 1, 0, 9);
    mshow(pomelo); // [8]
    cout << endl;

    // no
    modify_evaluation(pomelo, 0, 1, 1);
    mshow(pomelo); // [8]
    cout << endl;

    // si
    modify_evaluation(pomelo, 0, 0, 0);
    mshow(pomelo); // [0]
    cout << endl;

    // no
    modify_evaluation(pomelo, 0, 0, 11);
    mshow(pomelo); // [0]
    cout << endl;


    return 0;

}





