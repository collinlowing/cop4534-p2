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
    this->heap = new Heap(MAX_SIZE);
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
    serverAvailableCount = M;
    // generate first arrival
    double arrivalInterval = getNextRandomInterval(lambda);
    Event* firstEvent = new Event(Event::ARRIVAL, arrivalInterval);
    heap->insert(firstEvent);
    executedEvents++;

    while(!heap->isEmpty()) {
        Event* nextEvent = heap->getMin();
        std::cout << nextEvent->getType() << std::endl;
        processNextEvent(nextEvent->getType());

        if(heap->getSize() <= M + 1 && isMoreArrivals()) {
            arrivalInterval = getNextRandomInterval(lambda);
            Event* newEvent = new Event(Event::ARRIVAL, arrivalInterval);
            heap->insert(newEvent);
            executedEvents++;
        }
    }

    printResults(); // finished
}

void Simulation::processNextEvent(int type) {
    if(type == Event::ARRIVAL) {
        if(serverAvailableCount > 0) {
            --serverAvailableCount;

            Event * event = heap->popMin();

            // calculate time intervals for departure
            double startOfServiceTime = event->getArrivalTime() + totalSimulationTime;
            double timeInterval = getNextRandomInterval(mu);
            double departureTime = startOfServiceTime + timeInterval;

            // set time intervals for event departure
            event->setDepartureTime(departureTime);
            event->setServiceTimeStart(startOfServiceTime);
            event->setType(Event::DEPARTURE);

            heap->insert(event); // add departure
        }
        else {
            Event * event = heap->getMin();
            fifoQueue.insertBack(event);
            heap->popMin();
        }
    }
    else if(type == Event::DEPARTURE) {
        Event * departure = heap->popMin(); // get departure and delete it from heap
        serverAvailableCount++;
        processStatistics(departure);

        // check if events are waiting in fifoQueue
        if(fifoQueue.size() > 0) {
            Event * event = fifoQueue.getFront();
            // calculate time intervals for departure
            double startOfServiceTime = event->getArrivalTime() + totalSimulationTime;
            double timeInterval = getNextRandomInterval(mu);
            double departureTime = startOfServiceTime + timeInterval;

            // set time intervals for event departure
            event->setDepartureTime(departureTime);
            event->setServiceTimeStart(startOfServiceTime);
            event->setType(Event::DEPARTURE);

            heap->insert(event); // add departure

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
    return (double) numEventsWait / numberOfEvents;
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

bool Simulation::isMoreArrivals() {
    return executedEvents <= numberOfEvents;
}

void Simulation::processStatistics(Event* departure) {
    double currentWaitTime = departure->getServiceTimeStart() - departure->getArrivalTime();

    if(currentWaitTime > 0) {
        numEventsWait++;
    }

    totalWaitTime += currentWaitTime;
    totalServiceTime += departure->getDepartureTime() - departure->getServiceTimeStart();
    if(serverAvailableCount == M && !heap->isEmpty()) {
        Event * event = heap->getMin(); // get next arrival
        totalIdleTime += event->getArrivalTime();
    }
}

Simulation::~Simulation() {
    delete heap;
}
