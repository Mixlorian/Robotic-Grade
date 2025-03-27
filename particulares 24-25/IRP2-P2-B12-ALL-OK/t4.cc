
#include "list.h"
#include <iostream>

// Buscamos NodePtr's en lista vacia (p1) y en lista con elementos
// (p2)

int main(int argc, char *argv[])
{
  ListPtr l = listCreate();

  auto p1 = listRetrieve(l, 2);

  for (char c='a'; c < 'f'; c++)
    listInsert (l, c, 100);

  listInsert (l, 'z', 1);
  
  auto p2 = listRetrieve(l, 3);
  char c = 'M';  // valor erroneo
  if (p2 != nullptr)
	c = p2->key;

  listMakeNull(l);
  delete l;

  return (p1 == nullptr) and (c == 'b') ? 0 : 1;
}
