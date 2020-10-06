#include "sports.hpp"

Sportsman::Sportsman(const std::string &sn, const std::string &_tc, float _r, int _p)
    : surname(sn), teamcode(_tc.substr(0, 2)), result(_r), place(_p)
{

}

Sportsman &Sportsman::operator =(const Sportsman &s)
{
    surname = s.surname;
    teamcode = s.teamcode;
    result = s.result;
    place = s.place;
    return *this;
}

Sportsman Sportsman::operator +(const Sportsman &s) const
{
    Sportsman t(*this);
    t.surname += "-" + s.surname;
    t.teamcode = s.teamcode; // why should I add teamcodes?
    t.result = (t.result + s.result)/2.f;
    t.place = (s.place + t.place) >> 1;
    return t;
}

bool Sportsman::operator ==(const Sportsman &s) const
{
    if(surname != s.surname)
        return false;
    if(teamcode != s.teamcode)
        return false;
    if(result != s.result)
        return false;
    if(place != s.place)
        return false;
    return true;
}

bool Sportsman::operator !=(const Sportsman &s) const
{
    return !(*this == s);
}

std::ostream &operator <<(std::ostream &out, const Sportsman &s)
{
    out << s.surname << "[" << s.teamcode << "] with " << s.result << ", place " << s.place;
    return out;
}

void getValue(std::istream &in, std::string &s)
{
    in >> s;
}

void getValue(std::istream &in, int &d)
{
    std::string t;
    do
    {
        in >> t;
        try
        {
            d = std::stoi(t);
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Введите число!" << std::endl;
            continue;
        }
    } while(1);
}

void getValue(std::istream &in, float &f)
{
    std::string t;
    do
    {
        in >> t;
        try
        {
            f = std::stof(t);
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Введите число!" << std::endl;
            continue;
        }
    } while(1);
}

std::istream &operator >>(std::istream &in, Sportsman &s)
{
    getValue(in, s.surname);
    getValue(in, s.teamcode);
    if(s.teamcode[0] > 0)
        s.teamcode = s.teamcode[0];
    else
        s.teamcode = s.teamcode.substr(0, 2);
    getValue(in, s.result);
    getValue(in, s.place);
    return in;
}
