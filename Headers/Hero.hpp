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
    sf::Vector2<int> sightPosition;

    //Init functions
    void initVariables();
    void initAttributes();
    void initSprite(const char* src, sf::RenderTarget &target);

public:

    //Constructors and Destructors
    Hero(const char* src, sf::RenderTarget &target);
    ~Hero();

    //Public functions
    void update(sf::RenderTarget &target);
    void render(sf::RenderTarget &target);

};

#endif