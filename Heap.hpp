//
// Created by cel on 10/6/22.
//

#ifndef COP4534_P2_HEAP_HPP
#define COP4534_P2_HEAP_HPP


#include "Event.hpp"
#include "iostream"

class Heap {
private:
    int maxSize;
    int size = 0;
    Event** heap;
public:
    explicit Heap(int maxSize);
    bool isEmpty();
    Event* getMin();
    void insert(Event* event);
    Event* popMin();
    void clear();
    void constructHeap(Event** array, int initializeSize);
    void buildHeap();
    void percolateDown(int index);
    int getSize();

    //~Heap();
    void swap(Event *x, Event *y);
    int parent(int i) { return (i-1)/2; }
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
    void heapify(int index);

};


#endif //COP4534_P2_HEAP_HPP
