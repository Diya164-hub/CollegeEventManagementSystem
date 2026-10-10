#include "Organizer.h"

Organizer::Organizer()
{
    organizerId = 0;
    name = "";
    department = "";
}

Organizer::Organizer(int id, string n, string d)
{
    organizerId = id;
    name = n;
    department = d;
}

void Organizer::display()
{
    cout << "Organizer ID : " << organizerId << endl;
    cout << "Name         : " << name << endl;
    cout << "Department   : " << department << endl;
}