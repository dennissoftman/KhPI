#include <iostream>

template<typename T>
class DynamicArray
{
public:
    DynamicArray<T>(std::size_t _idx = 0, std::size_t _size = 100)
        : idx(_idx), size(_size)
    {
        data = new T[size];
    }

    ~DynamicArray<T>()
    {
        delete[] data;
    }

    void insert(T a)
    {
        if(idx < size)
            data[idx++] = a;
    }

    T avg() const
    {
        return sum() / idx; // idx is the count of elements in array
    }

    T sum() const
    {
        T s = 0;
        for(std::size_t i=0; i < idx; i++)
            s += data[i];
        return s;
    }

    std::string str() const
    {
        std::string res;
        for(std::size_t i=0; i < idx; i++)
        {
            res += std::to_string(data[i]);
            if(i < (idx-1))
                res += ", ";
        }
        return res;
    }

    T operator [](int _) const
    {
        T _max = data[0];
        for(std::size_t i=1; i < idx; i++)
            _max = (data[i]>_max?data[i]:_max);
        return _max;
    }

private:
    std::size_t idx, size;
    T *data;
};

int main()
{
    DynamicArray<int> A;

    for(int i=0; i < 10; i++)
        A.insert(rand() % 10);

//    A.insert(0.25f);
//    A.insert(0.1f);
//    A.insert(1.5f);
//    A.insert(2.15f);

    std::cout << "A: " << A.str() << std::endl;
    std::cout << "sum(A): " << A.sum() << std::endl;
    std::cout << "avg(A): " << A.avg() << std::endl;
    std::cout << "max(A): " << A[0] << std::endl;

    return 0;
}
