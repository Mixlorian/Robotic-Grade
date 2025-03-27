
//////////////
// byLevels //
//////////////

#include "tree.h"
#include <iostream>
#include <algorithm>
#include <string>

const char sep = ' ';

int main(int argc, char *argv[])
{
  TreePtr t = treeCreate ();

  treeInsert (t, 'g');
  treeInsert (t, 'e');
  treeInsert (t, 'f');
  treeInsert (t, 'b');
  treeInsert (t, 's');
  treeInsert (t, 's');
  treeInsert (t, 'i');
  treeInsert (t, 't');
  treeInsert (t, 'm');

  auto bl = treeByLevels (t, sep);

  // Quitamos separadadores y solo dejamos caracteres
  bl.erase(std::remove(bl.begin(), bl.end(), sep), bl.end());
  
  auto r1 = bl == "gesbfitm";
  
  treeDestroy (t);

  //std::cout << "bl: " << bl << "\n";
  
  return r1 ? 0 : 1;
}
