#include <stdlib.h>
#include "munit.h"      // Ensure munit.h is included
#include "snekobject.h" // Your project header

// Forward declarations of test functions
static MunitResult test_returns_null(const MunitParameter params[], void* user_data_or_fixture);
static MunitResult test_vec_multiple_objects(const MunitParameter params[], void* user_data_or_fixture);
static MunitResult test_vec_same_object(const MunitParameter params[], void* user_data_or_fixture);

// Test function definitions
static MunitResult
test_returns_null(const MunitParameter params[], void* user_data_or_fixture) {
    (void)params; // Mark as unused if not needed
    (void)user_data_or_fixture; // Mark as unused if not needed

    snek_object_t *vec = new_snek_vector3(NULL, NULL, NULL);

    // Using standard MUnit assertion: munit_assert_ptr_null(pointer)
    munit_assert_ptr_null(vec);

    // Using standard MUnit assertion: munit_assert_true(condition)
    // Assuming boot_all_freed() returns a value that can be evaluated as true/false
    munit_assert_true(boot_all_freed());

    return MUNIT_OK;
}

static MunitResult
test_vec_multiple_objects(const MunitParameter params[], void* user_data_or_fixture) {
    (void)params;
    (void)user_data_or_fixture;

    snek_object_t *x = new_snek_integer(1);
    snek_object_t *y = new_snek_integer(2);
    snek_object_t *z = new_snek_integer(3);
    snek_object_t *vec = new_snek_vector3(x, y, z);

    munit_assert_ptr_not_null(vec);

    // Using standard MUnit assertion: munit_assert_ptr_equal(ptr1, ptr2)
    munit_assert_ptr_equal(x, vec->data.v_vector3.x);
    munit_assert_ptr_equal(y, vec->data.v_vector3.y);
    munit_assert_ptr_equal(z, vec->data.v_vector3.z);

    // Using standard MUnit assertion: munit_assert_int(val1, op, val2)
    munit_assert_int(vec->data.v_vector3.x->data.v_int, ==, 1);
    munit_assert_int(vec->data.v_vector3.y->data.v_int, ==, 2);
    munit_assert_int(vec->data.v_vector3.z->data.v_int, ==, 3);

    free(x);
    free(y);
    free(z);
    free(vec);
    munit_assert_true(boot_all_freed());

    return MUNIT_OK;
}

static MunitResult
test_vec_same_object(const MunitParameter params[], void* user_data_or_fixture) {
    (void)params;
    (void)user_data_or_fixture;

    snek_object_t *i = new_snek_integer(1);
    snek_object_t *vec = new_snek_vector3(i, i, i);

    munit_assert_ptr_not_null(vec);

    munit_assert_ptr_equal(i, vec->data.v_vector3.x);
    munit_assert_ptr_equal(i, vec->data.v_vector3.y);
    munit_assert_ptr_equal(i, vec->data.v_vector3.z);

    munit_assert_int(vec->data.v_vector3.x->data.v_int, ==, 1);
    munit_assert_int(vec->data.v_vector3.y->data.v_int, ==, 1);
    munit_assert_int(vec->data.v_vector3.z->data.v_int, ==, 1);

    i->data.v_int = 2;

    munit_assert_int(vec->data.v_vector3.x->data.v_int, ==, 2);
    munit_assert_int(vec->data.v_vector3.y->data.v_int, ==, 2);
    munit_assert_int(vec->data.v_vector3.z->data.v_int, ==, 2);

    free(i);
    free(vec);
    munit_assert_true(boot_all_freed());

    return MUNIT_OK;
}

// Define the tests array
static MunitTest tests[] = {
    // The munit_test macro is a helper for struct initialization:
    // { (char*) test_name_str, test_func_ptr, setup_func, teardown_func, options, params }
    { (char*) "/returns_null", test_returns_null, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/multiple_objects", test_vec_multiple_objects, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/same_object", test_vec_same_object, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    // End of tests marker (munit_null_test expands to a NULL-filled MunitTest struct)
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Define the test suite
// MunitSuite struct: { name_prefix, tests_array, sub_suites_array, iterations, options }
static const MunitSuite suite = {
    (char*) "object-vector", // Suite name prefix
    tests,                   // Array of MunitTest
    NULL,                    // No sub-suites
    1,                       // Number of iterations
    MUNIT_SUITE_OPTION_NONE  // Options
};

int main(int argc, char* argv[]) {
    // Pass argc and argv to munit_suite_main to enable MUnit's command-line features
    return munit_suite_main(&suite, NULL, argc, argv);
}
