#include "Kamikaze.hpp"

// Utility functions
sf::Vector2f generateRandomPositionKami(sf::RenderTarget &target, float margin = 0.f)
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
void Kamikaze::initVariables()
{
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
}

void Kamikaze::initSprite(const char *src, sf::RenderTarget &target)
{
    if (!this->texture->loadFromFile(src))
    {
    }
    this->sprite->setTexture(*this->texture);

    sf::Vector2f position = generateRandomPositionKami(target, 60.f);
    this->sprite->setPosition(position);
    sf::FloatRect bounds = this->sprite->getLocalBounds();
    this->sprite->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Kamikaze::showCollisionBox(sf::RenderWindow &window)
{
    sf::FloatRect shape = getArea();
    sf::RectangleShape hitbox(sf::Vector2f(shape.width, shape.height));

    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(2);
    hitbox.setPosition(shape.left, shape.top);

    window.draw(hitbox);
}

// Constructors and Destructors
Kamikaze::Kamikaze(const char *src, sf::RenderWindow &window, sf::FloatRect baseArea)
{
    this->initVariables();
    this->initSprite(src, window);
    this->baseArea = baseArea;
}

Kamikaze::~Kamikaze()
{
    delete this->texture;
    delete this->sprite;
}

// Public functions
void Kamikaze::update(sf::RenderWindow &window, float deltaTime)
{
    this->moveTowardsBase(deltaTime);
}

void Kamikaze::render(sf::RenderWindow &window)
{
    if (!this->sprite)
    {
        return;
    }
    window.draw(*this->sprite);
    //showCollisionBox(window);
}

void Kamikaze::moveTowardsBase(float deltaTime)
{
    sf::Vector2f basePos = sf::Vector2f(this->baseArea.left + this->baseArea.width / 2.f, this->baseArea.top + this->baseArea.height / 2.f);
    sf::Vector2f kamikazePos = this->sprite->getPosition();
    sf::Vector2f direction = basePos - kamikazePos;

    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    if (length != 0)
    {
        direction /= length;
        this->sprite->move(direction * this->speed * deltaTime);
    }
}

// Getters
sf::FloatRect Kamikaze::getArea() 
{
    if (!this->sprite) {
        return sf::FloatRect();
    }
    
    float reductionFactor = 0.6f;

    sf::FloatRect originalBounds = this->sprite->getGlobalBounds();
    sf::FloatRect reducedBounds = originalBounds;
    reducedBounds.width *= reductionFactor;
    reducedBounds.height *= reductionFactor;

    reducedBounds.left += (originalBounds.width - reducedBounds.width) / 2.0f;
    reducedBounds.top += (originalBounds.height - reducedBounds.height) / 2.0f;

    return reducedBounds;
}
