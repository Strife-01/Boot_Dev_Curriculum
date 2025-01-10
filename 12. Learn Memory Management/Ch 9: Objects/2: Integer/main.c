#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"

static MunitResult test_positive(const MunitParameter params[], void* data) {
  snek_object_t *int_object = new_snek_integer(42);
  munit_assert_int(int_object->data.v_int, ==, 42);  // Correct the assert usage
  free(int_object);
  return MUNIT_OK;
}

static MunitResult test_zero(const MunitParameter params[], void* data) {
  snek_object_t *int_object = new_snek_integer(0);
  munit_assert_int(int_object->kind, ==, INTEGER);  // Correct the assert usage
  munit_assert_int(int_object->data.v_int, ==, 0);  // Correct the assert usage
  free(int_object);
  return MUNIT_OK;
}

static MunitResult test_negative(const MunitParameter params[], void* data) {
  snek_object_t *int_object = new_snek_integer(-5);
  munit_assert_int(int_object->kind, ==, INTEGER);  // Correct the assert usage
  munit_assert_int(int_object->data.v_int, ==, -5);  // Correct the assert usage
  free(int_object);
  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/test_positive", test_positive, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_zero", test_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_negative", test_negative, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "/snekobject", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

