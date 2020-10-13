#ifndef CIRCLE2D_HPP
#define CIRCLE2D_HPP

#include "shape2d.hpp"

class Circle2D : public Shape2D
{
public:
    Circle2D(float r=1.f, float _=0.f);

    float Square() const override;

    float GetX() const override;
    float GetY() const override;
};

#endif // CIRCLE2D_HPP
