#include "gene.h"
#include "mutablegene.h"
#include <iostream>
using namespace std;
using namespace C3;
int main(){
	Gene gene('a');
	char caracter = (char) gene;
	cout << caracter << endl;
	
	
	MutableGene mg('r');
	
	
	cout << (Gene) mg << endl;
		
	mg.mutate_data(1);
	
	cout << (Gene) mg << endl;
	
	mg.mutate_data(.2);
	
	cout << (Gene) mg << endl;
	
	
	return 0;
}
