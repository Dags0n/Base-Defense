#ifndef HERO_H
#define HERO_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Attribute.hpp"
#include "Shot.hpp"

class Hero
{
private:
    // Variables
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::SoundBuffer shotBuffer;
    sf::Sound shotSound;
    Attribute *life;
    Attribute *ammunition;
    sf::Vector2i destiny;
    float speed;

    // Init functions
    void initVariables();
    void initShotSound();
    void initAttributes();
    void initSprite(const char *src, sf::RenderWindow &window);

public:
    // Constructors and Destructors
    Hero(const char *src, sf::RenderWindow &window);
    ~Hero();

    // Getters and Setters
    sf::Vector2f getMouseDirection(sf::RenderWindow &window);
    sf::Vector2f getDestinyDirection();
    sf::Vector2f getPosition();
    int getLife();
    int getMaxLife();
    int getAmmunition();
    int getMaxAmmunition();
    void setDestiny(sf::Vector2i destiny);
    std::vector<sf::FloatRect> getArea();
    void rechargeAmmunition(int value);
    void rechargeLife(int value);

    // Actions
    Shot *shot(const std::string &src, const sf::Vector2f &destiny);
    void damage(int points);

    // Update
    void updateRotation(sf::Vector2f direction);
    void updatePosition(sf::Vector2f direction, float deltaTime);
    void update(sf::RenderWindow &window, float deltaTime);

    // Render
    void render(sf::RenderWindow &window);
};

#endif