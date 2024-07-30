#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include "Base.hpp"
#include "Hero.hpp"
#include "Enemies.hpp"
#include "StatusBar.hpp"
#include "Shot.hpp"

class Game
{
private:
    // Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Texture *backgroundTexture;
    sf::Sprite *backgroundSprite;
    sf::Event event;
    sf::Music *music;
    sf::Font *SpaceMono;
    sf::Text *pauseMessage;
    sf::Clock clock;
    sf::Clock enemySpawnClock;
    float enemySpawnInterval = 3.0f;
    bool isPaused = false;

    // Game Objects
    Hero *hero;
    Base *base;
    std::vector<Enemies *> enemies;
    std::list<Shot *> heroShots;
    StatusBar *life;
    StatusBar *ammunition;

    // Private functions
    void initWindow();
    void initBackgroundSprite();
    void initMusic();
    void initFont();
    void initPauseMessage();
    void initHero();
    void initBase();
    void initEnemies();
    void initStatusBar();

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