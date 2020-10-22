#include "lecturer.hpp"

Lecturer::Lecturer(const std::string &_fio, int _byear, const std::string &sub, GRADE_ID _g)
    : Person(_fio, _byear), subject(sub), grade(_g)
{

}

std::string Lecturer::info() const
{
    return fio+" (" + std::to_string(byear) + "). "+subject+", степень: "+std::to_string(grade);
}

int Lecturer::who() const
{
    return 1;
}

int Lecturer::ask() const
{
    return grade;
}

int Lecturer::GetAge() const
{
    int cy = 1970 + time(nullptr)/(60 * 60 * 24 * 365);
    return (cy-byear);
}
