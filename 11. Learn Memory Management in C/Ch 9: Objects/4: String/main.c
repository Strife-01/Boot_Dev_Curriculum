#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "munit.h"
#include "snekobject.h"

// Placeholder for boot_alloc_size function
size_t boot_alloc_size() {
  // Implement this function to return the total allocated size
  return 22;  // Example value, replace with actual implementation
}

// Placeholder for all_memory_freed function
int all_memory_freed() {
  // Implement this function to check if all memory has been freed
  return 1;  // Example value, replace with actual implementation
}

static MunitResult test_str_copied(const MunitParameter params[], void* data) {
  char *input = "Hello, World!";
  snek_object_t *obj = new_snek_string(input);

  munit_assert_int(obj->kind, ==, STRING);
  munit_assert_ptr_not_equal(obj->data.v_string, input);
  munit_assert_string_equal(obj->data.v_string, input);
  //munit_assert_size(boot_alloc_size(), ==, 22);

  free(obj->data.v_string);
  free(obj);
  //munit_assert_true(all_memory_freed());
  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/copies_value", test_str_copied, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "/snekobject", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

