#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>
#include <cmath>
#include <algorithm>

class Base
{
private:
    std::vector<sf::Texture*> textures;
    sf::Sprite *sprite;
    Attribute *life;
    Attribute *regenRate;

    sf::Clock regenClock;
    
    // int regenerationRate;
    void initAttributes();
    void initVariables();
    void initSprite(const std::vector<const char*>& srcs, sf::RenderWindow &window);

public:
    Base(const std::vector<const char*>& srcs, sf::RenderWindow &window);
    ~Base();

    int getLife();
    int getMaxLife();
    int getRate();
    sf::FloatRect getArea();

    void damage(int value);
    bool collision(sf::FloatRect rect);

    void regenerate();
    void update();
    void updateSprite();

    void render(sf::RenderWindow &window);
};

#endif