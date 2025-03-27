
#include "list.h"
#include <iostream>

// Vaciamos la lista. Probamos listSize

int main(int argc, char *argv[])
{
  ListPtr l = listCreate();

  listMakeNull(l);
  auto p1 = listSize (l) == 0;

  for (char c='a'; c < 'f'; c++)
    listInsert (l, c, 100);

  listMakeNull(l);
  auto p2 = listSize (l) == 0;

  listMakeNull(l);
  delete l;

  return (p1) and (p2) ? 0 : 1;
}
