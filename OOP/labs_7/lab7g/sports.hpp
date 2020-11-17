#ifndef SPORTS_HPP
#define SPORTS_HPP

#include <iostream>
#include <string>
#include <vector>

class Sportsman
{
public:
    Sportsman(const std::string &sn="", const std::string &_tc="0", float _r=0, int _p=1);

    Sportsman &operator =(const Sportsman &s);

    Sportsman operator +(const Sportsman &s) const;
    bool operator ==(const Sportsman &s) const;
    bool operator !=(const Sportsman &s) const;

    operator std::string() const;

    void setSurname(const std::string &_sn);
    void setTeamcode(const std::string &_tc);
    void setResult(float res);
    void setPlace(int pl);

    friend std::ostream &operator <<(std::ostream &out, const Sportsman &s);
    friend std::istream &operator >>(std::istream &in, Sportsman &s);
private:
    std::string surname;    // surname
    std::string teamcode;   // teamcode character (2 byte limited string)
    float result;           // 0.f to 200.f result
    int place;              // place 1,2,3,4,...
};

class Team
{
public:
    Team();
    ~Team();

    void Cleanup();

    void Write(const std::string &fname, const Sportsman &data);
    Sportsman Read(const std::string &fname, int id);

    void Import(const std::string &fname);
    void Export(const std::string &fname);

    std::string GetView() const;

    void Add(Sportsman *data);
private:
    std::vector<Sportsman*> people;
};

#endif // SPORTS_HPP
