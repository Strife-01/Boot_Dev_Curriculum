#include "munit.h"
#include "exercise.h"
#include <stdlib.h>

// Test function for allocate_scalar_list with valid size and multiplier
static MunitResult test_allocate_scalar_list_size(const MunitParameter params[], void *user_data) {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  munit_assert_not_null(result);
  free(result);
  return MUNIT_OK;
}

// Test function for allocate_scalar_list with correct values
static MunitResult test_allocate_scalar_list_values(const MunitParameter params[], void *user_data) {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  int expected[5] = {0, 2, 4, 6, 8};
  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, expected[i]);
  }
  free(result);
  return MUNIT_OK;
}

// Test function for allocate_scalar_list with zero multiplier
static MunitResult test_allocate_scalar_list_zero_multiplier(const MunitParameter params[], void *user_data) {
  int size = 3;
  int multiplier = 0;
  int *result = allocate_scalar_list(size, multiplier);
  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, 0);
  }
  free(result);
  return MUNIT_OK;
}

// Test function for allocate_scalar_list with large allocation
static MunitResult test_allocate_too_much(const MunitParameter params[], void *user_data) {
  int size = 1024 * 1024 * 100;
  int multiplier = 1;
  int *result = allocate_scalar_list(size, multiplier);
  munit_assert_null(result);
  return MUNIT_OK;
}

int main(int argc, char *argv[]) {
  MunitTest tests[] = {
    {
      "/test_allocate_scalar_list_size",    // name
      test_allocate_scalar_list_size,       // test function
      NULL,                                 // setup function
      NULL,                                 // tear down function
      MUNIT_TEST_OPTION_NONE,               // options
      NULL                                  // parameters
    },
    {
      "/test_allocate_scalar_list_values",  // name
      test_allocate_scalar_list_values,     // test function
      NULL,                                 // setup function
      NULL,                                 // tear down function
      MUNIT_TEST_OPTION_NONE,               // options
      NULL                                  // parameters
    },
    {
      "/test_allocate_scalar_list_zero_multiplier", // name
      test_allocate_scalar_list_zero_multiplier,    // test function
      NULL,                                         // setup function
      NULL,                                         // tear down function
      MUNIT_TEST_OPTION_NONE,                       // options
      NULL                                          // parameters
    },
    {
      "/test_allocate_too_much",            // name
      test_allocate_too_much,               // test function
      NULL,                                 // setup function
      NULL,                                 // tear down function
      MUNIT_TEST_OPTION_NONE,               // options
      NULL                                  // parameters
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
  };

  MunitSuite suite = {
    "/allocate_scalar_list",                // name
    tests,                                  // tests
    NULL,                                   // suites
    1,                                      // iterations
    MUNIT_SUITE_OPTION_NONE                 // options
  };

  return munit_suite_main(&suite, NULL, argc, argv);
}

