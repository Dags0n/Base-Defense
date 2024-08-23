#ifndef KAMIKAZE_HPP
#define KAMIKAZE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Kamikaze
{
private:
    // Variables
    std::vector<sf::Texture *> textures;
    sf::Sprite *sprite;
    sf::FloatRect baseArea;
    float speed = 200.f;
    int currentTextureIndex = 0;
    float animationTime = 0.f;
    float timePerFrame = 0.12f;

    // Init functions
    void initVariables();
    void initSprite(const std::vector<const char*>& srcs, sf::RenderTarget &target);
    void showCollisionBox(sf::RenderWindow &window);


public:
    // Constructors and Destructors
    Kamikaze(const std::vector<const char*>& srcs, sf::RenderWindow &window, sf::FloatRect baseArea);
    ~Kamikaze();

    // Public functions
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);
    void moveTowardsBase(float deltaTime);
    void updateWalkingAnimation(float deltaTime);
    
    // Getters
    sf::FloatRect getArea();
};

#endif
