#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>

class Base
{
private:
    sf::Texture *texture;
    sf::Sprite *sprite;
    Attribute *life;
    Attribute *regenRate;

    sf::Clock regenClock;
    
    // int regenerationRate;
    void initAttributes();
    void initVariables();
    void initSprite(const char *src, sf::RenderWindow &window);

public:
    Base(const char *src, sf::RenderWindow &window);
    ~Base();

    int getLife();
    int getMaxLife();
    int getRate();
    sf::FloatRect getArea();

    void damage(int value);

    void regenerate();
    void update();
    void updateAppearance();

    void render(sf::RenderWindow &window);
};

#endif