#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"
#include "snekstack.h"

// Custom memory tracking functions
static size_t allocated_memory = 0;

void* track_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr) {
        allocated_memory += size;
    }
    return ptr;
}

void track_free(void* ptr, size_t size) {
    if (ptr) {
        free(ptr);
        allocated_memory -= size;
    }
}

int all_memory_freed() {
    return allocated_memory == 0;
}

// Rename stack_t to avoid conflict with system typedef
typedef struct Stack snekstack_t;

// Define test cases
static MunitResult create_stack_small(const MunitParameter *params, void *data) {
    snekstack_t *s = stack_new(3);
    munit_assert_int(s->capacity, ==, 3);  // Using munit's assertion macros
    munit_assert_int(s->count, ==, 0);
    munit_assert_ptr_not_null(s->data);

    free(s->data);
    free(s);

    munit_assert_true(all_memory_freed());

    return MUNIT_OK;
}

static MunitResult create_stack_large(const MunitParameter *params, void *data) {
    snekstack_t *s = stack_new(100);
    munit_assert_int(s->capacity, ==, 100);
    munit_assert_int(s->count, ==, 0);
    munit_assert_ptr_not_null(s->data);

    free(s->data);
    free(s);

    munit_assert_true(all_memory_freed());

    return MUNIT_OK;
}

// Define the main function
int main() {
    MunitTest tests[] = {
        {"/create_stack_small", create_stack_small, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {"/create_stack_large", create_stack_large, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},  // End of the test list
    };

    MunitSuite suite = {"/snekstack", tests, NULL, 1};

    return munit_suite_main(&suite, NULL, 0, NULL);
}

