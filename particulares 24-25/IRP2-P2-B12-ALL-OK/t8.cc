
#include "stack.h"
#include "error.h"

// Creamos pila y pila vacia

int main(int argc, char *argv[])
{
  StackPtr s = stackCreate();

  auto empty = stackEmpty(s);   // true
  
  stackPop(s); // tiene que poner error a 1 porque no puede hacer Pop de una lista vacia.
  auto error = get_error() == 1;     // true

  auto result = empty and error;

  listMakeNull(&s->l);
  delete s;

  return result ? 0 : 1;
}
