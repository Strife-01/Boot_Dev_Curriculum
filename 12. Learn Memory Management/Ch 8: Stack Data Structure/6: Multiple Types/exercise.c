#include "snekstack.h"
#include "stdlib.h"
#include <string.h>

void stack_push_multiple_types(stack_t *s) {
  float *ptr_f = (float *)malloc(sizeof(float));
  if (ptr_f == NULL) {
    return;
  }

  *ptr_f = 3.14;

  stack_push(s, (void *) ptr_f);

  char *ptr_c = (char *)malloc(strlen("Sneklang is blazingly slow!") + 1);
  if (ptr_c == NULL) {
    free(ptr_f);
    return;
  }

  strcpy(ptr_c, "Sneklang is blazingly slow!");

  stack_push(s, (void *) ptr_c);
}

