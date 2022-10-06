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
    priorityQueue = new PriorityQueue(MAX_SIZE);
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
    // generate first arrival
    serverAvailableCount = M;
    double arrivalInterval = getNextRandomInterval(lambda);
    priorityQueue->enqueue(Event::ARRIVAL, arrivalInterval);

    while(!priorityQueue->isEmpty()) {
        processNextEvent(priorityQueue->getTopEvent()->getType());

        if(isMoreArrivals() && priorityQueue->getSize() <= M + 1) {
            arrivalInterval = getNextRandomInterval(lambda);
            priorityQueue->enqueue(Event::ARRIVAL, arrivalInterval);
        }
    }

    printResults(); // finished
}

void Simulation::processNextEvent(int type) {
    if(type == Event::ARRIVAL) {
        if(serverAvailableCount > 0) {
            --serverAvailableCount;

            Event * event = priorityQueue->getTopEvent();

            // calculate time intervals for departure
            double startOfServiceTime = event->getArrivalTime() + totalSimulationTime;
            double timeInterval = getNextRandomInterval(mu);
            double departureTime = startOfServiceTime + timeInterval;

            // set time intervals for event departure
            event->setDepartureTime(departureTime);
            event->setServiceTimeStart(startOfServiceTime);
            event->setType(Event::DEPARTURE);

            priorityQueue->dequeue(); // delete arrival
            priorityQueue->enqueue(event); // add departure
        }
        else {
            Event * event = priorityQueue->getTopEvent();
            fifoQueue.insertBack(event);
            priorityQueue->dequeue();
        }
    }
    else if(type == Event::DEPARTURE) {
        serverAvailableCount++;
        processStatistics();

        // check if events are waiting in fifoQueue
        if(fifoQueue.size() == 0) {
            Event * event = fifoQueue.getFront();
            double startOfServiceTime = event->getServiceTimeStart();
            double timeInterval = getNextRandomInterval(mu);
            double departureTime = startOfServiceTime + timeInterval;
            priorityQueue->enqueue(Event::DEPARTURE, departureTime);
            --serverAvailableCount;
            fifoQueue.deleteFront();
        }
    }
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
    return totalIdleTime / totalSimulationTime;
}

double Simulation::getAverageTimeSpent() {
    return (totalWaitTime + totalServiceTime) / numberOfEvents;
}

double Simulation::getUtilizationFactor() {
    return totalServiceTime / (totalSimulationTime * M);
}

double Simulation::getAverageWaitTime() {
    return totalWaitTime / numEventsWait;
}

Simulation::~Simulation() {
    delete priorityQueue;
}

bool Simulation::isMoreArrivals() {
    int remaining = numberOfEvents - (numberOfArrivals + numberOfDepartures);
    return remaining > 0;
}

void Simulation::processStatistics() {
    Event * event = priorityQueue->getTopEvent();
    double currentWaitTime = event->getServiceTimeStart() - event->getArrivalTime();
    if(currentWaitTime > 0) {
        numEventsWait++;
    }

    totalWaitTime += currentWaitTime;
    totalServiceTime += event->getDepartureTime() - event->getServiceTimeStart();
    if(serverAvailableCount == M) {
        Event* nextEvent = priorityQueue->getNextArrival();
        totalIdleTime += nextEvent->getArrivalTime();
    }
}

