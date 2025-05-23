
#include <iostream>

#include "p1.h"

using namespace std;

int main(int argc, char *argv[])
{
  for (auto np = 0; np < 10; np++) {
    auto nc = C3::ncuts(np);
    cout << "For " << np << " people you need " << nc << " cuts!\n";
  }

  return 0;
}
