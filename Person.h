#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
    public:
        virtual void display() = 0;
        virtual ~Person();
};

#endif