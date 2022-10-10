/***************************************************************
  Student Name: Collin Lowing
  File Name: Simulation.cpp
  Project 2

  Simulation runner. Calls all methods to drive simulation processes.
***************************************************************/

#include "Simulation.hpp"

// sets values for simulation
Simulation::Simulation(int lambda, int mu, int M, int numberOfEvents) {
    this->lambda = lambda;
    this->mu = mu;
    this->M = M;
    this->numberOfEvents = numberOfEvents;
    this->heap = new Heap(MAX_SIZE); // initialize heap
}

double Simulation::getNextRandomInterval(double avg) {
    double f = getRandomFloat();

    double intervalTime = -1 * (1.0 / avg) * log(f);

    return intervalTime;
}

// intermediate method for getNextRandomInterval
double Simulation::getRandomFloat() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(INTERVAL_MIN, INTERVAL_MAX);
    return distr(eng);
}

// runs the simulation loop
void Simulation::startSimulation() {
    // initialize server count
    serverAvailableCount = M;

    // generate first arrival
    double arrivalInterval = getNextRandomInterval(lambda);
    totalSimulationTime += arrivalInterval;
    Event *firstEvent = new Event(Event::ARRIVAL, arrivalInterval);
    firstEvent->setArrivalTime(arrivalInterval);
    heap->insert(firstEvent);

    // main simulation loop
    while (!heap->isEmpty() && isMoreArrivals()) {
        Event *nextEvent = heap->getMin();
        processNextEvent(nextEvent->getType());

        // generates new arrivals
        if (heap->getSize() <= M + 1 && isMoreArrivals()) {
            arrivalInterval = getNextRandomInterval(lambda);
            totalSimulationTime += arrivalInterval;
            Event *newEvent = new Event(Event::ARRIVAL, arrivalInterval);
            newEvent->setArrivalTime(arrivalInterval + totalSimulationTime);
            heap->insert(newEvent);
        }
    }

    printResults(); // finished prints results
}

void Simulation::processNextEvent(int type) {
    if (type == Event::ARRIVAL) { // process arrival
        if (serverAvailableCount > 0) {
            --serverAvailableCount;

            Event *event = heap->popMin(); // get arrival and remove it from the heap

            // calculate time intervals for departure
            double startOfServiceTime = event->getArrivalTime() + totalSimulationTime;
            double timeInterval = getNextRandomInterval(mu);
            totalSimulationTime += timeInterval;
            double departureTime = startOfServiceTime + timeInterval;

            // set time intervals for event departure
            event->setDepartureTime(departureTime);
            event->setServiceTimeStart(startOfServiceTime);
            event->setType(Event::DEPARTURE);

            heap->insert(event); // add departure to heap
        } else { // servers are full, move from Heap to FIFO Queue
            Event *event = heap->popMin();
            fifoQueue.insertBack(event);
        }
    } else if (type == Event::DEPARTURE) { // process departure
        Event *departure = heap->popMin(); // get departure and delete it from heap
        serverAvailableCount++;
        processStatistics(departure);

        // check if events are waiting in fifoQueue
        if (fifoQueue.size() > 0) {
            Event *event = fifoQueue.getFront();
            // calculate time intervals for departure
            double startOfServiceTime = event->getArrivalTime() + totalSimulationTime;
            double timeInterval = getNextRandomInterval(mu);
            totalSimulationTime += timeInterval;
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
    results << "Po = " << theoryPo << "\n";
    results << "L = " << theoryL << "\n";
    results << "W = " << theoryW << "\n";
    results << "Lq = " << theoryLq << "\n";
    results << "Wq = " << theoryWq << "\n";
    results << "rho = " << theoryRho << "\n";
    results << std::endl;

    double simPo = getPercentIdleTime();
    double simW = getAverageTimeSpent();
    double simWq = getAverageWaitTime();
    double simRho = getUtilizationFactor();
    double probabilityWaitForService = getProbabilityWaitForService();

    results << "Simulation Results:" << "\n";
    results << "Po = " << simPo << "\n";
    results << "W = " << simW << "\n";
    results << "Wq = " << simWq << "\n";
    results << "rho = " << simRho << "\n";
    results << "probability of having to wait for service = "
            << probabilityWaitForService << std::endl << std::endl;

    std::cout << results.str();

    return results.str();
}

double Simulation::getProbabilityWaitForService() {
    double top = numEventsWait;
    double bottom = numberOfEvents;
    return top / bottom;
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
    return executedEvents < numberOfEvents;
}

void Simulation::processStatistics(Event *departure) {
    double currentWaitTime = departure->getServiceTimeStart() - departure->getArrivalTime();

    if (currentWaitTime > 0) { // if waiting, add to number of events wait count
        numEventsWait++;
    }

    totalWaitTime += currentWaitTime;
    totalServiceTime += std::abs(departure->getDepartureTime() -
                                 departure->getServiceTimeStart()); // time interval it takes to leave system after arrival
    if (serverAvailableCount == M && !heap->isEmpty()) { // idle time where no events are being served or waiting
        Event *event = heap->getMin(); // get next arrival for idle time
        totalIdleTime += event->getArrivalTime();
    }
    executedEvents++;
}