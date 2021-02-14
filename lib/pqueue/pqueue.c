#include "pqueue.h"

int pqueue_peek(Heap* h)
{
  return heap_getMax(h);
}

int pqueue_dequeue(Heap* h)
{
  return heap_extractMax(h);
}

void pqueue_enqueue(Heap* h, int val)
{
  heap_insert(h, val);
}
