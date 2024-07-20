#ifndef HERO_H
#define HERO_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Attribute.hpp"

class Hero {
private:
    //Variables
    sf::Texture* texture;
    sf::Sprite* sprite;
    Attribute* life;
    Attribute* ammunition;
    sf::Vector2<int> sightPosition;
    float speed;

    //Init functions
    void initVariables();
    void initAttributes();
    void initSprite(const char* src, sf::RenderWindow &window);

public:

    //Constructors and Destructors
    Hero(const char* src, sf::RenderWindow &window);
    ~Hero();

    //Public functions
    sf::Vector2f getMouseDirection(sf::RenderWindow &window);
    void updateRotation(sf::Vector2f direction);
    void updatePosition(sf::Vector2f direction, float deltaTime);
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);

};

#endif