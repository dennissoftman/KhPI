#include "deltatime.hpp"
#include <iostream>

int main()
{
    DeltaTime t0, t1;

    t0.SetHours(2);
    t0.SetMinutes(28);
    t0.SetSeconds(0);

    t1.SetHours(4);
    t1.SetMinutes(54);
    t1.SetSeconds(0);

    std::cout << "t0 == " << t0.GetTime() << std::endl;
    std::cout << "t1 == " << t1.GetTime() << std::endl;
    std::cout << "t1 - t0 == " << (t1 - t0).GetTime() << std::endl;
    std::cout << "^t0 == " << t0.GetAngle() << "º" << std::endl;
    std::cout << "^t1 == " << t1.GetAngle() << "º" << std::endl;

    std::cout << "t0 == t1: " << ((t0 == t1) ? "YES" : "NO") << std::endl;
    std::cout << "t0 >  t1: " << ((t0 >  t1) ? "YES" : "NO") << std::endl;
    std::cout << "t0 >= t1: " << ((t0 >= t1) ? "YES" : "NO") << std::endl;
    std::cout << "t0 <  t1: " << ((t0 <  t1) ? "YES" : "NO") << std::endl;
    std::cout << "t0 <= t1: " << ((t0 <= t1) ? "YES" : "NO") << std::endl;

    return 0;
}
