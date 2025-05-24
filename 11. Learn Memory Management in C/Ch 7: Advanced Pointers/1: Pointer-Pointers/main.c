#include <stdlib.h>
#include "exercise.h"
#include "munit.h"

// Test function for allocating memory for an int and assigning a value
static MunitResult test_allocate(const MunitParameter params[], void *user_data) {
  int *pointer = NULL;
  allocate_int(&pointer, 10);

  munit_assert_ptr_not_null(pointer);
  munit_assert_int(*pointer, ==, 10);

  free(pointer);
  return MUNIT_OK;
}

// Test function for ensuring that allocate_int doesn't overwrite existing values
static MunitResult test_does_not_overwrite(const MunitParameter params[], void *user_data) {
  int value = 5;
  int *pointer = &value;

  allocate_int(&pointer, 20);

  munit_assert_int(value, ==, 5);
  munit_assert_ptr_not_null(pointer);
  munit_assert_int(*pointer, ==, 20);

  free(pointer);
  return MUNIT_OK;
}

int main(int argc, char *argv[]) {
  MunitTest tests[] = {
    {
      "/create",       // test name
      test_allocate,   // test function
      NULL,            // setup function (optional)
      NULL,            // tear down function (optional)
      MUNIT_TEST_OPTION_NONE,  // test options (none)
      NULL             // test parameters (optional)
    },
    {
      "/overwrite",    // test name
      test_does_not_overwrite, // test function
      NULL,            // setup function (optional)
      NULL,            // tear down function (optional)
      MUNIT_TEST_OPTION_NONE,  // test options (none)
      NULL             // test parameters (optional)
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
  };

  MunitSuite suite = {
    "/allocate_list",    // suite name
    tests,               // tests
    NULL,                // sub-suites (none)
    1,                   // iterations (1)
    MUNIT_SUITE_OPTION_NONE // options (none)
  };

  return munit_suite_main(&suite, NULL, argc, argv);
}

