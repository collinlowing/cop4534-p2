/***************************************************************
  Student Name: Collin Lowing
  File Name: testPriorityQueue.cpp
  Project 2

  tests PriorityQueue operations
***************************************************************/

#include "gtest/gtest.h"
#include "../PriorityQueue.hpp"

TEST(PriorityQueueTests, enqueue) {
    PriorityQueue pr(200);
    double expectedProcessTime = 2.1214;

    pr.enqueue(Event::ARRIVAL, 2.1214);

    Event* event = pr.getTopEvent();

    ASSERT_FALSE(event == nullptr);

    EXPECT_EQ(event->getType(), Event::ARRIVAL);
    EXPECT_EQ(event->getProcessTime(), expectedProcessTime);
}

TEST(PriorityQueueTests, dequeue) {
    PriorityQueue pr(200);
    double highestPriority = 1.11234;
    double lowestPriority = 3.5657;

    pr.enqueue(Event::ARRIVAL, highestPriority);
    pr.enqueue(Event::DEPARTURE, lowestPriority);

    Event* event = pr.getTopEvent();

    ASSERT_FALSE(event == nullptr);

    EXPECT_EQ(event->getType(), Event::ARRIVAL);
    EXPECT_EQ(event->getProcessTime(), highestPriority);

    pr.dequeue();
    Event* nextEvent = pr.getTopEvent();

    ASSERT_FALSE(nextEvent == nullptr);

    EXPECT_EQ(nextEvent->getType(), Event::DEPARTURE);
    EXPECT_EQ(nextEvent->getProcessTime(), lowestPriority);
}