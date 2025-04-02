
////////////////
// treeHeight //
////////////////

/*
		g
	       / \
              e   h
	     / \
	    b   f


*/
#include "tree.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  auto r1 = treeHeight (t) == 0;

  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'f');
  treeInsert (t, 'b');
  treeInsert (t, 'h');

  auto r2 = treeHeight (t) == 2;
	
	cout << treeHeight(t) << endl;

	cout << r2 << endl;

  treeDestroy (t);

  return r1 and r2 ? 0 : 1;
}
