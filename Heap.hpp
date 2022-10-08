//
// Created by cel on 10/6/22.
//

#ifndef COP4534_P2_HEAP_HPP
#define COP4534_P2_HEAP_HPP


#include "Event.hpp"

class Heap {
private:
    int maxSize;
    int size = 0;
    Event** heap;
public:
    Heap(int maxSize);
    bool isEmpty();
    Event* getMin();
    void insert(Event* event);
    Event* popMin();
    void clear();
    void constructHeap(Event** array, int initializeSize);
    void buildHeap();
    void percolateDown(int index);
    int getSize();
    ~Heap();
};


#endif //COP4534_P2_HEAP_HPP
