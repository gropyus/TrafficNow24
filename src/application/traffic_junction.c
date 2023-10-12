/*!
*******************************************************************************
* @file traffic_junction.c
*
* @brief Simulates a traffic junction
*
* @authors Shreyas Gokhale (shreyas.gokhale@gropyus.com)
*
* @date 11.10.2023
*
* @par
* COPYRIGHT NOTICE: (c) 2023 Gropyus GmbH
* All rights reserved.
*******************************************************************************
*/

/** @brief
 * - Some number of cars (< 255) are going to pass through a junction
 *   Our job is to add a signal light and control the flow of the traffic
 *   Some conditions:
 *
 * - 1 - 5 vehicles arrive randomly in front of the signal, periodically.
 * - Signal checks for number of vehicles periodically.
 * - If number of vehicles is > 3, the signal turns green for the vehicles.
 *   (Start condition)
 * - We assume all vehicles pass once the signal is green. So the number of
 *   vehicles waiting is 0 in the next period, including the last iteration
 *
 *   The simulation should return the number of remaining vehicles
 */


/*
 *******************************************************************************
 * #include Statements                                                         *
 *******************************************************************************
 */

#include <stdlib.h>
#include <stdio.h>

#include "led.h"
#include "traffic_junction.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Data types                                                                  *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Private Function Prototypes                                                 *
 *******************************************************************************
 */

int get_traffic(void);

void run_signal(int traffic);

/*
 *******************************************************************************
 * Public Data Declarations                                                    *
 *******************************************************************************
 */

int g_remaining_vehicles;
int g_no_of_cars;

/*
 *******************************************************************************
 * Static Data Declarations                                                    *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

/**
 * Simulate a traffic junction
 *
 * @param      no_of_cars               Number of cars in total
 * @param[out] remaining_vehicles       Pointer to remaining vehicles
 *                                      after simulation
 * @retval     result                   true if function succeeds
 *                                      false if function fails
 */
int simulate_traffic_junction(int no_of_cars, int *remaining_vehicles) {
    int result = 1;

    g_remaining_vehicles = no_of_cars;
    printf("*** Traffic simulator 9000 ***\n");

    led_initialize();

    while (g_remaining_vehicles > 0) {
        run_signal(get_traffic());
    }

    return result;
}


/*
*******************************************************************************
* Private Function Bodies                                                      *
*******************************************************************************
*/

int get_traffic(void) {
    int traffic = rand() % (5) + 1;
    if (g_remaining_vehicles > traffic)
        g_remaining_vehicles -= traffic;
    else {
        traffic = g_remaining_vehicles;
        g_remaining_vehicles = 0;
    }
    return traffic;
}

void run_signal(int traffic) {
    static int backlog;
    backlog += traffic;
    printf("%d vehicles arrived!, current pileup: %d\n", traffic, backlog);
    if (backlog > 3) {
        // TODO: Make signal Green
        printf("Green signal!\n");
        backlog = 0;
    } else {
        // TODO: Make signal Red
        printf("Red signal!\n");
    }
}
