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