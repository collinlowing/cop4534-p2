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
#include "Heap.hpp"

class Simulation {
private:
    int lambda;
    int mu;
    int M;
    int numberOfEvents;
    int executedEvents = 0;
    int numberOfArrivals = 0;
    int numberOfDepartures = 0;
    int serverAvailableCount = 0;
    double totalSimulationTime = 0;
    int numEventsWait = 0;
    double totalIdleTime = 0;
    double totalWaitTime = 0;
    double totalServiceTime = 0;
    const int INTERVAL_MIN = 0;
    const int INTERVAL_MAX = 1;
    const int MAX_SIZE = 200;
    Heap* heap;
    FIFO_Queue fifoQueue;
public:
    Simulation(int lambda, int mu, int M, int numberOfEvents);
    
    double getNextRandomInterval(double avg);

    double getRandomFloat();

    void startSimulation();

    double getAverageWaitTime();

    double getUtilizationFactor();

    std::string printResults();

    double getProbabilityWaitForService();

    double getPercentIdleTime();

    double getAverageTimeSpent();

    void processNextEvent(int type);

    bool isMoreArrivals();

    void processStatistics(Event* departure);

    ~Simulation();
};


#endif //COP4534_P2_SIMULATION_HPP
