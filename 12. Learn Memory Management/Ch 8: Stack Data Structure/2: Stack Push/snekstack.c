#include "snekstack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(stacksnek_t *stack, void *obj) {
  if (stack->count == stack->capacity) {
    stack->capacity *= 2;
    // tmp pointer
    void **tmp = realloc(stack->data, stack->capacity * sizeof(void *));
    if (tmp == NULL) {
      free(stack->data);
      exit(1);
    }
    stack->data = tmp;
  }

  stack->data[stack->count] = obj;
  stack->count++;
  return;
}

// don't touch below this line

stacksnek_t *stack_new(size_t capacity) {
  stacksnek_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}

