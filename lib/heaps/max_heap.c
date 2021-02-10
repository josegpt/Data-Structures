#include <stdlib.h>
#include "max_heap.h"
#include  "../utils/utils.h"

#define HEAP_SIZE 256

struct Heap {
  int data[HEAP_SIZE];
  int size;
};

int in_boundary(Heap* h, int index)
{
  return index < h->size - 1;
}

int parent(Heap* h, int index)
{
  int p = (index - 1) / 2;
  return in_boundary(h, p) ? p : -1;
}

int left_child(Heap* h, int index)
{
  int left = 2 * index + 1;
  return in_boundary(h, left) ? left : -1;
}

int right_child(Heap* h, int index)
{
  int right = 2 * index + 2;
  return in_boundary(h, right) ? right : -1;
}

void heapify_up(Heap* h, int index)
{
  if (index > 0 && h->data[index] > h->data[parent(h, index)]) {
    swap(&h->data[index], &h->data[parent(h, index)]);
    heapify_up(h, parent(h, index));
  }
}

void heapify_down(Heap* h, int index)
{
  int largest = index;

  if ((left_child(h, index) > 0) && h->data[left_child(h, index)] > h->data[largest]) {
    largest = left_child(h, index);
  }

  if ((right_child(h, index) > 0) && h->data[right_child(h, index)] > h->data[largest]) {
    largest = right_child(h, index);
  }

  if (largest != index) {
    swap(&h->data[index], &h->data[largest]);
    heapify_down(h, largest);
  }
}

Heap* heap_create(void)
{
  Heap* h = malloc(sizeof(Heap));
  h->size = 0;

  return h;
}

void heap_insert(Heap* h, int val)
{
  if (h->size < HEAP_SIZE) {
    h->data[h->size++] = val;
    heapify_up(h, h->size - 1);
  }
}

void heap_remove(Heap* h, int index)
{
  if (h->size > 0 && index <= h->size - 1) {
    swap(&h->data[--h->size], &h->data[index]);
    heapify_down(h, index);
  }
}

int heap_extractMax(Heap* h)
{
  int value = h->data[0];
  heap_remove(h, 0);

  return value;
}

int heap_getMax(Heap* h)
{
  return h->data[0];
}

void heap_print(Heap* h)
{
  print_list(h->data, h->size, '-');
}

int* heap_sort(Heap* h)
{
  int* arr = malloc(h->size * sizeof(int));
  if (arr == NULL) return NULL;

  for (int i = h->size - 1; i >= 0; --i) {
    arr[i] = heap_extractMax(h);
  }

  return arr;
}
