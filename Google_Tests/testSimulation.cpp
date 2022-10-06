/***************************************************************
  Student Name: Collin Lowing
  File Name: testSimulation.cpp
  Project 2

  tests Simulation class methods
***************************************************************/

#include "gtest/gtest.h"
#include "../Simulation.hpp"

TEST(SimulationTests, testRandomIntervals) {
    Simulation sim(2,4,3,2000);

    for(int i = 0; i < 2000; i++)
    {
        std::cout << sim.getNextRandomInterval(2) << std::endl;
    }
}

TEST(SimulationTests, testRandomFloat) {
    Simulation sim(2, 4, 3, 2000);

    for(int i = 0; i < 2000; i++)
    {
        EXPECT_TRUE(sim.getRandomFloat() > 0
                        && sim.getRandomFloat() < 1);
    }
}