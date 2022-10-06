/***************************************************************
  Student Name: Collin Lowing
  File Name: PriorityQueue.cpp
  Project 2

  Stores new arrivals and departures in a priority ordered list.
  First In, Highest Priority Out
***************************************************************/

#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue(int MAX_SIZE) {
    this->MAX_SIZE = MAX_SIZE;
    priorityQueue = new Event*[MAX_SIZE];
}

void PriorityQueue::enqueue(int type, double processTime) {
    // increase the allocated current size
    current++;

    // insert the new event
    priorityQueue[current] = new Event(type, processTime);
}

void PriorityQueue::enqueue(Event *newEvent) {
    current++;

    priorityQueue[current] = newEvent;
}

Event *PriorityQueue::getTopEvent() {
    double highestPriority = -1;
    std::size_t index = 0;

    for(int i = 0; i <= current; i++) {
        double interval = priorityQueue[i]->getInterval();

        if(highestPriority == interval
            && priorityQueue[index]->getInterval()
                    > interval) {
            highestPriority = interval;
            index = i;
        }
        else if (highestPriority > interval) {
            highestPriority = interval;
            index = i;
        }
    }

    return priorityQueue[index];
}

void PriorityQueue::dequeue() {
    int index = getTopIndex();

    for(int i = index; i < current; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    --current;
}

int PriorityQueue::getTopIndex() {
    int highestPriority = -1;
    std::size_t index = 0;

    for(int i = 0; i <= current; i++) {
        double interval = priorityQueue[i]->getInterval();
        if(highestPriority == interval
           && priorityQueue[index]->getInterval()
              > interval) {
            highestPriority = interval;
            index = i;
        }
        else if (highestPriority > interval) {
            highestPriority = interval;
            index = i;
        }
    }

    return index;
}

bool PriorityQueue::isEmpty() {
    return current < 0;
}

int PriorityQueue::getSize() {
    return current + 1;
}

Event *PriorityQueue::getNextArrival() {
    return nullptr;
}
