#include "Base.hpp"

// Init funtions
void Base::initAttributes(){
    this->life = new Attribute(100, 100);
    this->regenRate = new Attribute(1, 1);
}

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
Base::Base(const char *src, sf::RenderWindow &window)
{
    this->initAttributes();
    this->initVariables();
    this->initSprite(src, window);
}

Base::~Base()
{
    delete this->texture;
    delete this->sprite;
    delete this->life;
    delete this->regenRate;
}

// Getters and Setters
int Base::getLife()
{
    return this->life->points();
}

int Base::getMaxLife(){
    return this->life->maxPoints();
}

int Base::getRate(){
    return this->regenRate->points();
}

sf::FloatRect Base::getArea()
{
    return this->sprite->getGlobalBounds();
}

// Public functions
void Base::damage(int value)
{
    this->life->consume(value);
}


// update functions
void Base::regenerate(){
    this->life->recharge(regenRate->points());
}

void Base::update()
{
    if(this->regenClock.getElapsedTime().asSeconds() >= 1.0f)
    {
        this->regenerate();
        this->regenClock.restart();
    }
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
