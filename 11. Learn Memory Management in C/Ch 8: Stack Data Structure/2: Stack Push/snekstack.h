#include <stddef.h>

typedef struct Stack {
  size_t count;
  size_t capacity;
  void **data;
} stacksnek_t;

stacksnek_t *stack_new(size_t capacity);
void stack_push(stacksnek_t *stack, void *obj);

