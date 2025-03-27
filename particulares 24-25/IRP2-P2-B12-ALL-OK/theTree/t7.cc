
////////////////////////
// pre-post-in orders //
////////////////////////

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
  treeInsert (t, 'h');

  auto pre = treePreOrder (t, sep);
  auto in  = treeInOrder (t, sep);
  auto post = treePostOrder (t, sep);

  // Quitamos separadadores y solo dejamos caracteres
  pre.erase(std::remove(pre.begin(), pre.end(), sep), pre.end());
  in.erase(std::remove(in.begin(), in.end(), sep), in.end());
  post.erase(std::remove(post.begin(), post.end(), sep), post.end());
  
  auto r1 = pre == "gebfh";
  auto r2 = in == "befgh";
  auto r3 = post == "bfehg";
  
  treeDestroy (t);

  // std::cout << "pre: " << pre << "\n";
  // std::cout << "in: " << in << "\n";
  // std::cout << "post: " << post << "\n";
  
  return r1 and r2 and r3 ? 0 : 1;
}
