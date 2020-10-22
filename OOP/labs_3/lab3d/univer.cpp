#include "univer.hpp"

#include <cstring>
#include <iostream>

Univer::Univer()
{

}

Univer::~Univer()
{
    for(Person *a : shtat)
        delete a;
    shtat.clear();
}

void Univer::AddPerson(Person *a)
{
    shtat.push_back(a);
}

void Univer::ShowInfo() const
{
    std::cout << "University info:\n";
    for(Person *p : shtat)
    {
        std::cout << p->info() << std::endl;
        std::cout << "\tWHO: " << p->who() << ", ASK: " << p->ask() << std::endl;
    }
}

void Univer::Filter() const
{
    std::cout << "Должники:\n";
    for(Person *p : shtat)
    {
        if(p->who() != 3) // student
            continue;
        if(p->ask() > 0) // more than 0 debt
            std::cout << "\t" << p->info() << std::endl;
    }
    std::cout << "Молодые преподователи:\n";
    for(Person *p : shtat)
    {
        if(p->who() != 1)
            continue;
        Lecturer *cp = (Lecturer*)p;
        if(cp->GetAge() < 50)
            std::cout << "\t" << p->info() << std::endl;
    }
}
