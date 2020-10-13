#ifndef SHAPE2D_HPP
#define SHAPE2D_HPP

class Shape2D
{
public:
    Shape2D(float _x, float _y);
    virtual ~Shape2D();

    virtual float Square() const = 0;

    virtual float GetX() const = 0;
    virtual float GetY() const = 0;
protected:
    float x, y;
};

#endif // SHAPE2D_HPP
