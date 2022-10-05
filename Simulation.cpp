/***************************************************************
  Student Name: Collin Lowing
  File Name: Simulation.cpp
  Project 2

  Simulation runner. Calls all methods to drive simulation processes.
***************************************************************/

#include "Simulation.hpp"

Simulation::Simulation(int lambda, int mu, int M, int numberOfEvents) {
    this->lambda = lambda;
    this->mu = mu;
    this->M = M;
    this->numberOfEvents = numberOfEvents;
}

double Simulation::getNextRandomInterval(double avg) {
    double f = getRandomFloat();

    double intervalTime = -1 * (1.0/avg) * log(f);

    return intervalTime;
}

double Simulation::getRandomFloat() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(INTERVAL_MIN, INTERVAL_MAX);
    return distr(eng);
}

void Simulation::startSimulation() {
    // generate arrivals until M+1 arrivals

    // add idle time until first arrival

    // assign events to server

    // generate departure

    // add service time

    // if arrival occurs and servers available == M then add to FIFO queue

    // when departure occurs, pop next arrival and assign to server.

    printResults(); // finished
}

Event* Simulation::processArrival() {
    //Event newArrival(Event::ARRIVAL);
    return nullptr;
}

Event* Simulation::processDeparture() {
    return nullptr;
}

std::string Simulation::printResults() {
    AnalyticalModel model(lambda, mu, M);
    double theoryPo = model.getPercentIdleTime();
    double theoryL = model.getAverageTotalPeople();
    double theoryW = model.getAverageTimeSpent();
    double theoryLq = model.getAverageNumberInQueue();
    double theoryWq = model.getAverageTimeWaitingInQueue();
    double theoryRho = model.getProportionOfResourcesUsedByArrivals();

    std::stringstream results;
    results << std::fixed;
    results << std::setprecision(4);
    results << "Theoretical Results:" << "\n";
    results << "Po = "  << theoryPo   << "\n";
    results << "L = "   << theoryL    << "\n";
    results << "W = "   << theoryW    << "\n";
    results << "Lq = "  << theoryLq   << "\n";
    results << "Wq = "  << theoryWq   << "\n";
    results << "rho = " << theoryRho  << "\n";
    results << std::endl;

    double simPo = getPercentIdleTime();
    double simW = getAverageTimeSpent();
    double simWq = getAverageWaitTime();
    double simRho = getUtilizationFactor();
    double probabilityWaitForService = getProbabilityWaitForService();

    results << "Simulation Results:" << "\n";
    results << "Po = "  << simPo     << "\n";
    results << "W = "   << simW      << "\n";
    results << "Wq = "  << simWq     << "\n";
    results << "rho = " << simRho    << "\n";
    results << "probability of having to wait for service = "
            <<  probabilityWaitForService << std::endl;

    std::cout << results.str();

    return results.str();
}

double Simulation::getProbabilityWaitForService() {
    return numEventsWait / numberOfEvents;
}

double Simulation::getPercentIdleTime() {
    return idleTime / totalSimulationTime;
}

double Simulation::getAverageTimeSpent() {
    return (waitingTime + serviceTime) / numberOfEvents;
}

double Simulation::getUtilizationFactor() {
    return serviceTime / (totalSimulationTime * M);
}

double Simulation::getAverageWaitTime() {
    return waitingTime / numEventsWait;
}
