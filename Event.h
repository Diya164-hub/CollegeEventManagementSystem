#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
    int eventID;
    string name;
    string date;
    string venue;
    int capacity;

public:
    Event();
    Event(int id, string n, string d, string v, int c);

    void display();
    void update();
    int getEventId();

    string getName();
    string getDate();
    string getVenue();
    int getCapacity();
};

#endif