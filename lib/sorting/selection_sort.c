#include "../utils/utils.h"

void selection_sort(int* arr, int arr_size)
{
  for (int i = 0; i < arr_size - 1; ++i) {
    int min_index = i;

    for (int j = i + 1; j < arr_size; ++j) {
      if (arr[min_index] > arr[j]) {
        min_index = j;
      }
    }
    swap(&arr[min_index], &arr[i]);
  }
}