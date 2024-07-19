#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>

class Base {
private:
    sf::RectangleShape baseShape;
    int score;
    int maxScore;
    int regenerationRate;

public:
    Base(int x, int y, int initialScore, int rate);
    ~Base();

    void takeDamage(int damage);
    void regenerate(int value);

    bool isDestroyed();

    int getScore();
    sf::RectangleShape getShape();

    void updateAppearance();
};

#endif