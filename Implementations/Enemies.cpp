#include "Enemies.hpp"

// Utility functions
sf::Vector2f generateRandomPosition(sf::RenderTarget &target, float margin = 0.f)
{
    int side = rand() % 4;
    float x, y;
    switch (side)
    {
    case 0: // Top
        x = static_cast<float>(rand() % static_cast<int>(target.getSize().x + 2 * margin)) - margin;
        y = -margin;
        break;
    case 1: // Right
        x = target.getSize().x + margin;
        y = static_cast<float>(rand() % static_cast<int>(target.getSize().y + 2 * margin)) - margin;
        break;
    case 2: // Bottom
        x = static_cast<float>(rand() % static_cast<int>(target.getSize().x + 2 * margin)) - margin;
        y = target.getSize().y + margin;
        break;
    case 3: // Left
        x = -margin;
        y = static_cast<float>(rand() % static_cast<int>(target.getSize().y + 2 * margin)) - margin;
        break;
    }
    sf::Vector2f position(x, y);
    return position;
}

// Init functions
void Enemies::initVariables()
{
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
}

void Enemies::initSprite(const char *src, sf::RenderTarget &target)
{
    if (!this->texture->loadFromFile(src))
    {
    }
    this->sprite->setTexture(*this->texture);

    sf::Vector2f position = generateRandomPosition(target, 60.f);
    this->sprite->setPosition(position);
    sf::FloatRect bounds = this->sprite->getLocalBounds();
    this->sprite->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

// Constructors and Destructors
Enemies::Enemies(const char *src, sf::RenderWindow &window, Hero *hero)
{
    this->initVariables();
    this->initSprite(src, window);
    this->hero = hero;
}

Enemies::~Enemies()
{
    delete this->texture;
    delete this->sprite;
}

// Public functions
void Enemies::update(sf::RenderWindow &window)
{
    this->moveTowardsHero();
}

void Enemies::render(sf::RenderWindow &window)
{
    window.draw(*this->sprite);
}

void Enemies::moveTowardsHero()
{
    sf::Vector2f heroPos = this->hero->getPosition();
    sf::Vector2f enemyPos = this->sprite->getPosition();
    sf::Vector2f direction = heroPos - enemyPos;

    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    if (length != 0)
    {
        direction /= length;
        float speed = .4f; // Speed of the enemy
        this->sprite->move(direction * speed);
    }
}