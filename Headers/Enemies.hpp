#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <SFML/Graphics.hpp>
#include <Hero.hpp>

class Enemies
{
private:
    // Variables
    sf::Texture *texture;
    sf::Sprite *sprite;
    Hero *hero;
    float enemySpeed;

    // Init functions
    void initVariables();
    void initSprite(const char *src, sf::RenderTarget &target);

public:
    // Constructors and Destructors
    Enemies(const char *src, sf::RenderWindow &window, Hero *hero);
    ~Enemies();

    // Public functions
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);
    void moveTowardsHero(float deltaTime);
};

#endif