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

class FIFO_Queue {
private:
    Event ** queue;
public:
    void insertBack(Event* event);
    void deleteFront();
    Event *getEvent();
};


#endif //COP4534_P2_FIFO_QUEUE_HPP
