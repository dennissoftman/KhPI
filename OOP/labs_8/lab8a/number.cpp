#include "number.hpp"

template<typename T>
Number<T>::Number(T a)
{
    v = a;
}

template<typename T>
Number<T> Number<T>::operator +(const Number<T> &other) const
{
    return Number(v + other.v);
}

std::ostream &operator <<(std::ostream &out, const Number<char> &a)
{
    out << "<char> " << (int)a.v;
    return out;
}

std::ostream &operator <<(std::ostream &out, const Number<short> &a)
{
    out << "<short> " << a.v;
    return out;
}

std::ostream &operator <<(std::ostream &out, const Number<int> &a)
{
    out << "<int> " << a.v;
    return out;
}

std::ostream &operator <<(std::ostream &out, const Number<float> &a)
{
    out << "<float> " << a.v;
    return out;
}

std::ostream &operator <<(std::ostream &out, const Number<double> &a)
{
    out << "<double> " << a.v;
    return out;
}

template class Number<int>;
template class Number<float>;
