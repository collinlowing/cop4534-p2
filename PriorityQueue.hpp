/***************************************************************
  Student Name: Collin Lowing
  File Name: PriorityQueue.hpp
  Project 2

  Stores new arrivals and departures in a priority ordered list.
  First In, Highest Priority Out
***************************************************************/

#ifndef COP4534_P2_PRIORITYQUEUE_HPP
#define COP4534_P2_PRIORITYQUEUE_HPP

#include "Event.hpp"
#include <cstdio>

class PriorityQueue {
private:
    int MAX_SIZE;
    Event **priorityQueue;
    int current = -1; // empty by default
    int numOfArrivals = 0;
public:
    explicit PriorityQueue(int MAX_SIZE);

    void enqueue(int type, double interval);

    void enqueue(Event *newEvent);

    Event *getTopEvent();

    Event *getNextArrival();

    void dequeue();

    int getTopIndex();

    bool isEmpty();

    int getSize();
};


#endif //COP4534_P2_PRIORITYQUEUE_HPP
