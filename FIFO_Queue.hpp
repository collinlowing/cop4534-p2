/***************************************************************
  Student Name: Collin Lowing
  File Name: FIFO_Queue.hpp
  Project 2

  Stores new arrivals and departures when all servers (M) are full.
  First In, First Out
***************************************************************/

#ifndef COP4534_P2_FIFO_QUEUE_HPP
#define COP4534_P2_FIFO_QUEUE_HPP

#include "Event.hpp"
#include <vector>

class FIFO_Queue {
private:
    std::vector<Event*> queue;
    Event * back;
    int queueSize;
public:
    FIFO_Queue();
    void insertBack(Event* event);
    void deleteFront();
    Event *getFront();
    int size();
};


#endif //COP4534_P2_FIFO_QUEUE_HPP
