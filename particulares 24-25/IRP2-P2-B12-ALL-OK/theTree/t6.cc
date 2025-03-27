
/////////////////////
// search & parent //
/////////////////////

#include "tree.h"
#include <iostream>

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'f');
  treeInsert (t, 'b');
  treeInsert (t, 'h');

  TreeNodePtr n1 = treeSearch (t, 'b');
  TreeNodePtr n2 = treeParent (t, n1);
  auto r = treeNodeKey(n2) == 'e';
  
  treeDestroy (t);
  
  return r ? 0 : 1;
}
