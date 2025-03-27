
/////////////////////////
// treeInsert & remove //
/////////////////////////

#include "tree.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const char sep = ',';

/*
       g
      / \
     e   h
    / \
   b   f
RID: g e b f h

Eliminamos la e.
       g
      / \
     f   h
    / 
   b   
RID: g f b h

Eliminamos la g.
       h
      / 
     f   
    / 
   b   
RID: h f b

Eliminamos la h.
      f
     /
    b
RID: f b

*/

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  auto r1 = (t) and (treeEmpty (t));
  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'f');
  treeInsert (t, 'b');
  treeInsert (t, 'h');
	cout << "antes de borrar: " << treePreOrder(t, ',') << endl;

  treeRemove (t, 'e');          // 2 hijos
 
 auto pre2 =  treePreOrder (t, ',');
	cout << "despues de borrar la e: " << pre2 << endl;
  pre2.erase(std::remove(pre2.begin(), pre2.end(), sep), pre2.end());
  auto r2 = pre2 == "gfbh";

  treeRemove (t, 'g');          // Raiz
  auto pre3 = treePreOrder (t, ',');
	cout << "despues de borrar la g: " << pre3 << endl;
  pre3.erase(std::remove(pre3.begin(), pre3.end(), sep), pre3.end());
  auto r3 =  pre3 == "hfb";
  
  treeRemove (t, 'f');          // 1 hijo
  auto pre4 = treePreOrder (t, ',');
	cout << "despues de borrar la f: " << pre4 << endl;
  pre4.erase(std::remove(pre4.begin(), pre4.end(), sep), pre4.end());
  auto r4 = pre4 == "hb";
 
  treeDestroy (t);
 
	cout << r1 << r2 << r3 << r4 << endl; 
  return r1 and r2 and r3 and r4 ? 0 : 1;
}
