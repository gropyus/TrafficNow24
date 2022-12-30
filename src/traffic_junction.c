#include <stdlib.h>
#include <stdio.h>

#include "traffic_junction.h"


/*
- There are 20 cars in total.
- 1 - 5 vehicles arrive randomly in front of the signal, periodically.
- Signal checks for number of vehicles periodically.
- If number of vehicles is > 3, the signal turns green for the vehicles. (Start condition)
- We assume all vehicles pass once the signal is green. So the number of vehicles waiting is 0 in the next period.
*/


static const int total_vehicles = 20;
int remaining_vehicles = total_vehicles;

int get_traffic()
{
    int traffic = rand() % (5) + 1;
    if (remaining_vehicles > traffic)
        remaining_vehicles -= traffic;
    else
    {
        traffic = remaining_vehicles;
        remaining_vehicles = 0;
    }
    return traffic;
}

void run_signal(int traffic)
{
    static int backlog;
    backlog += traffic;
    printf("%d vehicles arrived!, current pileup: %d\n", traffic, backlog);
    if (backlog > 3)
    {
        printf("Green signal!\n");
        backlog = 0;
    }
    else
    {
        printf("Red signal!\n");
    }
}


int simulate_traffic_junction()
{
    printf("*** Traffic simulator 9000 ***\n");
    int period = 0;
    while (remaining_vehicles > 0)
    {
        printf("Period: %d \n", period);
        run_signal(get_traffic());
        period++;
    }
    return remaining_vehicles;
}
