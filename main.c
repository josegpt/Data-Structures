#include <stdio.h>
#include "lib/utils/utils.h"
#include "lib/sorting/sorting.h"
#include "lib/heaps/max_heap.h"

int main(void)
{
  int arr[] = {5, 9, 2, 1, 3, 6, 0, 4, 7, 8};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  // bubble_sort(arr, arr_size);
  // selection_sort(arr, arr_size);
  // insertion_sort(arr, arr_size);

  // Heap* h = heap_create();
  // for (int i = 0; i < arr_size; ++i) {
  //   heap_insert(h, i);
  // }

  // int* a = heap_sort(h);

  // print_list(a, arr_size, ' ');

  return 0;
}