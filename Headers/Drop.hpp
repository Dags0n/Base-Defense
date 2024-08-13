#ifndef DROP_HPP
#define DROP_HPP

#include <SFML/Graphics.hpp>

class Drop
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
  Drop(const char *src, sf::Vector2f position);
  ~Drop();

  // Public functions
  void render(sf::RenderWindow &window);

  // Getters
  sf::FloatRect getArea();
  sf::Clock &getClock();
  float getLifeTime();
};

#endif