
///////////////////////////
// treeCreate & treeRoot //
///////////////////////////

#include "tree.h"

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  auto r = (t) and (treeRoot (t) == nullptr) ?
    0 :                         // ok
    1;                          // error

  treeDestroy (t);
  
  return r;
}
