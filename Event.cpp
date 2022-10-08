/***************************************************************
  Student Name: Collin Lowing
  File Name: Event.cpp
  Project 2

  Stores information for event handling.
  Arrival or Departure, and time intervals for the lifetime of event
***************************************************************/

#include <iostream>
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

int Event::getType() {
    std::cout << type << std::endl;
    return type;
}

void Event::setType(int type) {
    this->type = type;
}

double Event::getServiceTimeStart() {
    return serviceTimeStart;
}

void Event::setServiceTimeStart(double serviceTimeStart) {
    this->serviceTimeStart = serviceTimeStart;
}

double Event::getArrivalTime() {
    return arrivalTime;
}

void Event::setArrivalTime(double arrivalTime) {
    this->arrivalTime = arrivalTime;
}

double Event::getDepartureTime() {
    return departureTime;
}

void Event::setDepartureTime(double departureTime) {
    this->departureTime = departureTime;
}

double Event::getInterval() {
    double interval;
    if(type == Event::ARRIVAL) {
        interval = arrivalTime;
    }
    else {
        interval = departureTime;
    }

    return interval;
}
