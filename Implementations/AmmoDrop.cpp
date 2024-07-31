#include "AmmoDrop.hpp"

// Init functions
void AmmoDrop::initVariables()
{
  this->texture = new sf::Texture();
  this->sprite = new sf::Sprite();
  this->lifeTime = 8.f;
}

void AmmoDrop::initSprite(const char *src, sf::Vector2f position)
{
  if (!this->texture->loadFromFile(src))
  {
  }
  this->sprite->setTexture(*this->texture);

  this->sprite->setPosition(position);
}

// Constructors and Destructors
AmmoDrop::AmmoDrop(sf::Vector2f position)
{
  this->initVariables();
  this->initSprite("Assets/Image/ammo.png", position);
}

AmmoDrop::~AmmoDrop()
{
  delete this->texture;
  delete this->sprite;
}

// Public functions
void AmmoDrop::render(sf::RenderWindow &window)
{
  window.draw(*this->sprite);
}

// Getters
sf::FloatRect AmmoDrop::getArea()
{
  return this->sprite->getGlobalBounds();
}

sf::Clock &AmmoDrop::getClock()
{
  return this->clock;
}

float AmmoDrop::getLifeTime()
{
  return this->lifeTime;
}