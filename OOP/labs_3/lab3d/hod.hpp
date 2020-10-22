#ifndef HOD_HPP
#define HOD_HPP

#include "lecturer.hpp"

class HoD : public Lecturer
{
public:
    HoD(const std::string &_fio, int _byear, const std::string &_sub, GRADE_ID _grade, const std::string &_pos);

    std::string info() const override;
    int who() const override;
    int ask() const override;
private:
    std::string position;
};

#endif // HOD_HPP
