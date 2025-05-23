/*
 * Copyright (C) 2023
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

#include "msort.cc"
#include <cstdint>
#include <iostream>

using namespace std;

template <typename T>
void print_vector(vector<T>& v) {
  cout << "[ ";
  for (auto i = 0u; i < v.size(); i++)
    if (i != (v.size()-1))
      cout << v[i] << ", ";
    else
      cout << v[i];
  cout << " ]\n";
}

int main(int argc, char *argv[])
{
  vector<int32_t> v1 {4,5,3,7};
  vector<int32_t> v2 {7, 4, -5, 1, 2, 3, 6};

  vector<int32_t> v1s = C3::mergesort(v1);
  vector<int32_t> v2s = C3::mergesort(v2);

  cout << "V1 unsorted:";
  print_vector(v1);

  cout << "V1 sorted:  ";
  print_vector(v1s);

  cout << "V2 unsorted:";
  print_vector(v2);

  cout << "V2 sorted:  ";
  print_vector(v2s);

  return 0;
}
