#include "student.hpp"

Student::Student(const std::string &_fio, int _byear, const int *_grades)
    : Person(_fio, _byear)
{
    for(int i=0; i < 5; i++)
        grades[i] = _grades[i];
}

std::string stringify(const int *arr, int n)
{
    std::string s;
    for(int i=0; i < n; i++)
    {
        s += std::to_string(arr[i]);
        if(i < (n-1))
            s += ", ";
    }
    return s;
}

std::string Student::info() const
{
    return fio + " (" + std::to_string(byear) + "). Оценки: " + stringify(grades, 5);
}

int Student::who() const
{
    return 3;
}

int Student::ask() const
{
    int cnt=0;
    for(int i=0; i < 5; i++)
        cnt += (grades[i] == 2);
    return cnt;
}
