#ifndef CLASSES_HPP
#define CLASSES_HPP

class B
{
public:
    B(int _a=0);
    virtual void show();
private:
    int a;
};

class D1 : public B
{
public:
    D1(int _a=0, int _b=0);
    virtual void show();
private:
    int b;
};

class D2 : private B
{
public:
    D2(int _a=0, int _c=0);
    virtual void show();
private:
    int c;
};

class D3 : private B
{
public:
    D3(int _a=0, int _d=0);
    virtual void show();
private:
    int d;
};

class D4 : private D1
{
public:
    D4(int _a=0, int _b=0, int _e=0);
    virtual void show();
private:
    int e;
};

class D5 : public D1, public D2, private D3
{
public:
    D5(int _a=0, int _b=0, int _c=0, int _d=0, int _f=0);
    void show() override;
private:
    int f;
};
#endif // CLASSES_HPP
