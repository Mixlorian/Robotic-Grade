#include "TyreType.h"
#include <stdexcept>

namespace C3{

TyreType::TyreType(string d, double minp, double maxp){
	if(minp < 0 || maxp < minp || d == ""){
		throw invalid_argument("Wrong arguments");
	}
	min_pressure = minp;
	max_pressure = maxp;
	description = d;
}

TyreType::TyreType(const TyreType &tt){
	min_pressure = tt.min_pressure;
	max_pressure = tt.max_pressure;
	description = tt.description;
}

double TyreType::getMinPressure() const{
	return min_pressure;
}

double TyreType::getMaxPressure() const{
	return max_pressure;
}

string TyreType::toString() const{
	return "TyreType " + description + " ["
	+ to_string(min_pressure) + ","
	+ to_string(max_pressure) + "]";
}

bool TyreType::operator==(const TyreType &tt) const{
	return description == tt.description
	&& min_pressure == tt.min_pressure
	&& max_pressure == tt.max_pressure;
}

}



