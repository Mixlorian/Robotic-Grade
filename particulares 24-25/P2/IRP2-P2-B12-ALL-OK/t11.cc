
//#include <iostream>
#include "queue.h"

// Encolamos
int main(int argc, char *argv[])
{
  QueuePtr q = queueCreate();

  
  queueEnqueue (q, 'd');
  queueEnqueue (q, 'r');
  auto empty = queueEmpty(q);   // false
  auto t1 = queueDequeue(q) == 'd';
  auto t2 = queueDequeue(q) == 'r';

  //std::cout << t1 << " [" << t2 << "]";
  listMakeNull(&q->l);
  delete q;

  auto result = not empty and t1 and t2;

  return result ? 0 : 1;
}
