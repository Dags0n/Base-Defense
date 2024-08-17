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
  sf::FloatRect area;

  // Init functions
  void initVariables();
  void initSprite(const char *src, sf::Vector2f position);
  void initArea();
  void showCollisionBox(sf::RenderWindow &window);

public:
  // Constructors and Destructors
  Drop(const char *src, sf::Vector2f position);
  ~Drop();

  // Public functions
  void render(sf::RenderWindow &window);

  // Getters
  sf::FloatRect getArea();
  sf::Clock &getClock();
  float getLifeTime();

  // Setters
  void setArea(sf::FloatRect newArea);
};

#endif