
#include "queue.h"
#include "error.h"

// Crear cola y cola vacia
int main(int argc, char *argv[])
{
  QueuePtr q = queueCreate();

  auto empty = queueEmpty(q);   // true
  
  auto e = queueDequeue (q);
  auto error = get_error() == 1;     // true

  listMakeNull(&q->l);
  delete q;

  auto result = empty and error;

  return result ? 0 : 1;
}
