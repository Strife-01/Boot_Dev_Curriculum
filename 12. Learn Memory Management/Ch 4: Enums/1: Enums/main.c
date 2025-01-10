#include "munit.h"
#include "color.h"  // Include color.h where the enum Color is defined

/* Test case 1 */
static MunitResult test_color_enum1(const MunitParameter params[], void* data) {
    /* Munit assertion macros */
    munit_assert_int(RED, ==, 0);      // Assert RED is 0
    munit_assert_int(GREEN, ==, 1);    // Assert GREEN is 1
    munit_assert_int(BLUE, ==, 2);     // Assert BLUE is 2
    return MUNIT_OK;
}

/* Test case 2 */
static MunitResult test_color_enum2(const MunitParameter params[], void* data) {
    /* Munit assertion macros */
    munit_assert_int(RED, !=, 4);      // Assert RED is not 4
    munit_assert_int(GREEN, !=, 2);    // Assert GREEN is not 2
    munit_assert_int(BLUE, !=, 0);     // Assert BLUE is not 0
    return MUNIT_OK;
}

/* Test cases */
static MunitTest tests[] = {
    { (char*) "/are_defined", test_color_enum1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/are_defined_correctly", test_color_enum2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* End of the test list */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* Test suite */
static const MunitSuite suite = {
    (char*) "/colors",  /* Name of the suite */
    tests,             /* Array of test cases */
    NULL,              /* Sub-suites (none in this case) */
    1,                 /* Number of iterations */
    MUNIT_SUITE_OPTION_NONE  /* Options */
};

/* Main function */
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

