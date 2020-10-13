#ifndef LECTURER_H
#define LECTURER_H

#include "person.hpp"

class Lecturer : public Person
{
public:
    Lecturer(const std::string &_fio, char _age, const std::string &sub, int _g);

private:
    std::string subject;
    int grade;
};

#endif // LECTURER_H
