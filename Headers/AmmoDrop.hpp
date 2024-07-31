#ifndef AMMODROP_HPP
#define AMMODROP_HPP

#include <SFML/Graphics.hpp>

class AmmoDrop
{
private:
  sf::Texture *texture;
  sf::Sprite *sprite;
  sf::Clock clock;
  float lifeTime;

public:
  // Init functions
  void initVariables();
  void initSprite(const char *src, sf::Vector2f position);

  // Constructors and Destructors
  AmmoDrop(sf::Vector2f position);
  ~AmmoDrop();

  // Public functions
  void render(sf::RenderWindow &window);

  // Getters
  sf::FloatRect getArea();
  sf::Clock &getClock();
  float getLifeTime();
};

#endif