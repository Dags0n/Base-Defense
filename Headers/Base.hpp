#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>

class Base
{
private:
    sf::Texture *texture;
    sf::Sprite *sprite;
    int score;
    int maxScore;
    int regenerationRate;

    void initVariables();
    void initSprite(const char *src, sf::RenderWindow &window);

public:
    Base(const char *src, int initialScore, int rate, sf::RenderWindow &window);
    ~Base();

    int getScore();
    sf::FloatRect getArea();

    void takeDamage(int damage);
    void regenerate(int value);
    bool isDestroyed();
    void updateAppearance();

    void render(sf::RenderWindow &window);
};

#endif