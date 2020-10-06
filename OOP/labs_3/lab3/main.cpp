#include "classes.hpp"
#include <cstdio>

int main()
{
    D4 t0(2, 1, 5);
    D5 t1(4, 8, 10, 3, 1);

    printf("D4:\n");
    t0.show();
    printf("--------\n");
    printf("D5:\n");
    t1.show();
    printf("--------\n");

    return 0;
}
