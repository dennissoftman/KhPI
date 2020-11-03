#include <iostream>
#include <fstream>
#define GEN_LEN (32)

std::string Generate()
{
    std::string data;
    for(int i=0; i < GEN_LEN; i++)
    {
        int r = (rand() % 100);
        char c;
        if(r >= 48 and r <= 52)
            c = ' ';
        else if(r > 52)
        {
            c = rand() % 26 + 65;
            c = ((rand() % 100 > 50) ? c : tolower(c));
        }
        else
            c = rand() % 10 + '0';
        data += c;
    }
    return data;
}

class Overloaded
{
public:
    Overloaded(const std::string &s)
        : data(s)
    {

    }
    const std::string &GetData() const;
    friend std::ostream &operator <<(std::ostream &out, const Overloaded &a);
private:
    std::string data;
};

const std::string &Overloaded::GetData() const
{
    return data;
}

std::ostream &operator <<(std::ostream &out, const Overloaded &a)
{
    for(char c : a.data)
    {
        if(c >= '0' and c <= '9')
            continue;
        if(c >= 'A' and c <= 'Z')
            continue;
        out << c;
    }
    return out;
}

int main()
{
    srand(time(nullptr));

    Overloaded a(Generate());

    std::cout << "Source string: " << a.GetData() << std::endl;

    std::ofstream fout;

    fout.open("out");
    fout << a;
    fout.close();

    return 0;
}
