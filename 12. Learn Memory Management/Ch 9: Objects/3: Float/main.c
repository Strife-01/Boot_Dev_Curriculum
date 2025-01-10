#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"


static MunitResult test_positive(const MunitParameter params[], void* data) {
  snek_object_t *obj = new_snek_float(42.0);
  munit_assert_double(obj->data.v_float, ==, 42.0);  // Correct the assert usage
  free(obj);
  //munit_assert_true(all_memory_freed());  // Assuming all_memory_freed is defined
  return MUNIT_OK;
}

static MunitResult test_zero(const MunitParameter params[], void* data) {
  snek_object_t *obj = new_snek_float(0.0);
  munit_assert_int(obj->kind, ==, FLOAT);  // Correct the assert usage
  munit_assert_double(obj->data.v_float, ==, 0.0);  // Correct the assert usage
  free(obj);
  //munit_assert_true(all_memory_freed());  // Assuming all_memory_freed is defined
  return MUNIT_OK;
}

static MunitResult test_negative(const MunitParameter params[], void* data) {
  snek_object_t *obj = new_snek_float(-5.0);
  munit_assert_int(obj->kind, ==, FLOAT);  // Correct the assert usage
  munit_assert_double(obj->data.v_float, ==, -5.0);  // Correct the assert usage
  free(obj);
  //munit_assert_true(all_memory_freed());  // Assuming all_memory_freed is defined
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

