#include "exercise.h"

void snek_zero_out(void *ptr, snek_object_kind_t kind){
  switch (kind) {
    case INTEGER:
      //ptr = (snek_int_t *)malloc(sizeof(snek_int_t));
      ((snek_int_t *)ptr)->value = 0;
      break;
    case FLOAT:
      //ptr = (snek_float_t *)malloc(sizeof(snek_float_t));
      ((snek_float_t *)ptr)->value = 0.0;
      break;
    case BOOL:
      //ptr = (snek_bool_t *)malloc(sizeof(snek_bool_t));
      ((snek_bool_t *)ptr)->value = 0;
      break;
  }
}

