#include <iostream>
#include <map>

class Name
{
public:
    Name(const std::string &_name="")
        : name(_name)
    {
    }
    void set(const std::string &n)
    {
        name = n;
    }
    std::string get() const
    {
        return name;
    }
    bool operator <(const Name &other) const
    {
        return (name < other.name);
    }
    bool operator ==(const Name &other) const
    {
        return (name == other.name);
    }
private:
    std::string name;
};

class Number
{
public:
    Number(const std::string &n="")
        : number(n)
    {

    }
    void set(const std::string &n)
    {
        number = n;
    }
    std::string get() const
    {
        return number;
    }
private:
    std::string number;
};

void cutoff_char(std::string &s)
{
    if((char)s[0] < 0)
        s = s.substr(0, 2);
    else
        s = s.substr(0, 1);
}

int main()
{
    std::map<Name, Number> db;

    db.emplace(Name("Газовщики"), Number("104"));
    db.emplace(Name("Пожарные"), Number("101"));
    db.emplace(Name("Полиция"), Number("102"));
    db.emplace(Name("Скорая помощь"), Number("103"));
    db.emplace(Name("Князь"), Number("777"));
    db.emplace(Name("Дьявол"), Number("666"));

    for(auto &s : db)
        std::cout << s.first.get() << ": " << s.second.get() << std::endl;

    std::string tmp;

    std::cout << "[Search by name] Name: ";
    std::cin >> tmp;

    const auto &s = db.find(Name(tmp));
    if(s != db.end())
        std::cout << s->first.get() << ": " << s->second.get() << std::endl;
    else
        std::cout << "No suitable records found" << std::endl;

    std::cout << "[Filter by first character] Character: ";
    std::cin >> tmp;

    cutoff_char(tmp);

    for(auto &s : db)
    {
        std::string fch = s.first.get();
        cutoff_char(fch);
        if(fch == tmp)
            std::cout << s.first.get() << ": " << s.second.get() << std::endl;
    }

    std::cout << "[Remove by first character] Character: ";
    std::cin >> tmp;

    cutoff_char(tmp);

    bool found;
    do
    {
        found = false;
        for(auto &s : db)
        {
            std::string fch = s.first.get();
            cutoff_char(fch);
            if(fch == tmp)
            {
                found = true;
                db.erase(s.first);
                break;
            }
        }
    } while(found);

    for(auto &s : db)
        std::cout << s.first.get() << ": " << s.second.get() << std::endl;

    return 0;
}
