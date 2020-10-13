#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
public:
    Person(const std::string &_fio, char _age);
    virtual ~Person();

    virtual const std::string &info() = 0;
    virtual int who() = 0;
    virtual int ask() = 0;

protected:
    std::string fio;
    char age;
};

#endif // PERSON_HPP
