#ifndef SHOT_HPP
#define SHOT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

class Enemies;

class Shot
{
private:
    // Variables
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Vector2f direction;
    float speed;
    Enemies *owner;

    // Init
    void initVariables(const sf::Vector2f &currentPosition, const sf::Vector2f &destiny);
    void initShot(const std::string &src, const sf::Vector2f &currentPosition);

public:
    // Constructors and Destructors
    Shot(const std::string &src, const sf::Vector2f &currentPosition, const sf::Vector2f &destiny, Enemies *owner = nullptr, float speed = 600.f);
    ~Shot();

    // Getters and setters
    sf::FloatRect getArea();
    Enemies *getOwner();

    // Update
    void updatePosition(float deltaTime);
    void update(float deltaTime);

    // Render
    void render(sf::RenderWindow &window) const;

    bool isOutOfWindow(sf::RenderWindow &window) const;
};

#endif