
////////////////////////////////////////
// treeEmpty & treeSize && treeInsert //
////////////////////////////////////////

#include "tree.h"

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  auto r1 = (t) and (treeEmpty (t));
  
  treeInsert (t, 'g');
  treeRemove (t, 'g');
  
  treeInsert (t, 'e');
  treeRemove (t, 's');
  
  treeInsert (t, 'b');
  treeInsert (t, 'h');
  treeRemove (t, 's');
  
  auto r2 = treeSize (t) == 3;
  
  treeDestroy (t);
  
  return r1 and r2 ? 0 : 1;
}
