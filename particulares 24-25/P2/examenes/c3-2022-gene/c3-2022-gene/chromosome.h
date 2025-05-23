// -*- mode: c++ -*-
/*
 * Copyright (C) 2017  Antonio-M. Corbi Bellot
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


#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <cstdint>
#include <string>
#include <vector>
#include <boost/signals2.hpp>

using namespace std;

namespace C3 {

  class MutableGene;

  class Chromosome
  {
  public:
    Chromosome (string& tstr);
    Chromosome (const char* tstr);
    ~Chromosome ();

    string target () const;
    uint32_t fitness () const;
    void show_genes (ostream& os) const;
    string get_genes () const;
    uint32_t size();
    void evolve (float mr);

    boost::signals2::signal<void (Chromosome* c)> on_evolve;

  protected:
    void create_genes ();
    void free_gene_list (vector<MutableGene*>& l);
    vector<MutableGene*> gl;

  private:
    string ts;
  };

}  // C3

#endif /* CHROMOSOME_H */
