#include "sports.hpp"
#include <sstream>
#include <fstream>

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

void Sportsman::setSurname(const std::string &_sn)
{
    surname = _sn;
}

void Sportsman::setTeamcode(const std::string &_tc)
{
    teamcode = _tc;
}

void Sportsman::setResult(float res)
{
    result = res;
}

void Sportsman::setPlace(int pl)
{
    place = pl;
}

Sportsman::operator std::string() const
{
    return surname + "["
         + teamcode + "] with "
         + std::to_string(result) + ", place "
         + std::to_string(place);
}

std::ostream &operator <<(std::ostream &out, const Sportsman &s)
{
    out << s.surname << ' ' << s.teamcode << ' ' << s.result << ' ' << s.place;
    return out;
}

//std::istream &operator >>(std::istream &in, Sportsman &s)
//{
//    getValue(in, s.surname);
//    getValue(in, s.teamcode);
//    if(s.teamcode[0] > 0)
//        s.teamcode = s.teamcode[0];
//    else
//        s.teamcode = s.teamcode.substr(0, 2);
//    getValue(in, s.result);
//    getValue(in, s.place);
//    return in;
//}

std::istream &operator >>(std::istream &in, Sportsman &s)
{
    in >> s.surname >> s.teamcode >> s.result >> s.place;
    return in;
}

Team::Team()
{

}

Team::~Team()
{
    Cleanup();
}

void Team::Cleanup()
{
    for(Sportsman *s : people)
        delete s;
    people.clear();
}

void Team::Write(const std::string &fname, const Sportsman &data)
{
    std::ofstream fh;
    fh.open(fname, std::ios::out | std::ios::app);
    fh << data;
    fh.close();
}

Sportsman Team::Read(const std::string &fname, int id)
{
    std::ifstream fh;
    fh.open(fname, std::ios::in);

    std::string line;
    for(int i=0; i < id; i++)
    {
        if(!std::getline(fh, line))
            throw std::invalid_argument("Record not found");
    }
    fh.close();

    Sportsman tmp;
    std::stringstream ss;
    ss << line;
    ss >> tmp;

    return tmp;
}

void Team::Import(const std::string &fname)
{
    std::ifstream fh;
    fh.open(fname, std::ios::in);
    if(!fh.is_open())
        throw std::invalid_argument("File not found");
    Cleanup();
    Sportsman tmp;
    std::string line;
    while(std::getline(fh, line))
    {
        std::stringstream ss;
        ss << line;
        ss >> tmp;
        people.push_back(new Sportsman(tmp));
    }
    fh.close();
}

void Team::Export(const std::string &fname)
{
    std::ofstream fh;
    fh.open(fname, std::ios::out);
    if(!fh.is_open())
        throw std::invalid_argument("Failed to create file");

    for(Sportsman *s : people)
        fh << (*s) << "\n";
    fh.close();
}

std::string Team::GetView() const
{
    std::string res;
    for(Sportsman *s : people)
    {
        res += std::string(*s) + "\n";
    }
    return res;
}

void Team::Add(Sportsman *data)
{
    people.push_back(data);
}
