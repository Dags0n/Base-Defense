#include "Attribute.hpp"

Attribute::Attribute(int amount, int max)
{
    this->amount = amount;
    this->setMax(max);
}

void Attribute::recharge(int value)
{
    ((amount + value) > max) ? amount = max : amount += value;
}

void Attribute::recharge(float value)
{
    ((amount + value) > max) ? amount = max : amount += value;
} 

void Attribute::consume(int value)
{
    ((amount - value) < 0) ? amount = 0 : amount -= value;
}

int Attribute::points()
{
    return this->amount;
}

int Attribute::maxPoints()
{
    return this->max;
}

void Attribute::setMax(int max)
{
    this->max = max;
}
