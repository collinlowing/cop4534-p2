/***************************************************************
  Student Name: Collin Lowing
  File Name: Heap.hpp
  Project 2

  Store events and sort by smallest time interval for simulation use
***************************************************************/

#ifndef COP4534_P2_HEAP_HPP
#define COP4534_P2_HEAP_HPP


#include "Event.hpp"
#include "iostream"

class Heap {
private:
    int maxSize;
    int size = 0;
    Event **heap;
public:
    explicit Heap(int maxSize);

    bool isEmpty();

    Event *getMin();

    void insert(Event *event);

    Event *popMin();

    void clear();

    int getSize();

    void swap(Event *a, Event *b);

    int parent(int index) { return (index - 1) / 2; }

    int left(int index) { return (2 * index + 1); } // to get index of left child

    int right(int index) { return (2 * index + 2); } // to get index of right child

    void heapify(int index);

    ~Heap();
};


#endif //COP4534_P2_HEAP_HPP
