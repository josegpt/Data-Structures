#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "../heaps/max_heap.h"

int pqueue_peek(Heap* h);
int pqueue_dequeue(Heap* h);
void pqueue_enqueue(Heap* h, int val);

#endif // PRIORITY_QUEUE_H
