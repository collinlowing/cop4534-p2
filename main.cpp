/***************************************************************
  Student Name: Collin Lowing
  File Name: main.cpp
  Project 2

  Runs methods for Simulation class
***************************************************************/

#include <iostream>
#include "Simulation.hpp"
#include "FileParser.hpp"

int main() {
    // initialize
    FileParser parser;
    std::vector<int> testValues = parser.getTestValuesFromFile("test1.txt");
    int lambda = testValues.at(0);
    int mu = testValues.at(1);
    int M = testValues.at(2);
    int numberOfEvents = testValues.at(3);
    Simulation sim(lambda, mu, M, numberOfEvents);
    // action
    sim.startSimulation();

    return 0;
}
