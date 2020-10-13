#ifndef NUMBER_HPP
#define NUMBER_HPP

class Number
{
public:
    Number();
    virtual ~Number();

    virtual void set(int a);
    virtual int get() const;
protected:
    int x;
};

class Number73 : public Number
{
public:
    Number73();

    void set(int a) override;
    int get() const override;
protected:
    int r1;
};

class Number52 : public Number73
{
public:
    Number52();
    void set(int a) override;
    int get() const override;
protected:
    int r2;
};

#endif // NUMBER_HPP
