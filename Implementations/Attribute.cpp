#include "Attribute.hpp"

Attribute::Attribute(int amount, int max)
{
    this->amount = amount;
    this->max = max;
}

void Attribute::recharge(int value)
{
    ((amount+value)>max)? amount = max : amount += value;
}

void Attribute::consume(int value)
{
    ((amount-value)<0)? amount = 0 : amount -= value;
}

int Attribute::getValue()
{
    return amount;
}
