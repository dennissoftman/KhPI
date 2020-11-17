#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
public:
    Person(const std::string &_name="", int _age=0);

    Person(const std::string &_name);
    Person(int _age);

    const std::string &getName() const;
    int getAge() const;

    operator std::string() const;

    friend bool operator <(const Person &a, const Person &b);
    bool operator()(const Person &a, const Person &b) const;
private:
    std::string name;
    int age;
};

#endif // PERSON_HPP
