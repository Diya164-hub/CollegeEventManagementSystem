#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <string>

using namespace std;

class Registration
{
    private:
         int registrationId;
         int eventId;
         int participantId;
         string status;

    public:
         Registration();
         Registration(int regId, int eID, int pId, string s);

         void registerParticipant();
         void cancel();
         void display();

         int getRegistrationId();
         int getEventId();
         int getParticipantId();
         string getStatus();
};

#endif