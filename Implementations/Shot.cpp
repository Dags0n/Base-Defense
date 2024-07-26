#include "Shot.hpp"

// Init
void Shot::initVariables(const sf::Vector2f &currentPosition, const sf::Vector2f &destiny)
{
    this->speed = 250.f;
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();

    //Direction
    this->direction = destiny-currentPosition;
    float magnitude = std::sqrt(this->direction.x * this->direction.x + this->direction.y * this->direction.y);
    if (magnitude > 0.f) {
        this->direction /= magnitude;
    } else {
        this->direction = sf::Vector2f(0.f, 0.f);
    }

}

void Shot::initShot(const std::string &src, const sf::Vector2f &currentPosition)
{
    if (!this->texture->loadFromFile(src))
    {
    }
    this->sprite->setTexture(*this->texture);
    sf::FloatRect bounds = this->sprite->getLocalBounds();
    this->sprite->setOrigin(bounds.width / 2.f, bounds.height/2.f);
    this->sprite->setPosition(currentPosition);

    float angleRad = atan2(this->direction.y, this->direction.x);
    float angleDeg = (angleRad * (180.f / static_cast<float>(M_PI))) + 90.f;
    this->sprite->setRotation(angleDeg);
}

//Constructors and Destructors
Shot::Shot(const std::string &src, const sf::Vector2f &currentPosition, const sf::Vector2f &destiny)
{
    this->initVariables(currentPosition, destiny);
    this->initShot(src, currentPosition);
}

Shot::~Shot()
{
    delete this->texture;
    delete this->sprite;
}

//Update
void Shot::updatePosition(float deltaTime)
{
    this->sprite->move(this->direction * this->speed * deltaTime);
}

void Shot::update(float deltaTime)
{
    this->updatePosition(deltaTime);
}

//Render
void Shot::render(sf::RenderWindow &window) const
{
    window.draw(*this->sprite);
}