#include "Drop.hpp"

// Init functions
void Drop::initVariables()
{
  this->texture = new sf::Texture();
  this->sprite = new sf::Sprite();
  this->lifeTime = 8.f;
}

void Drop::initSprite(const char *src, sf::Vector2f position)
{
  if (!this->texture->loadFromFile(src))
  {
  }
  this->sprite->setTexture(*this->texture);

  this->sprite->setPosition(position);
}

// Constructors and Destructors
Drop::Drop(const char *src, sf::Vector2f position)
{
  this->initVariables();
  this->initSprite(src, position);
}

Drop::~Drop()
{
  delete this->texture;
  delete this->sprite;
}

// Public functions
void Drop::render(sf::RenderWindow &window)
{
  window.draw(*this->sprite);
}

// Getters
sf::FloatRect Drop::getArea()
{
  return this->sprite->getGlobalBounds();
}

sf::Clock &Drop::getClock()
{
  return this->clock;
}

float Drop::getLifeTime()
{
  return this->lifeTime;
}