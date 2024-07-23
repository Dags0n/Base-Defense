#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

class Attribute
{
private:
    int amount;
    int max;

public:
    Attribute(int amount, int max);
    void recharge(int value);
    void consume(int value);
    int points();
    int maxPoints();
    void setMax(int max);
};

#endif