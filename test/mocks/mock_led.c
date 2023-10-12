/*!
 *******************************************************************************
 * @file mock_led.c
 *
 * @brief Mocked implementation for those prototypes at `led.h`
 *        Mocks are expected to be handled by CMocka framework.
 *
 * @authors Shreyas Gokhale (shreyas.gokhale@gropyus.com)
 * @date 11.10.23
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2023 Gropyus GmbH
 * All rights reserved.
 *******************************************************************************
 */


#include <setjmp.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <cmocka.h>

int led_initialize(void) {
    function_called();
    return mock_type(bool);
}
