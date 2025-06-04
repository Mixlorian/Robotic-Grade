#ifndef _B_H_
#define _B_H_
#include <iostream>
using namespace std;

class B{
	friend ostream &operator<<(ostream &os, const B &b);
	private:
		int x;
		int y;
	public:
		B(int x, int y);
		int getX() const;
		int getY() const;
		void setX(int x);
		void setY(int y);
};

#endif

