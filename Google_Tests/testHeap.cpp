//
// Created by cel on 10/9/22.
//

#include "gtest/gtest.h"
#include "../Heap.hpp"

TEST(HeapTests, getInterval) {
    Heap * heap = new Heap(200);
    Event* newEvent = new Event(Event::ARRIVAL, 0.1232434);
    heap->insert(newEvent);
    double expectedInterval = 0.1232434;
    Event* testEvent = heap->getMin();
    EXPECT_EQ(testEvent->getInterval(), expectedInterval);
}

TEST(HeapTests, getType) {
    Heap * heap = new Heap(200);
    Event* event1 = new Event(Event::ARRIVAL, 0.1232434);
    Event* event2 = new Event(Event::DEPARTURE, 0.9877555);
    heap->insert(event1);
    heap->insert(event2);
    int expectedType1 = Event::ARRIVAL;
    int expectedType2 = Event::DEPARTURE;
    Event* testEvent = heap->popMin();
    EXPECT_EQ(testEvent->getType(), expectedType1);
    testEvent = heap->getMin();
    EXPECT_EQ(testEvent->getType(), expectedType2);
}