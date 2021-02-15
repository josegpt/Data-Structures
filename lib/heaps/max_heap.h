#ifndef HEAP_SORT_H
#define HEAP_SORT_H

typedef struct Heap Heap;

Heap* heap_create(void);
void heap_insert(Heap* h, int val);
void heap_remove(Heap* h, int index);
int heap_extractMax(Heap* h);
int heap_getMax(Heap* h);
void heap_print(Heap* h);
int* heap_sort(Heap* h);
#endif // HEAP_SORT_H
