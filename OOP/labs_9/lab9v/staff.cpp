#include "staff.hpp"
#include <set>
#include <algorithm>
#include <iostream>

Staff::Staff()
    : people_count(0)
{
    Person null("__null__", -1); // always will be first in people_f
    people_s[null] = -1;
    people_f[null] = -1;
}

Staff::~Staff()
{
    people_s.clear();
    people_f.clear(); // same Person* here, no need to delete
}

void Staff::insert(const std::string &name, int age)
{
    if(age <= 0)
        return;
    people_s.insert(std::pair<Person, int>(Person(name, age), age));
    people_f.insert(std::pair<Person, int>(Person(name, age), age));
}

void Staff::deleteByName(const std::string &name)
{
    for(auto it = people_s.begin(); it != people_s.end(); it++)
    {
        if(it->first.getName() == name)
        {
            people_s.erase(it);
            break;
        }
    }
    for(auto it = people_f.begin(); it != people_f.end(); it++)
    {
        if(it->first.getName() == name)
        {
            people_f.erase(it);
            break;
        }
    }
}

std::string Staff::getView(int mask) const
{
    std::string res;

    res += "NAME-sorted map:\n";
    for(auto &ps : people_s)
    {
        if(ps.second > 0)
        {
            res += "  ";
            if(mask == 0)
                res += std::string(ps.first);
            else if(mask == 1)
                res += std::to_string(ps.first.getAge());
            else if(mask == 2)
                res += ps.first.getName();
            res += "\n";
        }
    }
    res += "AGE-sorted map:\n";
    for(auto &ps : people_f)
    {
        if(ps.second > 0)
        {
            res += "  ";
            if(mask == 0)
                res += std::string(ps.first);
            else if(mask == 1)
                res += std::to_string(ps.first.getAge());
            else if(mask == 2)
                res += ps.first.getName();
            res += "\n";
        }
    }
    return res;
}

std::string Staff::getFull(const std::string &name) const
{
    for(auto &s : people_s)
        if(s.first.getName() == name)
            return s.first;
    return people_s.begin()->first;
}

std::string Staff::getName(const std::string &name) const
{
    for(auto &s : people_s)
        if(s.first.getName() == name)
            return s.first.getName();
    return people_s.begin()->first.getName();
}

std::string Staff::getAge(const std::string &name) const
{
    for(auto &s : people_s)
        if(s.first.getName() == name)
            return std::to_string(s.second);
    return std::to_string(people_s.begin()->second);
}

const Person &Staff::byName(const std::string &name) const
{
    for(auto &s : people_s)
    {
        if(s.first.getName() == name)
            return s.first;
    }
    return people_f.begin()->first;
}

const Person &Staff::byAge(int age) const
{
    for(auto &s : people_s)
    {
        if(s.first.getAge() == age)
            return s.first;
    }
    return people_f.begin()->first;
}
