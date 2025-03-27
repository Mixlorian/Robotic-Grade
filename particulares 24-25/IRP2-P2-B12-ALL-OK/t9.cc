
#include "stack.h"

// Apilamos y desapilamos

int main(int argc, char *argv[])
{
  StackPtr s = stackCreate();

  
  stackPush (s, 'd');
  stackPush (s, 'r');
  auto empty = stackEmpty(s);   // false
  auto t1 = stackPop(s) == 'r';
  auto t2 = stackPop(s) == 'd';

  auto result = not empty and t1 and t2;

  listMakeNull(&s->l);
  delete s;

  return result ? 0 : 1;
}
