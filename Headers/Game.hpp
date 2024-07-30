#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
    std::vector<Shot *> heroShots;
    std::vector<Shot *> enemyShots;
    StatusBar *life;
    StatusBar *ammunition;
    StatusBar *baseLife;

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

    // Update
    void pollEvents();
    void garbageRemover();
    void updateHeroShotCollision();
    void updateEnemyShotCollision();
    void update();

    // Render
    void render();
};

#endif