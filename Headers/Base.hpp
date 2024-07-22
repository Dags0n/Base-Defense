#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>

class Base
{
private:
    sf::RectangleShape baseShape;
    int score;
    int maxScore;
    int regenerationRate;

public:
    Base(int initialScore, int rate, const sf::Vector2u windowSize);
    ~Base();

    void takeDamage(int damage);
    void regenerate(int value);
    void initCenterBase(const sf::Vector2u windowSize);

    bool isDestroyed();

    int getScore();
    sf::RectangleShape getShape();

    void updateAppearance();
};

#endif