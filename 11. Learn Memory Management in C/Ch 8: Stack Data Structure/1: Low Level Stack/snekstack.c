#include "snekstack.h"

snekstack_t *stack_new(size_t capacity) {
    snekstack_t *stack = (snekstack_t *)malloc(sizeof(snekstack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->data = (void **)malloc(capacity * sizeof(void *));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->count = 0;
    return stack;
}

