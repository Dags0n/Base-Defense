#include "Base.hpp"

Base::Base(int initialScore, int rate, const sf::Vector2u windowSize)
{
    this->maxScore = initialScore;
    this->score = initialScore;
    this->regenerationRate = rate;
    this->baseShape.setSize(sf::Vector2f(250, 150));

    this->initCenterBase(windowSize);

    this->baseShape.setFillColor(sf::Color::Transparent);
    this->baseShape.setOutlineColor(sf::Color::Green);
    this->baseShape.setOutlineThickness(5.f);
}

Base::~Base() {}

void Base::takeDamage(int damage)
{
    score -= damage;
    if (score < 0)
    {
        score = 0;
    }

    updateAppearance();
}

void Base::regenerate(int value)
{
    this->score += value;
    if (this->score > this->maxScore)
    {
        this->score = this->maxScore;
    }

    updateAppearance();
}

void Base::initCenterBase(const sf::Vector2u windowSize)
{
    if (windowSize.x > 0 && windowSize.y > 0)
    {
        float x = (windowSize.x - this->baseShape.getLocalBounds().width) / 2.0f;
        float y = (windowSize.y - this->baseShape.getLocalBounds().height) / 2.0f;
        this->baseShape.setPosition(sf::Vector2f(x, y));
    }
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
    // falta implementar
}