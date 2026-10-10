#include "Registration.h"

Registration::Registration()
{
    registrationId = 0;
    eventId = 0;
    participantId = 0;
    status = "Cancelled";
}

Registration::Registration(int regId, int eId, int pId, string s)
{
    registrationId = regId;
    eventId = eId;
    participantId = pId;
    status = s;
}

void Registration::registerParticipant()
{
    status = "Registered";

    cout << "Participant registered successfully!" << endl;
}

void Registration::cancel()
{
    status = "Cancelled";

    cout << "Registration cancelled successfully!" << endl;
}

void Registration::display()
{
    cout << "Registration ID : " << registrationId << endl;
    cout << "Event ID        : " << eventId << endl;
    cout << "Participant ID  : " << participantId << endl;
    cout << "Status          : " << status << endl;
}

int Registration::getRegistrationId()
{
    return registrationId;
}

int Registration::getEventId()
{
    return eventId;
}

int Registration::getParticipantId()
{
    return participantId;
}

string Registration::getStatus()
{
    return status;
}
