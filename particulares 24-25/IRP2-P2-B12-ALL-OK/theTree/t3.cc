
//////////////////
// treeInsert 2 //
//////////////////

#include "tree.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const char sep = ',';

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  auto r1 = (t) and (treeEmpty (t));
  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'b');
  treeInsert (t, 'h');

	cout << r1 << endl;
  auto pre = treePreOrder (t, ',');
	cout << pre << endl;
  // Quitamos separadadores y solo dejamos caracteres
  pre.erase(std::remove(pre.begin(), pre.end(), sep), pre.end());

  auto r2 = pre == "gebh";
  
	cout << r2 << endl;
  treeDestroy (t);
 
	cout << r1  << r2 << endl; 
  return r1 and r2 ? 0 : 1;
}
