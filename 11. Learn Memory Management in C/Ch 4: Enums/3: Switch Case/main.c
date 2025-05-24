#include "munit.h"
#include "http.h"  // Include http.h where the http_to_str function and HttpErrorCode enum are defined

/* Test case 1 */
static MunitResult test_switch_enum(const MunitParameter params[], void* data) {
    /* Munit assertion macros */
    munit_assert_string_equal(http_to_str(HTTP_BAD_REQUEST), "400 Bad Request");
    munit_assert_string_equal(http_to_str(HTTP_UNAUTHORIZED), "401 Unauthorized");
    munit_assert_string_equal(http_to_str(HTTP_NOT_FOUND), "404 Not Found");
    munit_assert_string_equal(http_to_str(HTTP_TEAPOT), "418 I AM A TEAPOT!");
    munit_assert_string_equal(http_to_str(HTTP_INTERNAL_SERVER_ERROR), "500 Internal Server Error");
    return MUNIT_OK;
}

/* Test case 2 */
static MunitResult test_switch_enum_default(const MunitParameter params[], void* data) {
    /* Munit assertion macros */
    munit_assert_string_equal(http_to_str((HttpErrorCode)999), "Unknown HTTP status code");
    return MUNIT_OK;
}

/* Test cases */
static MunitTest tests[] = {
    { (char*) "/switch_enum", test_switch_enum, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/switch_enum_default", test_switch_enum_default, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* End of the test list */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* Test suite */
static const MunitSuite suite = {
    (char*) "/http",  /* Name of the suite */
    tests,           /* Array of test cases */
    NULL,            /* Sub-suites (none in this case) */
    1,               /* Number of iterations */
    MUNIT_SUITE_OPTION_NONE  /* Options */
};

/* Main function */
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

