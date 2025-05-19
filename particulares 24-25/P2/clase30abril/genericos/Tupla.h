#ifndef _TUPLA_H_
#define _TUPLA_H_
#include <iostream>
using namespace std;

class Tupla{
	private:
		int first, second;
	public:
		Tupla();
		Tupla(int f, int s);
		int getFirst() const;
		int getSecond() const;
		bool operator==(const Tupla &de) const;
		bool operator!=(const Tupla &de) const;
};

#endif
