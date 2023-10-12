#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <cmocka.h>
#include <stdbool.h>

#include "traffic_junction.h"

void test_no_car_remaining_at_end(void **state);

void test_lot_of_cars_return_success(void **state);

void test_invalid_cars_return_failure(void **state);

void test_led_fail_return_fail(void **state);


void test_no_car_remaining_at_end(void **state) {

    // Initial conditions
    int no_of_cars = 20;
    int remaining_vehicles = 20;
    bool response;

    // Check if we get a call to this function, when we call the next function
    expect_function_call(led_initialize);
    will_return(led_initialize, true);

    response = simulate_traffic_junction(no_of_cars, &remaining_vehicles);

    // Check if we got a success
    assert_true(response);

    // Check if we have no pending cars
    assert_int_equal(remaining_vehicles, 0);
}

void test_lot_of_cars_return_success(void **state) {
    // Initial conditions
    uint16_t no_of_cars = 255;
    int remaining_vehicles = 255;
    bool response;

    // Check if we get a call to this function, when we call the next function
    expect_function_call(led_initialize);
    will_return(led_initialize, true);

    response = simulate_traffic_junction(no_of_cars, &remaining_vehicles);

    // Check if we got a success
    assert_true(response);

    // Check if we have no pending cars
    assert_int_equal(remaining_vehicles, 0);
}

void test_invalid_cars_return_failure(void **state) {

    // Initial conditions
    int no_of_cars = -100;
    bool response;

    response = simulate_traffic_junction(no_of_cars, NULL);

    // Check if we got a fail
    assert_false(response);

}


void test_led_fail_return_fail(void **state) {

    // Initial conditions
    int no_of_cars = 10;
    int remaining_vehicles = 255;
    bool response;

    // Check if we get a call to this function, when we call the next function
    expect_function_call(led_initialize);
    will_return(led_initialize, false);

    response = simulate_traffic_junction(no_of_cars, &remaining_vehicles);

    // Check if we got a fail
    assert_false(response);

}


int main(void) {
    const struct CMUnitTest traffic_junction_tests[] =
            {
                    cmocka_unit_test(test_no_car_remaining_at_end),
                    cmocka_unit_test(test_lot_of_cars_return_success),
                    cmocka_unit_test(test_invalid_cars_return_failure),
                    cmocka_unit_test(test_led_fail_return_fail),
            };

    return cmocka_run_group_tests(traffic_junction_tests, NULL, NULL);
}
