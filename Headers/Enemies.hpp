#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <SFML/Graphics.hpp>
#include "Hero.hpp"
#include "Shot.hpp"

class Enemies
{
private:
    // Variables
    std::vector<sf::Texture *> textures;
    sf::Sprite *sprite;
    sf::Clock shotClock;
    float shotInterval;
    float enemySpeed;
    int currentTextureIndex = 0;
    float animationTime = 0.f;
    float timePerFrame = 0.15f;
    Hero *hero;

    // Init functions
    void initVariables(float enemySpeed);
    void initSprite(const std::vector<const char*>& srcs, sf::RenderTarget &target);
    void showCollisionBox(sf::RenderWindow &window);

public:
    // Constructors and Destructors
    Enemies(const std::vector<const char*>& srcs, sf::RenderWindow &window, Hero *hero, float enemySpeed);
    ~Enemies();

    // Public functions
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);
    void moveTowardsHero(float deltaTime);
    void updateWalkingAnimation(float deltaTime);

    Shot *shot(const std::string &src, const sf::Vector2f &destiny, Enemies *owner, float speed);

    // Getters
    sf::Clock &getShotClock();
    float getShotInterval();
    sf::FloatRect getArea();
};

#endif