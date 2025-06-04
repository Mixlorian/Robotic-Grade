// Copyright (C) 2024
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include "matrix2d.tcc"

int main(int argc, char *argv[])
{
  C4::Matrix2d m(3, 4, -3);
  C4::Matrix2d m2(m);

  std::cout << std::endl << "M:\n";
  m.print_matrix();

  m(0, 0) = 10;
  m(0, 3) = 10;
  m(1, 1) = 0;
  m(1, 2) = 0;
  m(2, 0) = 10;
  m(2, 3) = 10;

  std::cout << std::endl << "M':\n";
  m.print_matrix();

  std::cout << std::endl << "M2:\n";
  m2.print_matrix();

  auto sm = m + m2;
  std::cout << std::endl << "SUM M'+M2:\n";
  sm.print_matrix();

  return 0;
}
