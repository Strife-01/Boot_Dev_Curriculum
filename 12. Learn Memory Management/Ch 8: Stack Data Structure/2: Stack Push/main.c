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
static MunitResult create_stack(const MunitParameter *params, void *data) {
    snekstack_t *s = stack_new(10);
    munit_assert_int(s->capacity, ==, 10);
    munit_assert_int(s->count, ==, 0);
    munit_assert_ptr_not_null(s->data);

    track_free(s->data, s->capacity * sizeof(*s->data));
    track_free(s, sizeof(*s));

    munit_assert_true(all_memory_freed());

    return MUNIT_OK;
}

static MunitResult push_stack(const MunitParameter *params, void *data) {
    snekstack_t *s = stack_new(2);
    munit_assert_ptr_not_null(s);

    munit_assert_int(s->capacity, ==, 2);
    munit_assert_int(s->count, ==, 0);
    munit_assert_ptr_not_null(s->data);

    int a = 1;
    stack_push(s, &a);
    stack_push(s, &a);

    munit_assert_int(s->capacity, ==, 2);
    munit_assert_int(s->count, ==, 2);
    munit_assert_ptr_equal(s->data[0], &a);

    track_free(s->data, s->capacity * sizeof(*s->data));
    track_free(s, sizeof(*s));

    munit_assert_true(all_memory_freed());

    return MUNIT_OK;
}

static MunitResult push_double_capacity(const MunitParameter *params, void *data) {
    snekstack_t *s = stack_new(2);
    munit_assert_ptr_not_null(s);

    munit_assert_int(s->capacity, ==, 2);
    munit_assert_int(s->count, ==, 0);
    munit_assert_ptr_not_null(s->data);

    int a = 1;
    stack_push(s, &a);
    stack_push(s, &a);

    munit_assert_int(s->capacity, ==, 2);
    munit_assert_int(s->count, ==, 2);

    stack_push(s, &a);
    munit_assert_int(s->capacity, ==, 4);
    munit_assert_int(s->count, ==, 3);

    track_free(s->data, s->capacity * sizeof(*s->data));
    track_free(s, sizeof(*s));

    munit_assert_true(all_memory_freed());

    return MUNIT_OK;
}

// Define the main function
int main() {
    MunitTest tests[] = {
        {"/create_stack", create_stack, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {"/push_stack", push_stack, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {"/push_double_capacity", push_double_capacity, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},  // End of the test list
    };

    MunitSuite suite = {"/snekstack", tests, NULL, 1};

    return munit_suite_main(&suite, NULL, 0, NULL);
}

