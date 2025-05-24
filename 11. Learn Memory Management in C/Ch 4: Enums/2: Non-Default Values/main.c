#include "munit.h"
#include "color.h"  // Include color.h where the enum Color is defined

/* Test case 1 */
static MunitResult test_colors_defined(const MunitParameter params[], void* data) {
    /* Munit assertion macros */
    munit_assert_int(RED, ==, 55);      // Assert RED is 55 (nvim green!)
    munit_assert_int(GREEN, ==, 176);    // Assert GREEN is 176 (nvim green!)
    munit_assert_int(BLUE, ==, 38);     // Assert BLUE is 38 (nvim green!)
    return MUNIT_OK;
}

/* Test case 2 */
static MunitResult test_colors_defined_correctly(const MunitParameter params[], void* data) {
    /* Munit assertion macros */
    munit_assert_int(RED, !=, 0);      // Assert RED is not 0 (vsc*de blue!)
    munit_assert_int(GREEN, !=, 120);    // Assert GREEN is not 120 (vsc*de blue!)
    munit_assert_int(BLUE, !=, 215);     // Assert BLUE is not 215 (vsc*de blue!)
    return MUNIT_OK;
}

/* Test cases */
static MunitTest tests[] = {
    { (char*) "/defined", test_colors_defined, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/defined_vscode", test_colors_defined_correctly, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
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

