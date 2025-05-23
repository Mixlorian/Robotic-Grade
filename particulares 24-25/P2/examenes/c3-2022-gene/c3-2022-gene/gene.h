// -*- mode: c++ -*-
/*
 * Copyright (C) 2022
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

#ifndef GENE_H
#define GENE_H

#include <iostream>
#include <boost/signals2.hpp>

using namespace std;

namespace C3 {
  class Gene{
  public:
    Gene(char d);
    Gene(const Gene& g);
    void set_data (char d);
    char get_data () const;
    void set_random_data ();
    operator char () const;
    friend ostream& operator << (ostream& os, const Gene& g);
    boost::signals2::signal<void (Gene* g, char oldd, char newd)> on_data_changed;

  private:
    char data;
  };

}  // C3

#endif /* GENE_H */

