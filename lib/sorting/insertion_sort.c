#include "../utils/utils.h"

void insertion_sort(int* arr, int arr_size)
{
  for (int i = 1; i < arr_size; ++i) {
    int key = arr[i];

    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      swap(&arr[j], &arr[j + 1]);
      j--;
    }
    swap(&key, &arr[j + 1]);
  }
}