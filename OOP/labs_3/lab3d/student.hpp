#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person
{
public:
    Student(const std::string &_fio, int _byear, const int *_grades);

    std::string info() const override;
    int who() const override;
    int ask() const override;
private:
    int grades[5]; // student's grades
};

#endif // STUDENT_HPP
