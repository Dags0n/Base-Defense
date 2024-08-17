#ifndef KAMIKAZE_HPP
#define KAMIKAZE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Kamikaze
{
private:
    // Variables
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::FloatRect baseArea;
    float speed = 200.f;

    // Init functions
    void initVariables();
    void initSprite(const char *src, sf::RenderTarget &target);
    void showCollisionBox(sf::RenderWindow &window);


public:
    // Constructors and Destructors
    Kamikaze(const char *src, sf::RenderWindow &window, sf::FloatRect baseArea);
    ~Kamikaze();

    // Public functions
    void update(sf::RenderWindow &window, float deltaTime);
    void render(sf::RenderWindow &window);
    void moveTowardsBase(float deltaTime);
    
    // Getters
    sf::FloatRect getArea();
};

#endif
