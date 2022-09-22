/***************************************************************
  Student Name: Collin Lowing
  File Name: Event.hpp
  Project 2

  Stores information for event handling.
  Arrival or Departure, Priority, Completion Time
***************************************************************/

#ifndef COP4534_P2_EVENT_HPP
#define COP4534_P2_EVENT_HPP



class Event {
private:
    int type = ARRIVAL;
    int priority = 0;
    double processTime = 0;
public:
    enum types{ARRIVAL, DEPARTURE};

    Event(int type, int priority, int processTime);

    int getType() const;

    void setType(int type);

    int getPriority() const;

    void setPriority(int priority);

    double getProcessTime() const;

    void setProcessTime(double processTime);
};


#endif //COP4534_P2_EVENT_HPP
