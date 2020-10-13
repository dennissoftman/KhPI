#ifndef TRIANGLE2D_HPP
#define TRIANGLE2D_HPP

#include "shape2d.hpp"

class Triangle2D : public Shape2D
{
public:
    Triangle2D(float a=1.f, float h=1.f);

    float Square() const override;

    float GetX() const override;
    float GetY() const override;
};

#endif // TRIANGLE2D_HPP
