#ifndef STAFF_HPP
#define STAFF_HPP

#include "person.hpp"
#include <map>

class Staff
{
public:
    Staff();
    ~Staff();

    void insert(const std::string &name, int age);

    void deleteByName(const std::string &name);

    std::string getView(int mask=0) const;

    std::string getFull(const std::string &name) const;
    std::string getName(const std::string &name) const;
    std::string getAge(const std::string &name) const;

    void sortByAge();

    const Person &byName(const std::string &name) const;
    const Person &byAge(int age) const;

private:
    std::map<Person, int> people_s;
    std::map<Person, int, Person> people_f;
    int people_count;
};

#endif // STAFF_HPP
