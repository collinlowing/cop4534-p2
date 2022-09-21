/***************************************************************
  Student Name: Collin Lowing
  File Name: Simulation.hpp
  Project 2

  Simulation runner. Calls all methods to drive simulation processes.
***************************************************************/

#ifndef COP4534_P2_SIMULATION_HPP
#define COP4534_P2_SIMULATION_HPP

#include <random>
#include <iomanip>
#include <iostream>

class Simulation {
private:
    const int INTERVAL_MIN = 0;
    const int INTERVAL_MAX = 1;
public:
    double getNextRandomInterval(double avg);
};


#endif //COP4534_P2_SIMULATION_HPP
