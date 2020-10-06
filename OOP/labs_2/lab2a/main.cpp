#define N (3)
#include "sports.hpp"

void set_all(Sportsman *s, int count)
{
    for(int i=0; i < count; i++)
    {
#ifndef IN_SILENT
        std::cout << "Введите ФАМИЛИЮ КОД РЕЗУЛЬТАТ МЕСТО спортсмена [" << i << "] > ";
#endif
        std::cin >> s[i];
    }
}

void get_all(Sportsman *s, int count)
{
    for(int i=0; i < count; i++)
    {
        std::cout << "Спортсмен [" << i << "]: " << s[i] << std::endl;
    }
}

int main()
{
    Sportsman s[N];

    set_all(s, N);
    get_all(s, N);

    Sportsman t;
    for(int i=1; i < 3; i++)
    {
        t = s[i] + s[i-1];
        std::cout << "s[" << i << "] + s[" << (i-1) << "] == "  << t << std::endl;
    }

    return 0;
}
