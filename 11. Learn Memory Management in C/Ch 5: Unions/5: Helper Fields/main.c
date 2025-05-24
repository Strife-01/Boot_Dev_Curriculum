#include "exercise.h"
#include "munit.h"

static MunitResult test_packet_header(const MunitParameter params[], void *user_data) {
    packet_header_t header;

    // Initializing tcp_header members
    header.tcp_header.src_port = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num = 0x9ABCDEF0;

    // Assertions
    munit_assert_uint16(header.tcp_header.src_port, ==, 0x1234);
    munit_assert_uint16(header.tcp_header.dest_port, ==, 0x5678);
    munit_assert_uint32(header.tcp_header.seq_num, ==, 0x9ABCDEF0);

    // Raw data assertions
    header.tcp_header.src_port = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num = 0x9ABCDEF0;

    munit_assert_uint8(header.raw[0], ==, 0x34);
    munit_assert_uint8(header.raw[1], ==, 0x12);
    munit_assert_uint8(header.raw[2], ==, 0x78);
    munit_assert_uint8(header.raw[3], ==, 0x56);
    munit_assert_uint8(header.raw[4], ==, 0xF0);
    munit_assert_uint8(header.raw[5], ==, 0xDE);
    munit_assert_uint8(header.raw[6], ==, 0xBC);
    munit_assert_uint8(header.raw[7], ==, 0x9A);

    return MUNIT_OK;
}

int main(int argc, char *argv[]) {
    MunitTest tests[] = {
        {
            "/test_packet_header", // name
            test_packet_header,    // test function
            NULL,                  // setup function
            NULL,                  // tear down function
            MUNIT_TEST_OPTION_NONE,// options
            NULL                   // parameters
        },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/example", // name
        tests,      // tests
        NULL,       // suites
        1,          // iterations
        MUNIT_SUITE_OPTION_NONE // options
    };

    return munit_suite_main(&suite, NULL, argc, argv);
}

