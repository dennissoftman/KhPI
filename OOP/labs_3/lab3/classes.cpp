#include "classes.hpp"
#include <cstdio>

B::B(int _a)
    : a(_a)
{
}

void B::show()
{
    printf("a = %d\n", a);
}

D1::D1(int _a, int _b)
    : B(_a), b(_b)
{
}

void D1::show()
{
    B::show();
    printf("b = %d\n", b);
}

D2::D2(int _a, int _c)
    : B(_a), c(_c)
{
}

void D2::show()
{
    B::show();
    printf("c = %d\n", c);
}

D3::D3(int _a, int _d)
    : B(_a), d(_d)
{
}

void D3::show()
{
    B::show();
    printf("d = %d\n", d);
}

D4::D4(int _a, int _b, int _e)
    : D1(_a, _b), e(_e)
{
}

void D4::show()
{
    D1::show();
    printf("e = %d\n", e);
}

D5::D5(int _a, int _b, int _c, int _d, int _f)
    : D1(_a, _b), D2(_a, _c), D3(_a, _d), f(_f)
{
}

void D5::show()
{
    D1::show();
    D2::show();
    D3::show();
    printf("f = %d\n", f);
}
