#ifndef UNIVER_HPP
#define UNIVER_HPP

#include <list>

#include "lecturer.hpp"
#include "student.hpp"
#include "hod.hpp"

class Univer
{
public:
    Univer();
    ~Univer();

    void AddPerson(Person *a);

    void ShowInfo() const;
    void Filter() const;
private:
    std::list<Person*> shtat;
};

#endif // UNIVER_HPP
