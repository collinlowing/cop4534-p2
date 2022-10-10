/***************************************************************
  Student Name: Collin Lowing
  File Name: Heap.cpp
  Project 2

  Store events and sort by smallest time interval for simulation use
***************************************************************/


#include "Heap.hpp"

Heap::Heap(int maxSize) {
    this->maxSize = maxSize + 1;
    heap = new Event *[this->maxSize]();
    for (int i = 0; i < this->maxSize; i++) {
        heap[i] = nullptr;
    }
}

bool Heap::isEmpty() {
    return size <= 0;
}

// get top item in heap without deletion
Event *Heap::getMin() {
    return heap[0];
}

// add a new item into heap
void Heap::insert(Event *event) {
    if (size >= maxSize) {
        std::cout << "Heap is full, could not insert new event" << std::endl;
        return;
    }

    size++;
    int i = size - 1;
    heap[i] = event;

    while (i > 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// get and remove top item in heap
Event *Heap::popMin() {
    if (size <= 0) {
        return nullptr;
    }
    if (size == 1) {
        size--;
        return heap[0];
    }

    Event *rootNode = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);

    return rootNode;
}

// delete all items in heap
void Heap::clear() {
    for (int i = 0; i < maxSize; i++) {
        delete (heap[i]);
    }
    delete[] heap;
    size = 0;
}

Heap::~Heap() {
    clear();
}


int Heap::getSize() {
    return size;
}

void Heap::swap(Event *a, Event *b) {
    Event temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain min heap
void Heap::heapify(int index) {
    int left = Heap::left(index);
    int right = Heap::right(index);
    int smallest = index;

    if (left < size && heap[left] < heap[index]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify(smallest);
    }
}
