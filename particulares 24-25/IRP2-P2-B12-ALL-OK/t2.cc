
#include "list.h"
#include <iostream>

// Insertamos en lista

int main(int argc, char *argv[]){
	ListPtr l = listCreate();

	for (char c = 'a'; c < 'f'; c++)
		listInsert (l, c, 100);


	listInsert (l, 'z', 1);

	auto s = listToString (l,':');
	std::cout << s << std::endl;


	listMakeNull(l);
	delete l;
	//std::cout << s;

	return  s == ":z:a:b:c:d:e" ? 0 : 1;
}
