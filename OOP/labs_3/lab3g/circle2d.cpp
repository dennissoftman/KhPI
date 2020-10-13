#include "circle2d.hpp"
#include <cmath>

Circle2D::Circle2D(float r, float _)
    : Shape2D(r, _)
{

}

float Circle2D::Square() const
{
    return M_PIf32 * x * x; // pi * r^2
}

float Circle2D::GetX() const
{
    return x;
}

float Circle2D::GetY() const
{
    return GetX();
}
