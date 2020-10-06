#include "dog.hpp"
#include <cstdio>

int main()
{
    Dog *a = new Dog(2, 3.5f);
    a->voice();
    delete a;

    printf("\n");

    Spaniel *b = new Spaniel(4, 10.5f, 2);
    b->voice();
    delete b;

    return 0;
}
