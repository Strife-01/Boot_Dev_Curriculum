#ifndef SNEKSTACK_H
#define SNEKSTACK_H

#include <stdlib.h>

typedef struct Stack {
    size_t capacity;
    size_t count;
    void **data;
} snekstack_t;

snekstack_t *stack_new(size_t capacity);

#endif // SNEKSTACK_H

