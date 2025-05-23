
#include <iostream>

#include "list.tcc"

using namespace std;

void f(C3::NodePtr<char> n) {
  cout << n->get_key() << " ";
}

int main(int argc, char *argv[])
{
  C3::List<char> cl;


  for (auto c = 'a'; c < 'z'; c++) {
    cl.insert_back(c);
  }

  cl.insert_at(1, '[');
  cl.insert_at(12, '*');
  cl.insert_at(cl.length()+1, ']');

  cout << "Forward:\n";
  cl.for_each(f);
  cout << "\nBackward:\n";
  cl.for_each_reverse(f);
  
  cout << endl;
  cout << cl << endl;

  return 0;
}
