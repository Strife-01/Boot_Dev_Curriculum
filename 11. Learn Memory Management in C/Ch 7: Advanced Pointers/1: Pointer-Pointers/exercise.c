#include "stdlib.h"

#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
  int *ptr = (int *)malloc(sizeof(int));
  if (ptr == NULL) {
    pointer_pointer = NULL;
    return;
  }
  //ptr = &value; - never do this as after we romove the stack frame we deallocate the value
  *pointer_pointer = ptr;
  **pointer_pointer = value;
}

