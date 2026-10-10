#include "EventSystem.h"
#include "Organizer.h"

EventSystem::EventSystem()
{
    eventCount = 0;
    participantCount = 0;
    registrationCount = 0;

    events = new Event[10];
    participants = new Participant[10];
    registrations = new Registration[10];
}

EventSystem::~EventSystem()
{
    delete[] events;
    delete[] participants;
    delete[] registrations;
}

void EventSystem::addEvent()
{
    if (eventCount >= 10)
    {
        cout << "Event limit reached!" << endl;
        return;
    }

    int id;
    string name, date, venue;
    int capacity;

    cout << "Enter Event ID: ";
    cin >> id;

    // Validation 1: Event ID must be positive
    if (id <= 0)
    {
        cout << "Invalid Event ID! ID must be positive." << endl;
        return;
    }

    // Validation 2: Check duplicate Event ID
    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].getEventId() == id)
        {
            cout << "Event ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Event Name: ";
    cin >> name;

    cout << "Enter Event Date: ";
    cin >> date;

    cout << "Enter Event Venue: ";
    cin >> venue;

    cout << "Enter Event Capacity: ";
    cin >> capacity;

    // Validation 3: Capacity must be positive
    if (capacity <= 0)
    {
        cout << "Invalid capacity! Capacity must be greater than 0." << endl;
        return;
    }

    events[eventCount] = Event(id, name, date, venue, capacity);

    eventCount++;

    cout << "Event added successfully!" << endl;
}

void EventSystem::displayEvents()
{
    if (eventCount == 0)
    {
        cout << "No event available!" << endl;
        return;
    }

    cout << "\n==== EVENT RECORDS ====" << endl;

    for (int i = 0; i < eventCount; i++)
    {
        cout << "\nEvent " << i + 1 << ":" << endl;

        events[i].display();
    }
}

void EventSystem::addParticipant()
{
    if (participantCount >= 10)
    {
        cout << "Participant limit reached!" << endl;
        return;
    }

    int id;
    string name, phone;

    cout << "Enter Participant ID: ";
    cin >> id;

    // Validation 1: Participant ID must be positive
    if (id <= 0)
    {
        cout << "Invalid Participant ID! ID must be positive." << endl;
        return;
    }

    // Validation 2: Check duplicate Participant ID
    for (int i = 0; i < participantCount; i++)
    {
        if (participants[i].getParticipantId() == id)
        {
            cout << "Participant ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Participant Name: ";
    cin >> name;

    cout << "Enter Phone Number: ";
    cin >> phone;

    // Validation 3: Phone number must contain exactly 10 digits
    if (phone.length() != 10)
    {
        cout << "Invalid phone number! Phone number must contain 10 digits." << endl;
        return;
    }

    // Check that every character is a digit
    for (char ch : phone)
    {
        if (ch < '0' || ch > '9')
        {
            cout << "Invalid phone number! Only digits are allowed." << endl;
            return;
        }
    }

    participants[participantCount] = Participant(id, name, phone);

    participantCount++;

    cout << "Participant added successfully!" << endl;
}

void EventSystem::displayParticipants()
{
    if (participantCount == 0)
    {
        cout << "No participant available!" << endl;
        return;
    }

    cout << "\n==== PARTICIPANT RECORDS ====" << endl;

    for (int i = 0; i < participantCount; i++)
    {
        cout << "\nParticipant " << i + 1 << ":" << endl;
        participants[i].display();
    }
}

void EventSystem::displayRegistrations()
{
    if (registrationCount == 0)
    {
        cout << "No registrations available!" << endl;
        return;
    }

    cout << "\n==== REGISTRATION RECORDS ====" << endl;

    for (int i = 0; i < registrationCount; i++)
    {
        cout << "\nRegistration " << i + 1 << ":" << endl;
        registrations[i].display();
    }
}

void EventSystem::searchEvent()
{
    if (eventCount == 0)
    {
        cout << "No events available!" << endl;
        return;
    }

    int id;
    bool found = false;

    cout << "Enter Event ID to search: ";
    cin >> id;

    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].getEventId() == id)
        {
            cout << "\nEvent found!" << endl;
            events[i].display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Event not found!" << endl;
    }
}

void EventSystem::updateEvent()
{
    if (eventCount == 0)
    {
        cout << "No events available!" << endl;
        return;
    }

    int id;
    bool found = false;

    cout << "Enter Event ID to update: ";
    cin >> id;

    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].getEventId() == id)
        {
            cout << "\nEvent found. Enter new details:\n";

            events[i].update();

            cout << "Event updated successfully!" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Event not found!" << endl;
    }
}

