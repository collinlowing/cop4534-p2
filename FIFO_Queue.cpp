/***************************************************************
  Student Name: Collin Lowing
  File Name: FIFO_Queue.cpp
  Project 2

  Stores new arrivals and departures when all servers (M) are full.
  First In, First Out
***************************************************************/

#include "FIFO_Queue.hpp"

FIFO_Queue::FIFO_Queue() {
    queueSize = 0;
}

void FIFO_Queue::insertBack(Event *event) {
    queue.push_back(event);
    queueSize++;
}

void FIFO_Queue::deleteFront() {
    queue.erase(queue.begin());
}

Event *FIFO_Queue::getFront() {
    return queue.front();
}

int FIFO_Queue::size() {
    return queueSize;
}


