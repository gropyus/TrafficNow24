# TrafficNow24

Welcome to the future of smart mobility, where a smart traffic signal can detect the number of vehicles on the junction
and can automatically turn green!

For coding interviews only!

## Problem
Some number of cars (< 255) are going to pass through a junction
Our job is to add a signal light and control the flow of the traffic

Some conditions:

- 1 - 5 vehicles arrive randomly in front of the signal, periodically.
- Signal checks for number of vehicles periodically.
- If number of vehicles is > 3, the signal turns green for the vehicles.
  (Start condition)
- We assume all vehicles pass once the signal is green. So the number of
  vehicles waiting is 0 in the next period, including the last iteration
- The simulation should return the number of remaining vehicles

## Running

Make sure you have `CMake` > `3.18` 

```shell
mkdir build && cd build
cmake ../
make all
make test
```
