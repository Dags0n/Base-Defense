#include "Hero.hpp"

// Init funtions
void Hero::initVariables()
{
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
    this->destiny = sf::Vector2i(0, 0);
    this->speed = 1.5;
}

void Hero::initAttributes()
{
    this->life = new Attribute(100, 100);
    this->ammunition = new Attribute(100, 100);
}

void Hero::initSprite(const char *src, sf::RenderWindow &window)
{
    if (!this->texture->loadFromFile(src))
    {
    }
    this->sprite->setTexture(*this->texture);
    sf::FloatRect bounds = this->sprite->getLocalBounds();
    this->sprite->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    float posX = window.getSize().x / 2.0;
    float posY = window.getSize().y / 2.0;
    this->sprite->setPosition(sf::Vector2f(posX, posY));
    this->destiny = sf::Vector2i(posX, posY);
}

// Constructors and Destructors
Hero::Hero(const char *src, sf::RenderWindow &window)
{
    this->initVariables();
    this->initAttributes();
    this->initSprite(src, window);
}

Hero::~Hero()
{
    delete this->texture;
    delete this->sprite;
    delete this->life;
    delete this->ammunition;
}

// Getters and Setters
sf::Vector2f Hero::getMouseDirection(sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f heroPos = this->sprite->getPosition();
    sf::Vector2f direction = sf::Vector2f(mousePos.x, mousePos.y) - heroPos;
    return direction;
}

sf::Vector2f Hero::getDestinyDirection()
{
    sf::Vector2f heroPos = this->sprite->getPosition();
    sf::Vector2f direction = sf::Vector2f(this->destiny.x, this->destiny.y) - heroPos;
    return direction;
}

sf::Vector2f Hero::getPosition()
{
    return this->sprite->getPosition();
}

void Hero::setDestiny(sf::Vector2i destiny)
{
    this->destiny = destiny;
}

// Update
void Hero::updateRotation(sf::Vector2f direction)
{
    float angleRad = atan2(direction.y, direction.x);
    float angleDeg = (angleRad * (180.f / static_cast<float>(M_PI))) + 90.f;
    this->sprite->setRotation(angleDeg);
}

void Hero::updatePosition(sf::Vector2f direction, float deltaTime)
{
    this->sprite->move(direction * this->speed * deltaTime);
}

void Hero::update(sf::RenderWindow &window, float deltaTime)
{
    sf::Vector2f directionMouse = this->getMouseDirection(window);
    sf::Vector2f directionDestiny = this->getDestinyDirection();
    this->updateRotation(directionMouse);
    this->updatePosition(directionDestiny, deltaTime);

    // Collision
}

// Render
void Hero::render(sf::RenderWindow &window)
{
    window.draw(*this->sprite);
}
