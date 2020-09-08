#include "train.hpp"
#include <vector>

#include <iostream>
#include <algorithm>

#define CNTWARN(m) { std::cerr << m << std::endl; continue; }

void user_fill(Train &t)
{
    std::string buff;

    std::cout << "Enter train's destination > ";
    std::cin >> buff;
    t.SetDest(buff);

    do
    {
        std::cout << "Enter train's ID > ";
        std::cin >> buff;
        try
        {
            int id = std::stoi(buff);
            if(id < 0)
                throw std::invalid_argument("train_id");
            t.SetTID(id);
        }
        catch(std::invalid_argument &e)
        {
            CNTWARN("Train's ID must be a number >=0!")
        }
        break;
    } while(0 == 0);

    do
    {
        std::cout << "Enter train's departure time in format HHMM > ";
        std::cin >> buff;
        if(buff.length() != 4)
            CNTWARN("Incorrect time format!");
        break;
    } while(0 == 0);
    hm_t tmp;
    tmp = std::stoi(buff.substr(2, 2)) & 0x3F;          // minutes
    tmp |= (std::stoi(buff.substr(0, 2)) & 0x1F) << 6;  // hours
    t.SetDT(tmp);
}

static std::vector<std::string> cities =
{
    "Cherkasy", "Chernivtsi", "Chernihiv",
    "Dnipro",
    "Herson",
    "Kharkiv", "Kyiv",
    "Odesa",
    "Poltava",
    "Zaporozhia"
};

std::string random_city()
{
    return cities[rand() % cities.size()];
}

void auto_fill(Train &t)
{
    t.SetDest(random_city());
    t.SetTID(rand() % 100);
    t.SetDT(rand() % (60 + (23 << 6)));
}

void help()
{
    std::cout << "Commands:\n"
                 "  add   - add new train\n"
                 "  print - print train list\n"
                 "  sort  - sort trains\n"
                 "  quit  - quit\n";
}

bool train_comp(const Train &a, const Train &b)
{
    if(b.GetDest() == a.GetDest())
        return b.GetDT() > a.GetDT();
    return b.GetDest() > a.GetDest();
}

bool train_comp_no(const Train &a, const Train &b)
{
    return b.GetTID() > a.GetTID();
}

int main()
{
    srand(time(nullptr));
    std::vector<Train> trains;

    std::string cmd;
    Train newt;
    do
    {
        std::cout << "Enter cmd > ";
        std::cin >> cmd;

        if(cmd[0] == 'h')
            help();
        else if(cmd[0] == 'a') // add
        {
            user_fill(newt);
            trains.push_back(std::move(newt));
        }
        else if(cmd[0] == 'p') // print
        {
            for(const Train &t : trains)
                std::cout << t.GetInfo() << std::endl;
        }
        else if(cmd[0] == 'f') // fill with 5 entries
        {
            for(int i=0; i < 5; i++)
            {
                auto_fill(newt);
                trains.push_back(std::move(newt));
            }
            std::sort(trains.begin(), trains.end(), train_comp_no);
        }
        else if(cmd[0] == 's') // sort by destination(departure)
        {
            std::sort(trains.begin(), trains.end(), train_comp);
        }
        else if(cmd[0] == 'q') // quit
            break;
    } while(0 == 0);
    return 0;
}
