/* -*- mode C++ -*-
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

#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <vector>

namespace C4 {

  using T = int32_t;

  class Matrix2d {
  public:
    Matrix2d(size_t rows, size_t cols, T initval);

    void print_matrix();
    std::vector<T>& operator[] (size_t r);
    Matrix2d operator+ (const Matrix2d& m2);

  private:
    std::vector<std::vector<T>> m;
  };
}  // C4

#endif /* MATRIX_H */
