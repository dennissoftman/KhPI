#include "number.hpp"
#include <cstdio>

#define N (100)

int main()
{
    Number *nums[N];

    for(int i=0; i < N; i++)
    {
        nums[i] = new Number52();
        nums[i]->set(i);
    }

    for(int i=0; i < N; i++)
    {
        if(nums[i]->get())
            printf("%d: число %d\n", i, nums[i]->get());
    }

    for(int i=0; i < N; i++)
        delete nums[i];

    return 0;
}
