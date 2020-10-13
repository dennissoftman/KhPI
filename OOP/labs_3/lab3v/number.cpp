#include "number.hpp"

Number::Number()
    : x(0)
{

}

Number::~Number()
{

}

void Number::set(int a)
{
    x = a;
}

int Number::get() const
{
    return x;
}

Number73::Number73()
    : r1(0)
{

}

void Number73::set(int a)
{
    Number::set(a);
    r1 = x % 7;
}

int Number73::get() const
{
    return (r1==3?x:0);
}

Number52::Number52()
    : r2(0)
{

}

void Number52::set(int a)
{
    Number73::set(a);
    r2 = x % 5;
}

int Number52::get() const
{
    return (r1 == 3 && r2 == 2) ? x : 0;
}
