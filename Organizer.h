#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Organizer : public Person
{
    private:
       int organizerId;
       string name;
       string department;

    public:
       Organizer();
       Organizer(int id, string n, string d);

       void display() override;
};

#endif