//
// Created by cel on 10/6/22.
//

#include "Heap.hpp"

Heap::Heap(int maxSize) {
    this->maxSize = maxSize + 1;
    heap = new Event * [this->maxSize]();
    for(int i = 0; i < this->maxSize; i++) {
        heap[i] = nullptr;
    }
}

bool Heap::isEmpty() {
    return size <= 0;
}

Event *Heap::getMin() {
    return heap[0];
}

void Heap::insert(Event *event) {
    if(size >= maxSize) {
        std::cout << "Heap is full, could not insert new event" << std::endl;
        return;
    }

    size++;
    int i = size - 1;
    heap[i] = event;

    while(i > 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }

    /*std::cout << size << std::endl;
    int index = size++;
    std::cout << size << std::endl;
    heap[index] = event;
    while(event->getInterval() < heap[index / 2]->getInterval()) {
        std::cout << event->getInterval() << " < " << heap[index / 2]->getInterval() << std::endl;
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = event;*/
}

Event *Heap::popMin() {
    if(size <= 0) {
        return nullptr;
    }
    if(size == 1) {
        size--;
        return heap[0];
    }

    Event* rootNode = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify(0);

    return rootNode;

    /*Event* temp = getMin();
    heap[1] = heap[size--];
    percolateDown(1);
    return temp;*/
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

/*
Heap::~Heap() {
    clear();
}
*/

int Heap::getSize() {
    return size;
}

void Heap::swap(Event *x, Event *y)
{
    Event temp = *x;
    *x = *y;
    *y = temp;
}

void Heap::heapify(int index) {
    int left = Heap::left(index);
    int right = Heap::right(index);
    int smallest = index;

    if(left < size && heap[left] < heap[index]) {
        smallest = left;
    }
    if(right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if(smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify(smallest);
    }
}
