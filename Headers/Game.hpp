#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Base.hpp"
#include "Hero.hpp"
#include "Enemies.hpp"

class Game
{
private:
    // Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Event event;
    sf::Music *music;
    sf::Clock clock;
    sf::Clock enemySpawnClock;
    float enemySpawnInterval = 3.0f;

    // Game Objects
    Hero *hero;
    Base *base;
    std::vector<Enemies *> enemies;

    // Private functions
    void initWindow();
    void initMusic();
    void initHero();
    void initBase();
    void initEnemies();

public:
    // Contructors and Destructors
    Game();
    ~Game();

    // Accesors
    bool running();

    // Public functions
    void pollEvents();
    void update();
    void render();
};

#endif