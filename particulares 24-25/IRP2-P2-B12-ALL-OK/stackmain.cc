
#include "stack.h"
#include <iostream>
#include "lib/error.h"
// Apilamos y desapilamos

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  StackPtr s = stackCreate();

	stackTop(s);
	auto e =  get_error();  // 1
	set_error(0);
  std::cout << "Error al top: " << (int) e << std::endl;


  auto empty = stackEmpty(s);   // true


  for (int p = 0; p < 10; p++) {
    stackPush(s, 'a');
    stackPush(s, 'b');
    stackPush(s, 'c');
  }
  std::cout << stackToString(s, '-') << std::endl;


  auto count = listSize(&s->l) == 30;

  std::cout << "Longitud: " << count << std::endl;

  for (int p = 0; p < 9; p++) {
    [[maybe_unused]] auto t = stackPop(s);
    t = stackPop(s);
    t = stackPop(s);
    std::cout << "popeado: " << t << std::endl;
    std::cout << stackToString(s, '-') << std::endl;
  }

  [[maybe_unused]] auto t = stackPop(s);
  auto top = stackTop(s) == 'b';

  auto result = empty and count and top;

  listMakeNull(&s->l);
  delete s;

  return result ? 0 : 1;
}
