#include "Base.hpp"

Base::Base(int x, int y, int initialScore, int rate)
{ 
    this->maxScore = initialScore;
    this->score = initialScore;
    this->baseShape.setSize(sf::Vector2f(250, 150));
    this->baseShape.setPosition(x, y);
    this->baseShape.setFillColor(sf::Color::Transparent);
    this->baseShape.setOutlineColor(sf::Color::Green);
    this->baseShape.setOutlineThickness(5.f);
}

Base::~Base() {}

void Base::takeDamage(int damage)
{
    score -= damage;
    if(score < 0)
    {
        score = 0;
    }

    updateAppearance();
}

void Base::regenerate(int value)
{
    this->score += value;
    if(this->score > this->maxScore)
    {
        this->score = this->maxScore; 
    }

    updateAppearance();
}

bool Base::isDestroyed()
{
    return score <= 0;
}

int Base::getScore()
{
    return this->score;
}

sf::RectangleShape Base::getShape()
{
    return this->baseShape;
}

void Base::updateAppearance()
{
    // faltando implementar
}