void EventSystem::deleteEvent()
{
    if (eventCount == 0)
    {
        cout << "No events available!" << endl;
        return;
    }

    int id;
    bool found = false;

    cout << "Event Event ID to delete: ";
    cin >> id;

    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].getEventId() == id)
        {
            for (int j = i; j < eventCount - 1; j++)
            {
                events[j] = events[j + 1];
            }

            eventCount--;

            cout << "Event deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Event not found!" << endl;
    }
}

void EventSystem::registerParticipant()
{
    if (registrationCount >= 10)
    {
        cout << "Registration limit reached!" << endl;
        return;
    }

    if (eventCount == 0)
    {
        cout << "No events available!" << endl;
        return;
    }

    if (participantCount == 0)
    {
        cout << "No participants available!" << endl;
        return;
    }

    int registrationId;
    int eventId;
    int participantId;

    cout << "Enter Registration ID: ";
    cin >> registrationId;

    cout << "Enter Event ID: ";
    cin >> eventId;

    cout << "Enter Participant ID: ";
    cin >> participantId;

    bool eventFound = false;
    bool participantFound = false;

    // Search Event
    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].getEventId() == eventId)
        {
            eventFound = true;
            break;
        }
    }

    // Search Participant
    for (int i = 0; i < participantCount; i++)
    {
        if (participants[i].getParticipantId() == participantId)
        {
            participantFound = true;
            break;
        }
    }

    if (!eventFound)
    {
        cout << "Event not found!" << endl;
        return;
    }

    if (!participantFound)
    {
        cout << "Participant not found!" << endl;
        return;
    }
    registrations[registrationCount] =
        Registration(registrationId, eventId, participantId, "Registered");

    registrations[registrationCount].registerParticipant();

    registrationCount++;
}

void EventSystem::cancelRegistration()
{
    if (registrationCount == 0)
    {
        cout << "No registrations available!" << endl;
        return;
    }

    int registrationId;
    bool found = false;

    cout << "Enter Registration ID to cancel: ";
    cin >> registrationId;

    for (int i = 0; i < registrationCount; i++)
    {
        if (registrations[i].getRegistrationId() == registrationId)
        {
            registrations[i].cancel();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Registration not found!" << endl;
    }
}

void EventSystem::generateReport()
{
    cout << "\n========== EVENT MANAGEMENT REPORT ==========" << endl;

    cout << "\nTotal Events        : " << eventCount << endl;
    cout << "Total Participants  : " << participantCount << endl;
    cout << "Total Registrations : " << registrationCount << endl;

    cout << "\n----- Event Details -----" << endl;

    if (eventCount == 0)
    {
        cout << "No events available!" << endl;
    }
    else
    {
        for (int i = 0; i < eventCount; i++)
        {
            cout << "\nEvent " << i + 1 << ":" << endl;
            events[i].display();
        }
    }

    cout << "\n----- Participant Details -----" << endl;

    if (participantCount == 0)
    {
        cout << "No participants available!" << endl;
    }
    else
    {
        for (int i = 0; i < participantCount; i++)
        {
            cout << "\nParticipant " << i + 1 << ":" << endl;
            participants[i].display();
        }
    }

    cout << "\n----- Registration Details -----" << endl;

    if (registrationCount == 0)
    {
        cout << "No registrations available!" << endl;
    }
    else
    {
        for (int i = 0; i < registrationCount; i++)
        {
            cout << "\nRegistration " << i + 1 << ":" << endl;
            registrations[i].display();
        }
    }

    cout << "\n============================================" << endl;
}

void EventSystem::saveData()
{
    fileManager.saveEvents(events, eventCount);
    fileManager.saveParticipants(participants, participantCount);
    fileManager.saveRegistrations(registrations, registrationCount);

    cout << "All data saved successfully!" << endl;
}

void EventSystem::loadData()
{
    fileManager.loadEvents(events, eventCount);
    fileManager.loadParticipants(participants, participantCount);
    fileManager.loadRegistrations(registrations, registrationCount);

    cout << "All data loaded successfully!" << endl;
}

void EventSystem::demonstratePolymorphism()
{
    Person *person;

    Participant participant(101, "Rahul", "9876543210");
    Organizer organizer(201, "Amit", "Computer");

    cout << "\n===== RUNTIME POLYMORPHISM DEMONSTRATION =====" << endl;

    person = &participant;

    cout << "\nPerson pointer pointing to Participant object:" << endl;
    person->display();

    person = &organizer;

    cout << "\nPerson pointer pointing to Organizer object:" << endl;
    person->display();
}