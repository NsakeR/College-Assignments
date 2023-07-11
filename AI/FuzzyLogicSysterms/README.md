1. ryzyko.fcl - Create an FCL file for a fuzzy driver to help assess the risk of causing an accident. 
This risk is to depend on: the age of the driver and the power of the car. Assume the range of age -
[20,60] and power - [20,220]. These variables are given as input to the model. The output, on the other hand, is 
risk of causing an accident - [0,30].

2. klimatyzator.fcl - Design a fuzzy controller for air conditioning and save its configuration in an FCL file. Assume that 
linguistic variables related to temperatures and the air conditioner's on level each have 5 
values.

3. washing_maching.fcl - build a fuzzy controller for an automatic washing machine and 
save its configuration in an FCL file.

4. car1.fcl & car1.cpp - Design a fuzzy system that, for a given distance from an obstacle (from the interval [0,1000] m) 
will return the suggested vehicle speed (from the interval [0,120] km/h). Create a suitable FCL file. 
Convert it to C++ and write a simple vehicle simulator that, when given an initial distance 
from an obstacle prints out the subsequent values of speed and distance

5. moving_car.fcl & moving_car.cpp - Write a program that, for a given distance from an obstacle, writes successive changes in distance and 
speed until it stops. The program is to write out the distance and speed after the change.