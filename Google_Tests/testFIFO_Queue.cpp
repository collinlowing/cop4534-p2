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
    int expectedPriority = 1;
    int expectedProcessTime = 2;
    Event * event = new Event(Event::ARRIVAL,1,2);

    fifoQueue.insertBack(event);

    Event * testEvent = fifoQueue.getEvent();

    ASSERT_FALSE(testEvent == nullptr);
    EXPECT_EQ(testEvent->getPriority(), expectedPriority);
    EXPECT_EQ(testEvent->getProcessTime(), expectedProcessTime);
}

TEST(FIFOQueueTests, deleteEvent) {
    FIFO_Queue fifoQueue;
    int priority1 = 1;
    int processTime1 = 2;
    int priority2 = 3;
    int processTime2 = 4;
    Event * event1 = new Event(Event::ARRIVAL,1,2);
    Event * event2 = new Event(Event::DEPARTURE, 3, 4);

    fifoQueue.insertBack(event1);
    fifoQueue.insertBack(event2);

    Event * testEvent = fifoQueue.getEvent();

    ASSERT_FALSE(testEvent == nullptr);
    EXPECT_EQ(testEvent->getPriority(), priority1);
    EXPECT_EQ(testEvent->getProcessTime(), processTime1);

    fifoQueue.deleteFront();

    testEvent = fifoQueue.getEvent();

    ASSERT_FALSE(testEvent == nullptr);
    EXPECT_EQ(testEvent->getPriority(), priority2);
    EXPECT_EQ(testEvent->getProcessTime(), processTime2);
}