#include "FileManager.h"

FileManager::FileManager()
{
    eventFile = "Data/events.txt";
    participantFile = "Data/participants.txt";
    registrationFile = "Data/registrations.txt";
}

void FileManager::saveEvents(Event *events, int eventCount)
{
    ofstream file(eventFile);

    if (!file)
    {
        cout << "Unable to open event file!" << endl;
        return;
    }

    for (int i = 0; i < eventCount; i++)
    {
        file << events[i].getEventId() << "|"
             << events[i].getName() << "|"
             << events[i].getDate() << "|"
             << events[i].getVenue() << "|"
             << events[i].getCapacity() << endl;
    }

    file.close();

    cout << "Events saved successfully!" << endl;
}

void FileManager::saveParticipants(Participant *participants, int participantCount)
{
    ofstream file(participantFile);

    if (!file)
    {
        cout << "Unable to open participant file!" << endl;
        return;
    }

    for (int i = 0; i < participantCount; i++)
    {
        file << participants[i].getParticipantId() << "|"
             << participants[i].getName() << "|"
             << participants[i].getPhone() << endl;
    }

    file.close();

    cout << "Participants saved successfully!" << endl;
}

void FileManager::saveRegistrations(Registration *registrations, int registrationCount)
{
    ofstream file(registrationFile);

    if (!file)
    {
        cout << "Unable to open registration file!" << endl;
        return;
    }

    for (int i = 0; i < registrationCount; i++)
    {
        file << registrations[i].getRegistrationId() << "|"
             << registrations[i].getEventId() << "|"
             << registrations[i].getParticipantId() << "|"
             << registrations[i].getStatus() << endl;
    }

    file.close();

    cout << "Registrations saved successfully!" << endl;
}

void FileManager::loadEvents(Event *events, int &eventCount)
{
    ifstream file(eventFile);

    if (!file)
    {
        cout << "No event file found. Starting with empty events." << endl;
        return;
    }

    eventCount = 0;

    string line;

    while (getline(file, line) && eventCount < 10)
    {
        if (line.empty())
        {
            continue;
        }

        string idText;
        string name;
        string date;
        string venue;
        string capacityText;

        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        size_t pos4 = line.find('|', pos3 + 1);

        if (pos1 == string::npos ||
            pos2 == string::npos ||
            pos3 == string::npos ||
            pos4 == string::npos)
        {
            continue;
        }

        idText = line.substr(0, pos1);
        name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        date = line.substr(pos2 + 1, pos3 - pos2 - 1);
        venue = line.substr(pos3 + 1, pos4 - pos3 - 1);
        capacityText = line.substr(pos4 + 1);

        int id = stoi(idText);
        int capacity = stoi(capacityText);

        events[eventCount] = Event(id, name, date, venue, capacity);

        eventCount++;
    }

    file.close();

    cout << "Events loaded successfully!" << endl;
}

void FileManager::loadParticipants(Participant *participants, int &participantCount)
{
    ifstream file(participantFile);

    if (!file)
    {
        cout << "No participant file found. Starting with empty participants." << endl;
        return;
    }

    participantCount = 0;

    string line;

    while (getline(file, line) && participantCount < 10)
    {
        if (line.empty())
        {
            continue;
        }

        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos)
        {
            continue;
        }

        string idText = line.substr(0, pos1);
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string phone = line.substr(pos2 + 1);

        int id = stoi(idText);

        participants[participantCount] =
            Participant(id, name, phone);

        participantCount++;
    }

    file.close();

    cout << "Participants loaded successfully!" << endl;
}

void FileManager::loadRegistrations(
    Registration *registrations,
    int &registrationCount)
{
    ifstream file(registrationFile);

    if (!file)
    {
        cout << "No registration file found. Starting with empty registrations." << endl;
        return;
    }

    registrationCount = 0;

    string line;

    while (getline(file, line) && registrationCount < 10)
    {
        if (line.empty())
        {
            continue;
        }

        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        if (pos1 == string::npos ||
            pos2 == string::npos ||
            pos3 == string::npos)
        {
            continue;
        }

        string regIdText = line.substr(0, pos1);

        string eventIdText =
            line.substr(pos1 + 1, pos2 - pos1 - 1);

        string participantIdText =
            line.substr(pos2 + 1, pos3 - pos2 - 1);

        string status =
            line.substr(pos3 + 1);

        int registrationId = stoi(regIdText);
        int eventId = stoi(eventIdText);
        int participantId = stoi(participantIdText);

        registrations[registrationCount] =
            Registration(
                registrationId,
                eventId,
                participantId,
                status);

        registrationCount++;
    }

    file.close();

    cout << "Registrations loaded successfully!" << endl;
}