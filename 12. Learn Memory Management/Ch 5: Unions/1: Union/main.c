#include <stdio.h>
#include "exercise.h"
#include "munit.h"  // Include necessary headers

/* Test case 1 */
static MunitResult test_formats_int1(const MunitParameter params[], void* data) {
    char buffer[100];
    snek_object_t i = new_integer(5);
    format_object(i, buffer);

    munit_assert_string_equal(buffer, "int:5");
    return MUNIT_OK;
}

/* Test case 2 */
static MunitResult test_formats_string1(const MunitParameter params[], void* data) {
    char buffer[100];
    snek_object_t s = new_string("Hello!");
    format_object(s, buffer);

    munit_assert_string_equal(buffer, "string:Hello!");
    return MUNIT_OK;
}

/* Test case 3 */
static MunitResult test_formats_int2(const MunitParameter params[], void* data) {
    char buffer[100];
    snek_object_t i = new_integer(2014);
    format_object(i, buffer);

    munit_assert_string_equal(buffer, "int:2014");
    return MUNIT_OK;
}

/* Test case 4 */
static MunitResult test_formats_string2(const MunitParameter params[], void* data) {
    char buffer[100];
    snek_object_t s = new_string("nvim btw");
    format_object(s, buffer);

    munit_assert_string_equal(buffer, "string:nvim btw");
    return MUNIT_OK;
}

/* Test cases */
static MunitTest tests[] = {
    { (char*) "/integer_nvim", test_formats_int1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/string_nvim", test_formats_string1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/integer", test_formats_int2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/string", test_formats_string2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* End of the test list */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* Test suite */
static const MunitSuite suite = {
    (char*) "/format",  /* Name of the suite */
    tests,             /* Array of test cases */
    NULL,              /* Sub-suites (none in this case) */
    1,                 /* Number of iterations */
    MUNIT_SUITE_OPTION_NONE  /* Options */
};

/* Main function */
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

