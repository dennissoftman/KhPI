#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
public:
    Person(const std::string &_fio, int _byear);
    virtual ~Person();

    virtual std::string info() const = 0;
    virtual int who() const = 0;
    virtual int ask() const = 0;

protected:
    std::string fio;
    int byear; // birthyear
};

#endif // PERSON_HPP
