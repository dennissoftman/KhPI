#include "person.hpp"

Person::Person(const std::string &_name, int _age)
    : name(_name), age(_age)
{

}

Person::Person(const std::string &_name)
    : name(_name), age(0)
{

}

Person::Person(int _age)
    : name(""), age(_age)
{

}

const std::string &Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

bool operator <(const Person &a, const Person &b)
{
    return (a.name < b.name);
}

bool Person::operator()(const Person &a, const Person &b) const
{
    return (a.age < b.age);
}

Person::operator std::string() const
{
    return std::string(name + " (" + std::to_string(age) + ")");
}
