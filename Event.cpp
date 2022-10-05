/***************************************************************
  Student Name: Collin Lowing
  File Name: Event.cpp
  Project 2

  Stores information for event handling.
  Arrival or Departure, Priority, Process Time
***************************************************************/

#include "Event.hpp"

Event::Event(int type, double processTime) {
    this->type = type;
    this->processTime = processTime;
}

int Event::getType() const {
    return type;
}

void Event::setType(int type) {
    this->type = type;
}

double Event::getProcessTime() const {
    return processTime;
}

void Event::setProcessTime(double processTime) {
    this->processTime = processTime;
}

double Event::getServiceTimeStart() const {
    return serviceTimeStart;
}

void Event::setServiceTimeStart(double serviceTimeStart) {
    this->serviceTimeStart = serviceTimeStart;
}



