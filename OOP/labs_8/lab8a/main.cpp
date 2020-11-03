#include "number.hpp"

int main()
{
    Number<int> A(5), B(6);

    std::cout << "A == " << A << std::endl;
    std::cout << "B == " << B << std::endl;

    std::cout << "C = A + B == " << (A + B) << std::endl;

    Number<float> Af(15.6f), Bf(23.75f);

    std::cout << "A == " << Af << std::endl;
    std::cout << "B == " << Bf << std::endl;

    std::cout << "C = A + B == " << (Af + Bf) << std::endl;

    return 0;
}
