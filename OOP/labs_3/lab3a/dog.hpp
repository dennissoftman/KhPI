#ifndef DOG_HPP
#define DOG_HPP


class Dog
{
public:
    Dog(int _age=1, float _weight=1.f);
    ~Dog();

    void voice();
protected:
    float weight;
    int age;
};

class Spaniel : public Dog
{
public:
    Spaniel(int _age=1, float _weight=1.f, int _color=0);
    ~Spaniel();
private:
    int color;
};

#endif // DOG_HPP
