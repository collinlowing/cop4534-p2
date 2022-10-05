/***************************************************************
  Student Name: Collin Lowing
  File Name: testSimulation.cpp
  Project 2

  tests Simulation class methods
***************************************************************/

#include "gtest/gtest.h"
#include "../Simulation.hpp"

TEST(SimulationTests, test) {
    Simulation sim;

    for(int i = 0; i < 10; i++)
    {
        std::cout << sim.getNextRandomInterval(2) << std::endl;
    }
}