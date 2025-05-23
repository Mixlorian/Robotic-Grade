#include "gene.h"
#include <cctype>

namespace C3{

Gene::Gene(char d){
	set_data(d);
}

Gene::Gene(const Gene &g){
	set_data(g.data);
}

void Gene::set_data(char d){
	char old_data;
	
	// numero o letra?
	if(isalnum(d) != 0){
		old_data = data;
		data = d;
		on_data_changed(this, old_data, data); 
	}
	else{
		set_random_data();
	}
}

void Gene::set_random_data(){
	string permitidos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int pos = rand() % permitidos.length();
	data = permitidos[pos];

}

Gene::operator char () const{
	return data;
}

char Gene::get_data() const{
	return data;
}

ostream &operator<<(ostream &os, const Gene &g){
	os << g.data;	
	return os;
}

}

