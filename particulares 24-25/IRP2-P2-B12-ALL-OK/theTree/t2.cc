
////////////////////////////////////////
// treeEmpty & treeSize && treeInsert //
////////////////////////////////////////

#include "tree.h"

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  auto r1 = (t) and (treeEmpty (t));
  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'b');
  treeInsert (t, 'h');
  auto r2 = treeSize (t) == 4;
  treeDestroy (t);
  
  return r1 /*and r2*/ ? 0 : 1;
}
