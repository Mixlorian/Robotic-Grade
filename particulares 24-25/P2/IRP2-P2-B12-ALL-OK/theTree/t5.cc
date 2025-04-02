
/////////////////////////
// leafNodes & maximum //
/////////////////////////

#include "tree.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'f');
  treeInsert (t, 'b');
  treeInsert (t, 'h');

  auto r1 = treeLeafTreeNodes (t) == 3;
  auto r2 = treeNodeKey(treeMaximum (t)) == 'h';
  
	cout << treeLeafTreeNodes(t) << endl;

	cout << treeNodeKey(treeMaximum(t)) << endl;

  treeDestroy (t);
  
	cout << r1 << r2 << endl;
  return r1 and r2 ? 0 : 1;
}
