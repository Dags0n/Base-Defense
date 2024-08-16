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

void Drop::initArea()
{
  area = this->sprite->getGlobalBounds();
}

// Constructors and Destructors
Drop::Drop(const char *src, sf::Vector2f position)
{
  this->initVariables();
  this->initSprite(src, position);
  this->initArea();
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
    if (!this->sprite)
    {
        return sf::FloatRect();
    }

    sf::FloatRect spriteBounds = this->sprite->getGlobalBounds();

    sf::FloatRect currentArea;
    currentArea.width = area.width;
    currentArea.height = area.height;
    
    currentArea.left = spriteBounds.left + (spriteBounds.width - currentArea.width) / 2.0f;
    currentArea.top = spriteBounds.top + (spriteBounds.height - currentArea.height) / 2.0f;

    return currentArea;
}

sf::Clock &Drop::getClock()
{
  return this->clock;
}

float Drop::getLifeTime()
{
  return this->lifeTime;
}

// Setters
void Drop::setArea(sf::FloatRect newArea)
{
  this->area = newArea;
}
