#ifndef _TYRETYPE_H_
#define _TYRETYPE_H_
#include <iostream>
using namespace std;

namespace C3{


class TyreType{
	// friend bool operator==(const TyreType &izq, const TyreType &der);
	friend ostream &operator<<(ostream &os, const TyreType &tt);
	private:
		string description;
		double min_pressure;
		double max_pressure;
	public:
		TyreType(string d, double minp, double maxp);
		TyreType(const TyreType &tt);
		double getMinPressure() const;
		double getMaxPressure() const;
		string toString() const;
		bool operator==(const TyreType &tt) const;
};


}

#endif
