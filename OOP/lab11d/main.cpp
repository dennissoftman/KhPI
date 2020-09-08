#include "numberset.hpp"
#include <iostream>

int main()
{
    srand(time(nullptr));
    NumberSet s1;
    s1.Sort();
    NumberSet s2(20, -10, 10);
    s2.Sort();

    std::cout << "s1: " << s1.GetString() << std::endl;
    std::cout << "s1 max value: " << s1.GetMax() << std::endl;
    std::cout << "s2: " << s2.GetString() << std::endl;
    std::cout << "s2 max value: " << s2.GetMax() << std::endl;

    NumberSet s3(s2, 3);
    s3.Sort();
    std::cout << "s3 (at most value 3): " << s3.GetString() << std::endl;

    NumberSet s1u2 = (s1 + s2);
    s1u2.Sort();

    NumberSet s1p2 = (s1 ^ s2);
    s1p2.Sort();

    NumberSet s1m2 = (s1 - s2);
    s1m2.Sort();

    NumberSet s1s2 = (s1 % s2);
    s1s2.Sort();

    std::cout << "s1 \\/ s2: " << s1u2.GetString() << std::endl;
    std::cout << "s1 /\\ s2: " << s1p2.GetString() << std::endl;
    std::cout << "s1 \\ s2: " << s1m2.GetString() << std::endl;
    std::cout << "s1 (+) s2: " << s1s2.GetString() << std::endl;

    return 0;
}
