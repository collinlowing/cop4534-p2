//
// Created by cel on 10/6/22.
//

#include "Heap.hpp"

Heap::Heap(int maxSize) {
    this->maxSize = maxSize + 1;
}

bool Heap::isEmpty() {
    return size < 0;
}

Event *Heap::getMin() {
    return heap[1];
}

void Heap::insert(Event *event) {
    heap[0] = event;
    int index = size++;
    while(event->getInterval() < heap[index / 2]->getInterval()) {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = event;
}

Event *Heap::popMin() {
    Event* temp = getMin();
    heap[1] = heap[size--];
    percolateDown(1);
    return temp;
}

void Heap::clear() {
    for(int i = 0; i < maxSize; i++) {
        delete(heap[i]);
    }
    delete [] heap;
    size = 0;
}

void Heap::constructHeap(Event** array, int initializeSize) {
    int i;
    for(i = 0; i < initializeSize; i++) {
        heap[i + 1] = array[i];
    }
    buildHeap();
}

void Heap::buildHeap() {
    for(int i = size / 2; i > 0; i--) {
        percolateDown(i);
    }
}

void Heap::percolateDown(int index) {
    int childIndex;
    Event* temp = heap[index];

    while(index * 2 <= size) {
        childIndex = index * 2;
        if(childIndex != size
            && heap[childIndex + 1]->getInterval() < heap[childIndex]->getInterval()) {
                childIndex++;
        }
        if(heap[childIndex]->getInterval() < temp->getInterval()) {
            heap[index] = heap[childIndex];
        }
        else {
            break;
        }
        index = childIndex;
    }
    heap[index] = temp;
}

Heap::~Heap() {
    clear();
}

int Heap::getSize() {
    return size;
}
