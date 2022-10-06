/***************************************************************
  Student Name: Collin Lowing
  File Name: testFIFO_Queue.cpp
  Project 2

  tests FIFO_Queue operations
***************************************************************/

#include "gtest/gtest.h"
#include "../FIFO_Queue.hpp"

TEST(FIFOQueueTests, insertEvent) {
    FIFO_Queue fifoQueue;
    int expectedInterval = 2;
    Event * event = new Event(Event::ARRIVAL,2);

    fifoQueue.insertBack(event);

    Event * testEvent = fifoQueue.getFront();

    ASSERT_FALSE(testEvent == nullptr);
    EXPECT_EQ(testEvent->getInterval(), expectedInterval);
}

TEST(FIFOQueueTests, deleteEvent) {
    FIFO_Queue fifoQueue;
    int timeInterval1 = 2;
    int timeInterval2 = 4;
    Event * event1 = new Event(Event::ARRIVAL,2);
    Event * event2 = new Event(Event::DEPARTURE,4);

    fifoQueue.insertBack(event1);
    fifoQueue.insertBack(event2);

    Event * testEvent = fifoQueue.getFront();

    ASSERT_FALSE(testEvent == nullptr);
    EXPECT_EQ(testEvent->getInterval(), timeInterval1);

    fifoQueue.deleteFront();

    testEvent = fifoQueue.getFront();

    ASSERT_FALSE(testEvent == nullptr);
    EXPECT_EQ(testEvent->getInterval(), timeInterval2);
}