#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "Event.h"
#include "Participant.h"
#include "Registration.h"

using namespace std;

class FileManager
{
private:
    string eventFile;
    string participantFile;
    string registrationFile;

public:
    FileManager();

    void saveEvents(Event *events, int eventCount);
    void saveParticipants(Participant *participants, int participantCount);
    void saveRegistrations(Registration *registrations, int registrationCount);

    void loadEvents(Event *events, int &eventCount);
    void loadParticipants(Participant *participants, int &participantCount);
    void loadRegistrations(Registration *registrations, int &registrationCount);
};

#endif
