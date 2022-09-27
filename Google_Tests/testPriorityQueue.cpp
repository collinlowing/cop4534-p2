/***************************************************************
  Student Name: Collin Lowing
  File Name: testPriorityQueue.cpp
  Project 2

  tests PriorityQueue operations
***************************************************************/

#include "gtest/gtest.h"
#include "../PriorityQueue.hpp"

TEST(PriorityQueueTests, enqueue) {
    PriorityQueue pr(10);
    int expectedPriority = 1;
    int expectedProcessTime = 2;

    pr.enqueue(Event::ARRIVAL, 1, 2);

    Event* event = pr.getTopEvent();

    ASSERT_FALSE(event == nullptr);

    EXPECT_EQ(event->getType(), Event::ARRIVAL);
    EXPECT_EQ(event->getPriority(), expectedPriority);
    EXPECT_EQ(event->getProcessTime(), expectedProcessTime);
}

TEST(PriorityQueueTests, dequeue) {
    PriorityQueue pr(10);
    int highestPriority = 5;
    int expectedHighestPriorityProcessTime = 2;
    int lowestPriority = 3;
    int expectedLowestPriorityProcessTime = 6;

    pr.enqueue(Event::ARRIVAL, highestPriority, expectedHighestPriorityProcessTime);
    pr.enqueue(Event::DEPARTURE, lowestPriority, expectedLowestPriorityProcessTime);

    Event* event = pr.getTopEvent();

    ASSERT_FALSE(event == nullptr);

    EXPECT_EQ(event->getType(), Event::ARRIVAL);
    EXPECT_EQ(event->getPriority(), highestPriority);
    EXPECT_EQ(event->getProcessTime(), expectedHighestPriorityProcessTime);

    pr.dequeue();
    Event* nextEvent = pr.getTopEvent();

    ASSERT_FALSE(nextEvent == nullptr);

    EXPECT_EQ(nextEvent->getType(), Event::DEPARTURE);
    EXPECT_EQ(nextEvent->getPriority(), lowestPriority);
    EXPECT_EQ(nextEvent->getProcessTime(), expectedLowestPriorityProcessTime);
}