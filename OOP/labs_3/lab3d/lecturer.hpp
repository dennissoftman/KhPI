#ifndef LECTURER_H
#define LECTURER_H

#include "person.hpp"

enum GRADE_ID
{
    GRADE_NO=0,
    GRADE_KTN=1,
    GRADE_DTN=2,
};

class Lecturer : public Person
{
public:
    Lecturer(const std::string &_fio, int _byear, const std::string &sub, GRADE_ID _g);

    std::string info() const override;
    int who() const override;
    int ask() const override;

    int GetAge() const;
protected:
    std::string subject;
    GRADE_ID grade;
};

#endif // LECTURER_H
