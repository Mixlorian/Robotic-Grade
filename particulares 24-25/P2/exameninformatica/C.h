#ifndef _C_H_
#define _C_H_
#include <iostream>
using namespace std;

namespace C3{

class C;
using CPtr = C *;

class C{
	private:
		int id;
		static int nextId;
		static int getNextId();
	public:
		C();
		int getId() const;
};

}


#endif
