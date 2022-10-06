/***************************************************************
  Student Name: Collin Lowing
  File Name: Event.hpp
  Project 2

  Stores information for event handling.
  Arrival or Departure, and time intervals for the lifetime of event
***************************************************************/

#ifndef COP4534_P2_EVENT_HPP
#define COP4534_P2_EVENT_HPP



class Event {
private:
    int type;
    double serviceTimeStart = 0;
    double arrivalTime = 0;
    double departureTime = 0;
public:
    enum types{ARRIVAL, DEPARTURE};

    Event(int type, double interval);

    int getType() const;

    void setType(int type);

    double getServiceTimeStart() const;

    void setServiceTimeStart(double serviceTimeStart);

    double getArrivalTime() const;

    void setArrivalTime(double arrivalTime);

    double getDepartureTime() const;

    void setDepartureTime(double departureTime);
};


#endif //COP4534_P2_EVENT_HPP
