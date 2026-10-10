#include "Participant.h"

Participant::Participant()
{
    participantId = 0;
    name = "";
    phone = "";
}

Participant::Participant(int id, string n, string p)
{
    participantId = id;
    name = n;
    phone = p;
}

void Participant::display()
{
    cout << "Participant ID : " << participantId << endl;
    cout << "Name           : " << name << endl;
    cout << "Phone          : " << phone << endl;
}

int Participant::getParticipantId()
{
    return participantId;
}

string Participant::getName()
{
    return name;
}

string Participant::getPhone()
{
    return phone;
}