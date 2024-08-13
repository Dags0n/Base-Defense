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
#include "AmmoDrop.hpp"

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
    sf::Font *font;
    sf::Text *pauseMessage;
    sf::Clock clock;
    sf::Clock enemySpawnClock;
    float enemySpawnInterval = 3.0f;
    bool isPaused = false;
    int kills = 0;

    // Game Objects
    Hero *hero;
    Base *base;
    std::vector<Enemies *> enemies;
    std::vector<Shot *> heroShots;
    std::vector<Shot *> enemyShots;
    std::vector<AmmoDrop *> ammoDrops;
    
    StatusBar *life;
    StatusBar *ammunition;
    StatusBar *baseLife;
    sf::Text *killScore;

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
    void initKillScore();

public:
    // Contructors and Destructors
    Game();
    ~Game();

    // Accesors
    bool running();

    // Update
    void pollEvents();
    void garbageRemover();
    void updateDifficulty();
    void updateHeroShotCollision();
    void updateEnemyShotCollision();
    void updateBaseEnemyCollision();
    void updateHeroCollectsDrop();
    void updateEnemyFriendlyFire();
    void gameOver();
    void update();

    // Render
    void render();
};

#endif