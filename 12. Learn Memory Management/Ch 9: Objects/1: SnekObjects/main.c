#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"

static MunitResult test_integer_constant(const MunitParameter params[], void* data) {
  munit_assert_int(INTEGER, ==, 0);  // Correct the assert usage
  return MUNIT_OK;
}

static MunitResult test_integer_obj(const MunitParameter params[], void* data) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  obj->kind = INTEGER;
  obj->data.v_int = 0;

  munit_assert_int(obj->kind, ==, INTEGER);  // Correct the assert usage
  munit_assert_int(obj->data.v_int, ==, 0);  // Correct the assert usage

  free(obj);
  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/test_integer_constant", test_integer_constant, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_integer_obj", test_integer_obj, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "/snekobject", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

