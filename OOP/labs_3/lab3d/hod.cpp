#include "hod.hpp"
#include <ctime>

HoD::HoD(const std::string &_fio, int _byear, const std::string &_sub, GRADE_ID _grade, const std::string &_pos)
    : Lecturer(_fio, _byear, _sub, _grade), position(_pos)
{

}

std::string HoD::info() const
{
    return "[ЗавКаф] " + Lecturer::info() + ", должность: " + position;
}

int HoD::who() const
{
    return 2;
}

int HoD::ask() const
{
    return GetAge();
}
