#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"

int *allocate_scalar_list(int size, int multiplier) {
  if (size > 10240) {
    return NULL;
  }
  int *arr = (int *)malloc(sizeof(int) * size);
  if (arr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    *(arr + i) = i * multiplier;
  }
  return arr;
}

