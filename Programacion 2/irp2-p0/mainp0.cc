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

#include "p0.h"
#include <iostream>

using Collection = std::vector<std::string>;

void print_vector(const Collection &c) {
  for (auto &e : c) {
    std::cout << "· " << e << '\n';
  }
}

int main()
{
  std::string s = "-Practica-0 de programacion II. GIR.";
  Collection c1 = split_on(s, ' ');
  Collection c2 = split_on(s, '-');
  Collection c3 = split_on(s, '.');

  cout << "Sentence: " << s << "\n----------\n";
  cout << "Separator [ ]:\n";
  print_vector(c1);
  cout << '\n';

  cout << "Separator [-]:\n";
  print_vector(c2);
  cout << '\n';

  cout << "Separator [.]:\n";
  print_vector(c3);
  cout << '\n';

  return 0;
}
