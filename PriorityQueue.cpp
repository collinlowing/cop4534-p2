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

void PriorityQueue::enqueue(int type, int priority, int processTime) {
    // increase the allocated current size
    current++;

    // insert the new event
    priorityQueue[current] = new Event(type, priority, processTime);
}

Event *PriorityQueue::getTopEvent() {
    int highestPriority = -1;
    std::size_t index = 0;

    for(int i = 0; i <= current; i++) {
        if(highestPriority == priorityQueue[i]->getPriority()
            && index >= 0
            && priorityQueue[index]->getProcessTime()
                    < priorityQueue[i]->getProcessTime()) {
            highestPriority = priorityQueue[i]->getPriority();
            index = i;
        }
        else if (highestPriority < priorityQueue[i]->getPriority()) {
            highestPriority = priorityQueue[i]->getPriority();
            index = i;
        }
    }

    return priorityQueue[index];
}

void PriorityQueue::dequeue() {

}
