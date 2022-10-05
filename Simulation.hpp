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
#include <sstream>
#include "AnalyticalModel.hpp"
#include "FIFO_Queue.hpp"
#include "PriorityQueue.hpp"

class Simulation {
private:
    int lambda;
    int mu;
    int M;
    int numberOfEvents;
    double totalSimulationTime = 0;
    int numEventsWait = 0;
    double idleTime = 0;
    double waitingTime = 0;
    double serviceTime = 0;
    const int INTERVAL_MIN = 0;
    const int INTERVAL_MAX = 1;
    const int MAX_SIZE = 200;
    PriorityQueue* priorityQueue;
    FIFO_Queue fifoQueue;
public:
    Simulation(int lambda, int mu, int M, int numberOfEvents);
    
    double getNextRandomInterval(double avg);

    double getRandomFloat();

    void startSimulation();

    Event* processArrival();

    Event* processDeparture();

    double getAverageWaitTime();

    double getUtilizationFactor();

    std::string printResults();

    double getProbabilityWaitForService();

    double getPercentIdleTime();

    double getAverageTimeSpent();

    ~Simulation();
};


#endif //COP4534_P2_SIMULATION_HPP
