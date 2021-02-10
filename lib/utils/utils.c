#include <stdio.h>

void print_list(int* arr, int arr_size, char sep)
{
  for (int i = 0; i < arr_size; ++i) {
    printf("%d%c", arr[i], sep);
  }
  printf("\n");
}

void swap(int* num1, int* num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}