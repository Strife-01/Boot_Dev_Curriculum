#include <stdlib.h>

#include "snekobject.h"

snek_object_t *new_snek_integer(int value) {
  snek_object_t *ptr_i = (snek_object_t *)malloc(sizeof(snek_object_t));
  if (ptr_i == NULL) {
    return NULL;
  }

  ptr_i->kind = INTEGER;
  ptr_i->data.v_int = value;

  return ptr_i;
}

