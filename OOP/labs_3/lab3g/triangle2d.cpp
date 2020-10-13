#include "triangle2d.hpp"

Triangle2D::Triangle2D(float a, float h)
    : Shape2D(a, h)
{

}

float Triangle2D::Square() const
{
    return x*y*0.5f;
}

float Triangle2D::GetX() const
{
    return x;
}

float Triangle2D::GetY() const
{
    return y;
}
