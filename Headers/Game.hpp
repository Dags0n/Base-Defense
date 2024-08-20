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
#include "Drop.hpp"
#include "Menu.hpp"
#include "State.hpp"
#include "Kamikaze.hpp"
#include "Boss.hpp"

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
    sf::Clock kamikazeSpawnClock;
    float enemySpawnInterval;
    float enemySpeed;
    float bossDamageCooldown = 1.0f;
    float lastBossCollision = 0.f;
    int kills = 0;

    GameState state;
    HeroType heroType;
    Difficulty difficulty;
    Menu *menu;

    // Game Objects
    Hero *hero;
    Base *base;
    Boss *boss;
    bool bossSpawned = false;
    std::vector<Enemies *> enemies;
    std::vector<Kamikaze *> kamikazes;
    std::vector<Shot *> heroShots;
    std::vector<Shot *> enemyShots;
    std::vector<Shot *> bossShots;
    std::vector<Drop *> ammoDrops;
    std::vector<Drop *> lifeDrops;

    StatusBar *life;
    StatusBar *ammunition;
    StatusBar *baseLife;
    sf::Text *killScore;

    // Private functions
    void initWindow();
    void initBackgroundSprite();
    void initMenu();
    void initMusic();
    void initFont();
    void initPauseMessage();
    void initHero();
    void initBase();
    void initBoss();
    void initEnemies();
    void initKamikazes();
    void initStatusBar();
    void initKillScore();

    Drop *makeAmmuDrop(sf::Vector2f position);
    Drop *makeLifeDrop(sf::Vector2f position);

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
    void updateKamikazeShotCollision();
    void updateBaseEnemyCollision();
    void updateBaseKamikazeCollision();
    void updateHeroKamikazeCollision();
    void updateHeroCollectsAmmo();
    void updateHeroCollectsLife();
    void updateEnemyFriendlyFire();
    void updateBossShotCollision();
    void updateBossHeroCollision(float deltaTime);
    void updateBossBaseCollision(float deltaTime);
    void updateBossShotHeroCollision();
    void updateBossShotBaseCollision();
    void expiresDrops(std::vector<Drop *> &drops);
    void gameOver();
    void update();

    // Render
    void render();
};

#endif