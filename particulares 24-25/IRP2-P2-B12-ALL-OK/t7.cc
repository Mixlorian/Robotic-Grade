
#include "stack.h"

// Creamos la pila

int main(int argc, char *argv[])
{
  StackPtr s = stackCreate();
  int result = s != nullptr ? 0 : 1;

  listMakeNull(&s->l);
  delete s;
  
  return result;
}
