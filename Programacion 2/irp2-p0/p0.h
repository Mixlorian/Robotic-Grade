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
#ifndef P0_H
#define P0_H


/*********************************************************************/
/* Documentación en https://en.cppreference.com/w/cpp/header/cstdint */
/*********************************************************************/
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

/**
* \brief Ejercicio 1
*
* Esta función devuelve un vector de cadenas en el que cada componente
* representa una palabra.
*
* \param s La frase que contiene las palabras.
* \param c El carácter separador entre palabras.
* \return Un vector de cadenas.
*/
std::vector<std::string> split_on(const std::string &s, char c);

#endif /* P0_H */
