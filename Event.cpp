#include "Event.h"

Event::Event()
{
    eventID = 0;
    name = "";
    date = "";
    venue = "";
    capacity = 0;
}

Event::Event(int id, string n, string d, string v, int c)
{
    eventID = id;
    name = n;
    date = d;
    venue = v;
    capacity = c;
}

void Event::display()
{
    cout << "Event ID : " << eventID << endl;
    cout << "Name     : " << name << endl;
    cout << "Date     : " << date << endl;
    cout << "Venue    : " << venue << endl;
    cout << "Capacity : " << capacity << endl;
}

void Event::update()
{
    cout << "Enter new event name: ";
    cin >> name;

    cout << "Enter new date: ";
    cin >> date;

    cout << "Eventnew venue: ";
    cin >> venue;

    cout << "Event new capacity: ";
    cin >> capacity;
}

int Event::getEventId()
{
    return eventID;
}

string Event::getName()
{
    return name;
}

string Event::getDate()
{
    return date;
}

string Event::getVenue()
{
    return venue;
}

int Event::getCapacity()
{
    return capacity;
}