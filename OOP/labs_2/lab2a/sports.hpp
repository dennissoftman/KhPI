#ifndef SPORTS_HPP
#define SPORTS_HPP

#include <iostream>
#include <string>

class Sportsman
{
public:
    Sportsman(const std::string &sn="", const std::string &_tc="0", float _r=0, int _p=1);

    Sportsman &operator =(const Sportsman &s);

    Sportsman operator +(const Sportsman &s) const;
    bool operator ==(const Sportsman &s) const;
    bool operator !=(const Sportsman &s) const;

    friend std::ostream &operator <<(std::ostream &out, const Sportsman &s);
    friend std::istream &operator >>(std::istream &in, Sportsman &s);
private:
    std::string surname;    // surname
    std::string teamcode;   // teamcode character (2 byte limited string)
    float result;           // 0.f to 200.f result
    int place;              // place 1,2,3,4,...
};

#endif // SPORTS_HPP
