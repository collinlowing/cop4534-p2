//
// Created by cel on 10/9/22.
//

#include "gtest/gtest.h"
#include "../Heap.hpp"
#include "../Simulation.hpp"
#include "../AnalyticalModel.hpp"

TEST(HeapTests, getInterval) {
    Heap * heap = new Heap(200);
    Event* newEvent = new Event(Event::ARRIVAL, 0.1232434);
    heap->insert(newEvent);
    double expectedInterval = 0.1232434;
    Event* testEvent = heap->getMin();
    EXPECT_EQ(testEvent->getInterval(), expectedInterval);
}

TEST(HeapTests, swap) {
    Heap * heap = new Heap(200);
    Event* event1 = new Event(Event::ARRIVAL, 0.111);
    Event* event2 = new Event(Event::ARRIVAL, 0.222);
    heap->swap(event1, event2);
    EXPECT_TRUE(AnalyticalModel::isDoubleEqual(event1->getInterval(), 0.222));
    EXPECT_TRUE(AnalyticalModel::isDoubleEqual(event2->getInterval(), 0.111));
}

TEST(HeapTests, getType) {
    Heap * heap = new Heap(200);
    Event* event1 = new Event(Event::ARRIVAL, 0.1232434);
    Event* event2 = new Event(Event::DEPARTURE, 0.0100);
    Event* event3 = new Event(Event::ARRIVAL, 0.9877555);
    heap->insert(event1);
    heap->insert(event2);
    heap->insert(event3);
    double expectedInterval1 = 0.1000;
    double expectedInterval2 = 0.1232434;
    Event* testEvent = heap->popMin();
    EXPECT_EQ(testEvent->getInterval(), expectedInterval1);
    testEvent = heap->popMin();
    EXPECT_EQ(testEvent->getInterval(), expectedInterval2);
}

/*
TEST(HeapTest, lotsOfEvents) {
    Heap * heap = new Heap(200);
    for(int i = 0; i < 2000; i++) {
        if(heap->getSize() < 200) {
            double expectedInterval = Simulation::getNextRandomInterval(3);
            Event* newEvent = new Event(Event::ARRIVAL, expectedInterval);
            heap->insert(newEvent);

        }
    }
}*/
