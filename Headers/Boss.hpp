#ifndef BOSS_HPP
#define BOSS_HPP

#include <SFML/Graphics.hpp>
#include "Hero.hpp"
#include "Shot.hpp"
#include "Attribute.hpp"

class Boss
{
private:
    // Variables
    std::vector<sf::Texture *> textures;
    sf::Sprite *sprite;
    sf::Clock shotClock;
    float shotInterval;
    float bossSpeed = 50.f;
    int currentTextureIndex = 0;
    float animationTime = 0.f;
    float timePerFrame = 0.21f;
    Attribute *life;
    Hero *hero;

    // Init functions
    void initVariables(float bossSpeed);
    void initAttributes();
    void initSprite(const std::vector<const char*>& srcs, sf::RenderTarget &target);
    void showCollisionBox(sf::RenderWindow &window);

public:
    // Constructors and Destructors
    Boss(const std::vector<const char*>& srcs, sf::RenderWindow &window, Hero *hero, float enemySpeed);
    ~Boss();

    // Public functions
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);
    void moveTowardsHero(float deltaTime);
    void updateWalkingAnimation(float deltaTime);

    Shot *shot(const std::string &src, const sf::Vector2f &destiny);
    void damage(int points);

    // Getters
    sf::Clock &getShotClock();
    float getShotInterval();
    sf::FloatRect getArea();
    int getLife();
    int getMaxLife();
};

#endif