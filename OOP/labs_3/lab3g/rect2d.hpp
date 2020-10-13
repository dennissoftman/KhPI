#ifndef RECT2D_HPP
#define RECT2D_HPP

#include "shape2d.hpp"

class Rect2D : public Shape2D
{
public:
    Rect2D(float a=1.f, float b=1.f);

    float Square() const override;

    float GetX() const override;
    float GetY() const override;
};

#endif // RECT2D_HPP
