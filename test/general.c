#include <stdlib.h>
#include <setjmp.h>
#include <stdarg.h>

#include "cmocka.h"

#include "traffic_junction.h"

void test_no_traffic_pending(void **state)
{
    assert_int_equal(simulate_traffic_junction(),0);
}

int main()
{
    const struct CMUnitTest traffic_junction_tests[] =
        {
            cmocka_unit_test(test_no_traffic_pending),
        };

    return cmocka_run_group_tests(traffic_junction_tests, NULL, NULL);
}