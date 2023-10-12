#ifndef TRAFFIC_JUNCTION_H
#define TRAFFIC_JUNCTION_H

/**
 * Simulate a traffic junction
 *
 * @param      no_of_cars               Number of cars in total
 * @param[out] remaining_vehicles       Pointer to remaining vehicles
 *                                      after simulation
 * @retval     result                   true if function succeeds
 *                                      false if function fails
 */
int simulate_traffic_junction(int no_of_cars, int *remaining_vehicles);

#endif
