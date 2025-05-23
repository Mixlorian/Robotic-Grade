#include "hangar.h"

namespace P4{

std::ostream &operator<<(std::ostream &os, const Hangar &h){
	if(h.cname == "" && h.items.size() == 0){
		os << "Hangar vacio" << endl;
	}
	else{
		if(h.cname != ""){
			os << h.cname << endl;
		}
		for(ShipPtr sp : h.items){
			os << *sp;
		}
	}
	return os;
}

Hangar::Hangar(const std::string& name):Container(name){
		
}

void Hangar::remove(size_t index){
	if(index >= 0 && index < items.size()){
		items.erase(items.begin() + index);
	}
}

}
