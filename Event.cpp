/***************************************************************
  Student Name: Collin Lowing
  File Name: Event.cpp
  Project 2

  Stores information for event handling.
  Arrival or Departure, Priority, Process Time
***************************************************************/

#include "Event.hpp"

Event::Event(int type, int priority, int processTime) {
    this->type = type;
    this->priority = priority;
    this->processTime = processTime;
}

int Event::getType() const {
    return type;
}

void Event::setType(int type) {
    this->type = type;
}

int Event::getPriority() const {
    return priority;
}

void Event::setPriority(int priority) {
    this->priority = priority;
}

double Event::getProcessTime() const {
    return processTime;
}

void Event::setProcessTime(double processTime) {
    this->processTime = processTime;
}


