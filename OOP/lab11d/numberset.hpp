#ifndef NUMBERSET_HPP
#define NUMBERSET_HPP


#include <vector>
#include <string>

/*
Разработать класс для представления объекта множество чисел (элементы не повторяются).
– Определить конструктор с тремя параметрами (количество элементов,
  минимальный и максимальный в диапазоне генерируемых чисел),
  который задаёт элементы множества (конструктор с параметрами).
– Определить конструктор, который генерирует множество из 10 элементов в диапазоне [-20; 20] (конструктор по умолчанию).
– Определить конструктор, которые копирует в новое множество элементы другого множества, не превышающие заданное значение (конструктор копирования).
– Создать функцию, которая находит максимальное значение в множестве.
– Создать функции для построения объединения, пересечения, разности и дизъюнктивной суммы двух числовых множеств.
*/

struct inter_s
{
    int _min, _max;
} typedef inter_t;

class NumberSet
{
public:
    NumberSet(int n, int _min, int _max);
    NumberSet(int n=10, inter_t interval = {-20, 20});
    NumberSet(const NumberSet &other, int _maxv);

    int GetMax() const;
    NumberSet operator +(const NumberSet &other) const; // union
    NumberSet operator ^(const NumberSet &other) const; // intersection
    NumberSet operator -(const NumberSet &other) const; // difference
    NumberSet operator %(const NumberSet &other) const; // disjunctive sum

    void Sort();

    std::string GetString() const;

private:
    std::vector<int> numbers;
};

#endif // NUMBERSET_HPP
