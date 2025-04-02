#include "queue.h"
#include "lib/error.h"
#include <iostream>

// Crear cola y cola vacia
int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  QueuePtr q = queueCreate();

  auto empty = queueEmpty(q);   // true
  std::cout << empty << std::endl;

  [[maybe_unused]] auto e = queueDequeue (q);
  auto error = get_error() == 1;     // true

  for (int n = 0; n < 1000; n++)
    queueEnqueue(q, 'a');

  std::cout << listToString(&q->l, ',') << std::endl;
  
  auto count = listSize(&q->l) == 1000;
 
  std::cout << listSize(&q->l) << std::endl;

  listMakeNull(&q->l);
  delete q;

  auto result = empty and error and count;

  return result ? 0 : 1;
}
