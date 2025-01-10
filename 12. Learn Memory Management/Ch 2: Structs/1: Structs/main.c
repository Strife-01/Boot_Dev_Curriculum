#include "munit.h"
#include "coord.h"

// Define the test case functions

MunitResult test_new_coordinate1(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 1;
  c.y = 2;
  c.z = 3;

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
}

MunitResult test_new_coordinate2(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 4;
  c.y = 2;
  c.z = 0;

  munit_assert_int(c.x, ==, 4);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 0);

  return MUNIT_OK;
}

MunitResult test_new_coordinate3(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 10;
  c.y = 20;
  c.z = 30;

  munit_assert_int(c.x, ==, 10);
  munit_assert_int(c.y, ==, 20);
  munit_assert_int(c.z, ==, 30);

  return MUNIT_OK;
}

MunitResult test_new_coordinate4(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 0;
  c.y = 6;
  c.z = 9;

  munit_assert_int(c.x, ==, 0);
  munit_assert_int(c.y, ==, 6);
  munit_assert_int(c.z, ==, 9);

  return MUNIT_OK;
}

// Main test runner
int main() {
  MunitTest tests[] = {
    {"/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/create_coordinate3", test_new_coordinate3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/create_coordinate4", test_new_coordinate4, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL} // Terminator
  };

  MunitSuite suite = {
    "/coordinates",    // Name of the test suite
    tests,             // Array of test cases
    NULL,              // No setup function
    NULL,              // No tear-down function
    MUNIT_SUITE_OPTION_NONE
  };

  // Run the test suite and check the result
  int result = munit_suite_main(&suite, NULL, 0, NULL);
  if (result != MUNIT_OK) {
      fprintf(stderr, "Tests failed with code: %d\n", result);
  }

  return result;
}
#include <stdio.h>   // Added to fix `fprintf` and `stderr`
#include "munit.h"
#include "coord.h"

// Define the test case functions

MunitResult test_new_coordinate1(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 1;
  c.y = 2;
  c.z = 3;

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
}

MunitResult test_new_coordinate2(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 4;
  c.y = 2;
  c.z = 0;

  munit_assert_int(c.x, ==, 4);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 0);

  return MUNIT_OK;
}

MunitResult test_new_coordinate3(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 10;
  c.y = 20;
  c.z = 30;

  munit_assert_int(c.x, ==, 10);
  munit_assert_int(c.y, ==, 20);
  munit_assert_int(c.z, ==, 30);

  return MUNIT_OK;
}

MunitResult test_new_coordinate4(const MunitParameter params[], void* user_data) {
  struct Coordinate c;
  c.x = 0;
  c.y = 6;
  c.z = 9;

  munit_assert_int(c.x, ==, 0);
  munit_assert_int(c.y, ==, 6);
  munit_assert_int(c.z, ==, 9);

  return MUNIT_OK;
}

// Main test runner
int main() {
  MunitTest tests[] = {
    {"/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/create_coordinate3", test_new_coordinate3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/create_coordinate4", test_new_coordinate4, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL} // Terminator
  };

  MunitSuite suite = {
    "/coordinates",    // Name of the test suite
    tests,             // Array of test cases
    NULL,              // No setup function
    NULL,              // No tear-down function
    MUNIT_SUITE_OPTION_NONE
  };

  // Run the test suite and check the result
  int result = munit_suite_main(&suite, NULL, 0, NULL);
  if (result != MUNIT_OK) {
      fprintf(stderr, "Tests failed with code: %d\n", result);  // Now that <stdio.h> is included
  }

  return result;
}

