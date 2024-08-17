#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <SFML/Graphics.hpp>
#include "Hero.hpp"
#include "Shot.hpp"

class Enemies
{
private:
    // Variables
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Clock shotClock;
    float shotInterval;
    float enemySpeed;
    Hero *hero;

    // Init functions
    void initVariables(float enemySpeed);
    void initSprite(const char *src, sf::RenderTarget &target);
    void showCollisionBox(sf::RenderWindow &window);

public:
    // Constructors and Destructors
    Enemies(const char *src, sf::RenderWindow &window, Hero *hero, float enemySpeed);
    ~Enemies();

    // Public functions
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);
    void moveTowardsHero(float deltaTime);

    Shot *shot(const std::string &src, const sf::Vector2f &destiny, Enemies *owner, float speed);

    // Getters
    sf::Clock &getShotClock();
    float getShotInterval();
    sf::FloatRect getArea();
};

#endif