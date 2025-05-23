#include "chromosome.h"
#include "mutablegene.h"

namespace C3{

void Chromosome::create_genes (){
	MutableGene *mg;
	for(int i = 1; i <= ts.length(); i++){
		mg = new MutableGene('a'); // mg = new MutableGena(' ');
		mg->mutate_data(1);
		gl.push_back(mg);
	}
}

void Chromosome::free_gene_list (vector<MutableGene*>& l){
	for(int i = 0; i < l.size(); i++){
		delete l[i];
		// l[i] = nullptr;
	}
	l.clear();
}

Chromosome::Chromosome (string &tstr){
	ts = tstr;
	create_genes();
}

Chromosome::Chromosome (const char* tstr){
	ts = tstr; // string <= char []
	create_genes();
}

Chromosome::~Chromosome (){
	free_gene_list(gl);
}

string Chromosome::target () const{
	return ts;
}


// - Recorrer de forma paralela y contar la cantidad de caracteres
// que son distintos!! :) ^^
// string ts;
// vector<MutableGene*> gl;
uint32_t Chromosome::fitness () const{
	uint32_t distintos = 0;
	
	for(int i = 0; i < ts.length(); i++){
		if(ts[i] != gl[i]->get_data()){
			distintos++;
		}
	}
	return distintos;
}


// Chromosome puti("cositas");
// puti.show_genes(cout);

void Chromosome::show_genes (ostream& os) const{
	for(int i = 0; i < gl.size(); i++){
		os << *gl[i]; // si NO pones el * te muestra la direccion de
		// memoria => os << Gene
	}
}

string Chromosome::get_genes () const{
	string the_genes = "";
	
	for(int i = 0; i < gl.size();i++){
		the_genes += gl[i]->get_data();
	}
	return the_genes;	
}

uint32_t Chromosome::size(){
	return gl.size();
}

void Chromosome::evolve (float mr){
	for(int i = 0; i < gl.size(); i++){
		gl[i]->mutate_data(mr);
	}
	on_evolve(this);		
}

}



