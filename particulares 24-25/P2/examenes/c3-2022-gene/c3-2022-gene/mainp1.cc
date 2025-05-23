
#include <cstdlib>
#include <iostream>
#include <string>

#include "chromosome.h"
#include "gene.h"
#include "mutablegene.h"

using namespace C3;

void check_data_changed(Gene* g, char oldd, char newd) {
  std::cout << "\nData changed from: " << oldd
            << " to: " << newd << '\n';
}

void chromosome_evolved(Chromosome* c) {
  std::cout << "\nEvolved Chromosome (" << c << ")\n";
}

int main(int argc, char *argv[])
{
  std::cout << "\n============= GENE ============\n\n";

  Gene g('h');

  cout << "g: " << g << '\n';
  cout << "g as char: " << static_cast<char>(g) << '\n';

  std::cout << "\n============= MUTABLE GENE ============\n\n";

  MutableGene mg('a');
  mg.on_data_changed.connect(check_data_changed);

  cout << "mg: " << mg << " now mutate 10 times with mr = 20%\n";
  for (int n = 0; n < 10; n++) {
    mg.mutate_data(0.2);
    cout << "mg : " << mg << '\n';
  }

  std::cout << "\n============= CHROMOSOME ============\n\n";

  Chromosome crm("hoyes9dejunio");

  crm.on_evolve.connect(chromosome_evolved);

  std::cout << "Crm target length: " << crm.target().length()
            << " Crm genes length: " << crm.size() << '\n'
            << "Crm target: [" << crm.target() << "]\n"
            << "Crm genes:  [" << crm.get_genes() << "]\n"
            << "Crm fitness: [" << crm.fitness() << "]\n";

  std::cout << "\nEvolve 10 times.\n\n";
  for (int n = 0; n < 10; n++) {
    crm.evolve(0.3);

    std::cout << "Crm genes:  [" << crm.get_genes() << "]\n"
              << "Crm fitness: [" << crm.fitness() << "]\n";
  }

  std::cout << "\nCrm show_genes: \n";
  crm.show_genes(std::cout);
  std::cout << '\n';

  return 0;
}
