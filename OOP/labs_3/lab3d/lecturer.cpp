#include "lecturer.hpp"

Lecturer::Lecturer(const std::string &_fio, char _age, const std::string &sub, int _g)
    : Person(_fio, _age), subject(sub), grade(_g)
{

}
