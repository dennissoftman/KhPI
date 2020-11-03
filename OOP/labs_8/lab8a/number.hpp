#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <iostream>

template <typename T>
class Number
{
public:
    Number(T a=0);

    Number<T> operator +(const Number<T> &other) const;

    friend std::ostream &operator <<(std::ostream &out, const Number<T> &a);
private:
    T v;
};

#endif // NUMBER_HPP
