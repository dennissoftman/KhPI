#include "numberset.hpp"
#include <algorithm>
#include <iostream>

NumberSet::NumberSet(int n, int _min, int _max)
{
    int err = 0;
    for(int i=0; i < n; i++)
    {
        int counter = abs(_min) + _max;
        do
        {
            int a = rand() % (abs(_min) + _max + 1) + _min;
            if(std::find(numbers.begin(), numbers.end(), a) != numbers.end())
            {
                err = 1;
                continue;
            }
            numbers.push_back(a);
            err = 0;
            break;
        } while(counter--);

        if(err)
        {
            std::cerr << "Cannot insert number, interval is insufficient" << std::endl;
            return;
        }
    }
}

NumberSet::NumberSet(int n, inter_t interval)
    : NumberSet(n, interval._min, interval._max)
{

}

NumberSet::NumberSet(const NumberSet &other, int _maxv)
{
    numbers.clear();
    for(size_t i=0; i < other.numbers.size(); i++)
        if(other.numbers[i] <= _maxv)
            numbers.push_back(other.numbers[i]);
}

int NumberSet::GetMax() const
{
    if(numbers.size() == 0)
        return 0;

    int _mx = numbers[0];
    for(size_t i = 1; i < numbers.size(); i++)
        if(numbers[i] > _mx)
            _mx = numbers[i];
    return _mx;
}

NumberSet NumberSet::operator +(const NumberSet &other) const
{
    NumberSet _set(*this);
    for(size_t i=0; i < other.numbers.size(); i++)
    {
        int a = other.numbers[i];
        if(std::find(_set.numbers.begin(), _set.numbers.end(), a) == _set.numbers.end())
            _set.numbers.push_back(a);
    }
    return _set;
}

NumberSet NumberSet::operator ^(const NumberSet &other) const
{
    NumberSet _set;
    _set.numbers.clear();
    for(size_t i=0; i < numbers.size(); i++)
    {
        int a = numbers[i];
        if(std::find(other.numbers.begin(), other.numbers.end(), a) != other.numbers.end())
            _set.numbers.push_back(a);
    }
    return _set;
}

NumberSet NumberSet::operator -(const NumberSet &other) const
{
    NumberSet _set;
    _set.numbers.clear();
    for(size_t i=0; i < numbers.size(); i++)
    {
        int a = numbers[i];
        if(std::find(other.numbers.begin(), other.numbers.end(), a) == other.numbers.end())
            _set.numbers.push_back(a);
    }
    return _set;
}

NumberSet NumberSet::operator %(const NumberSet &other) const
{
    // A \ B u B \ A
    return (*this - other) + (other - *this);
}

void NumberSet::Sort()
{
    std::sort(numbers.begin(), numbers.end());
}

std::string NumberSet::GetString() const
{
    std::string s;
    for(size_t i=0; i < numbers.size(); i++)
    {
        s += std::to_string(numbers[i]);
        if(i == (numbers.size()-1))
            break;
        s += ", ";
    }
    return s;
}
