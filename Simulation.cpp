/***************************************************************
  Student Name: Collin Lowing
  File Name: Simulation.cpp
  Project 2

  Simulation runner. Calls all methods to drive simulation processes.
***************************************************************/

#include "Simulation.hpp"

double Simulation::getNextRandomInterval(double avg) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(INTERVAL_MIN, INTERVAL_MAX);

    return distr(eng);
}
