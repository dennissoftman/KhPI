#include "triangle2d.hpp"
#include "rect2d.hpp"
#include "circle2d.hpp"
#include <cstdio>

int main()
{
    Shape2D *shapes[3] = {new Triangle2D(), new Rect2D(), new Circle2D()};

    printf("Треугольник: a = %.02f, h = %0.2f; S = %.02f\n",
           shapes[0]->GetX(), shapes[0]->GetY(),
           shapes[0]->Square());
    printf("Прямоугольник: a = %.02f, b = %0.2f; S = %.02f\n",
           shapes[1]->GetX(), shapes[1]->GetY(),
           shapes[1]->Square());
    printf("Окружность: r = %.02f; S = %.02f\n",
           shapes[2]->GetX(),
           shapes[2]->Square());

    for(int i=0; i < 3; i++)
        delete shapes[i];
    return 0;
}
