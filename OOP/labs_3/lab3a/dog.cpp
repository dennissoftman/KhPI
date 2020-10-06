#include "dog.hpp"
#include <cstdio>

Dog::Dog(int _age, float _weight)
    : weight(_weight), age(_age)
{
    printf("Новая собака: возраст - %d лет, вес - %.02f кг\n", age, weight);
}

Dog::~Dog()
{
    printf("Собака умерла\n");
}

void Dog::voice()
{
    printf("%s\n", (weight >= 10.f) ? "ГАВ" : "гав");
}

Spaniel::Spaniel(int _age, float _weight, int _color)
    : Dog(_age, _weight), color(_color)
{
    printf("Собака - Спаниель, цвет №%d\n", color);
}

Spaniel::~Spaniel()
{
    printf("Спаниель умер\n");
}
