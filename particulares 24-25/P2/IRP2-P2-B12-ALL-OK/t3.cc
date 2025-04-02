
#include "list.h"
#include <iostream>

// Buscamos en lista vacia (p1) y en lista con elementos (p2)

int main(int argc, char *argv[])
{
  ListPtr l = listCreate();

  auto p1 = listLocate(l, 'c');

  for (char c='a'; c < 'f'; c++)
    listInsert (l, c, 100);

  listInsert (l, 'z', 1);
  
  auto p2 = listLocate(l, 'c');

  listMakeNull(l);
  delete l;

  return (p1 == NOPOS) and (p2 == 4) ? 0 : 1;
}
