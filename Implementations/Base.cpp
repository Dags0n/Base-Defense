#include "Base.hpp"

// Init funtions
void Base::initVariables()
{
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
}

void Base::initSprite(const char *src, sf::RenderWindow &window)
{
    if (!this->texture->loadFromFile(src))
    {
    }
    this->sprite->setTexture(*this->texture);

    float desiredWidth = 400.0f;
    float desiredHeight = 400.0f;
    float scaleX = desiredWidth / this->sprite->getLocalBounds().width;
    float scaleY = desiredHeight / this->sprite->getLocalBounds().height;
    this->sprite->setScale(sf::Vector2f(scaleX, scaleY));

    float posX = (window.getSize().x - desiredWidth) / 2.0f;
    float posY = (window.getSize().y - desiredHeight) / 2.0f;
    this->sprite->setPosition(sf::Vector2f(posX, posY));
}

// Constructors and Destructors
Base::Base(const char *src, int initialScore, int rate, sf::RenderWindow &window)
{
    this->maxScore = initialScore;
    this->score = initialScore;
    this->regenerationRate = rate;
    this->initVariables();
    this->initSprite(src, window);
}

Base::~Base() 
{
    delete this->texture;
    delete this->sprite;
}

// Getters and Setters
int Base::getScore()
{
    return this->score;
}

// Public functions
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

bool Base::isDestroyed()
{
    return score <= 0;
}

void Base::updateAppearance()
{
    // falta implementar
}

// render
void Base::render(sf::RenderWindow &window)
{
    window.draw(*this->sprite);
}

