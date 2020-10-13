#include "rect2d.hpp"

Rect2D::Rect2D(float a, float b)
    : Shape2D(a, b)
{

}

float Rect2D::Square() const
{
    return x*y;
}

float Rect2D::GetX() const
{
    return x;
}

float Rect2D::GetY() const
{
    return y;
}
