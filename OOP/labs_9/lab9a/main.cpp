#include <iostream>
#include <vector>

class Sum
{
public:
    Sum()
        : a(0), b(0), S(0)
    { }

    Sum(int _a, int _b)
        : a(_a), b(_b)
    {
        S = a+b;
    }

    int get() const
    {
        return S;
    }

    bool operator <(const Sum &other) const
    {
        return (S < other.S);
    }

    bool operator ==(const Sum &other) const
    {
        return (S == other.S);
    }

private:
    int a, b, S;
};

int main()
{
    std::vector<Sum> A = {Sum(3, 2), Sum(2, 3), Sum(4, 5), Sum(7, 6), Sum(1, 0)};
    std::vector<Sum> B = {Sum(3, 1), Sum(4, 6), Sum(1, 2), Sum(0, 3), Sum(10, 2)};

    int FS;

    std::cout << "vector A: ";
    FS = 0;
    for(const Sum &s : A)
    {
        std::cout << s.get() << " ";
        FS += s.get();
    }
    std::cout << std::endl << "Full sum: " << FS << std::endl;

    std::cout << "vector B: ";
    FS = 0;
    for(const Sum &s : B)
    {
        std::cout << s.get() << " ";
        FS += s.get();
    }
    std::cout << std::endl << "Full sum: " << FS << std::endl;

    std::cout << "A < B:  " << (A < B) << std::endl;
    std::cout << "A > B:  " << (A > B) << std::endl;
    std::cout << "A == B: " << (A == B) << std::endl;

    return 0;
}
