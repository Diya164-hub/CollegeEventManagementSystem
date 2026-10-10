#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <iostream>
#include "FileManager.h"
#include "Event.h"
#include "Participant.h"
#include "Registration.h"

using namespace std;

class EventSystem
{
private:
    Event *events;
    Participant *participants;
    Registration *registrations;

    int eventCount;
    int participantCount;
    int registrationCount;

    FileManager fileManager;

public:
    EventSystem();

    void addEvent();
    void addParticipant();

    void displayEvents();
    void displayParticipants();
    void displayRegistrations();

    void searchEvent();
    void updateEvent();
    void deleteEvent();

    void registerParticipant();
    void cancelRegistration();

    void generateReport();
    void demonstratePolymorphism();

    void saveData();
    void loadData();

    ~EventSystem();
};

#endif