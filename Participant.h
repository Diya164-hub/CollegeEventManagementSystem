#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Participant : public Person
{
    private:
       int participantId;
       string name;
       string phone;
    
    public:
       Participant();
       Participant(int id, string n, string p);
       
       void display() override;
       
       int getParticipantId();
       string getName();
       string getPhone();
      };

#endif