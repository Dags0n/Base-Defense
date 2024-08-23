#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>
#include <cmath>
#include <algorithm>

class Base
{
private:
    std::vector<sf::Texture *> textures;
    sf::Sprite *sprite;
    Attribute *life;

    sf::Clock regenClock;

    // int regenerationRate;
    void initAttributes();
    void initVariables();
    void initSprite(const std::vector<const char *> &srcs, sf::RenderWindow &window);
    void showCollisionBox(sf::RenderWindow &window);

public:
    Base(const std::vector<const char *> &srcs, sf::RenderWindow &window);
    ~Base();

    int getLife();
    int getMaxLife();
    sf::FloatRect getArea();

    void damage(int value);
    bool collision(sf::FloatRect rect);

    void regenerate(float regenRate);
    void update(float regenRate);
    void updateSprite();
    void reset();

    void render(sf::RenderWindow &window);
};

#endif