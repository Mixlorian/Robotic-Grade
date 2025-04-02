
#include "list.h"
#include <iostream>

// Borramos nodos

int main(int argc, char *argv[])
{
  ListPtr l = listCreate();

  auto p1 = listRemove(l, 2);   // false

  for (char c='a'; c < 'f'; c++)
    listInsert (l, c, 100);

  auto p2 = listRemove (l, 1);            // true
  auto p3 = listRemove (l, 100);          // false

  listMakeNull(l);
  delete l;

  return (!p1) and (p2) and (!p3) ? 0 : 1;
}
