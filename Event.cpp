/***************************************************************
  Student Name: Collin Lowing
  File Name: Event.cpp
  Project 2

  Stores information for event handling.
  Arrival or Departure, and time intervals for the lifetime of event
***************************************************************/

#include "Event.hpp"

Event::Event(int type, double interval) {
    this->type = type;
    if(type == Event::ARRIVAL) {
        this->arrivalTime = interval;
    }
    else {
        this->departureTime = interval;
    }
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

double Event::getArrivalTime() const {
    return arrivalTime;
}

void Event::setArrivalTime(double arrivalTime) {
    this->arrivalTime = arrivalTime;
}

double Event::getDepartureTime() const {
    return departureTime;
}

void Event::setDepartureTime(double departureTime) {
    this->departureTime = departureTime;
}