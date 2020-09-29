#include "sports.hpp"

Sportsman::Sportsman(const std::string &sn, const std::string &_tc, float _r, int _p)
    : surname(sn), result(_r), place(_p)
{
    SetTeamcode(_tc);
}

Sportsman &Sportsman::operator =(const Sportsman &s)
{
    surname = s.surname;
    teamcode = s.teamcode;
    result = s.result;
    place = s.place;
    return *this;
}

void Sportsman::SetTeamcode(const std::string &_tc)
{
    if(_tc[0] > 0)
        teamcode = _tc[0];
    else
        teamcode = _tc.substr(0, 2);
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

void Sportsman::operator ()(const std::string &sn, const std::string &_tc, float _r, int _p)
{
    surname = sn;
    SetTeamcode(_tc);
    result = _r;
    place = _p;
}

std::size_t Sportsman::operator [](int i) const
{
    if(i > 1)
        return std::string::npos;
    if(i == 1)
        return surname.length();
    return teamcode.length();
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
    std::string t;
    getValue(in, s.surname);
    getValue(in, t);
    s.SetTeamcode(t);
    getValue(in, s.result);
    getValue(in, s.place);
    return in;
}
