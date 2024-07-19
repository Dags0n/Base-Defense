#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
#include "Attribute.hpp"

class Hero {
private:
    //Variables
    sf::Texture* texture;
    sf::Sprite* sprite;
    Attribute* life;
    Attribute* ammunition;
    sf::Vector2<int> position;
    sf::Vector2<int> sightPosition;

    //Private functions
    void initVariables();
    void initAttributes();
    void initSprite(const char* src);

public:

    //Constructors and Destructors
    Hero(const char* src);
    ~Hero();

    //Getters and Setters
    sf::Sprite& getSprite();
    

};

#endif