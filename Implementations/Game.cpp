#include "Game.hpp"

// Private functions
void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1280;

    this->window = new sf::RenderWindow(this->videoMode, "Base Defense", sf::Style::Default);
    this->window->setFramerateLimit(144);
    this->window->setPosition(sf::Vector2i(0, 0));
}

void Game::initBackgroundSprite()
{
    this->backgroundTexture = new sf::Texture();
    if (!this->backgroundTexture->loadFromFile("Assets/Image/background.jpeg"))
    {
    }
    this->backgroundSprite = new sf::Sprite();
    this->backgroundSprite->setTexture(*this->backgroundTexture);

    sf::Vector2u windowSize = this->window->getSize();
    sf::Vector2u textureSize = backgroundTexture->getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    backgroundSprite->setScale(scaleX, scaleY);
}

void Game::initMenu()
{
    this->state = GameState::Menu;
    this->difficulty = Difficulty::Normal;
    this->menu = new Menu(*this->window);
}

void Game::initMusic()
{
    this->music = new sf::Music();
    if (!this->music->openFromFile("Assets/Music/background.wav"))
    {
    }
    this->music->setVolume(10);
    this->music->setLoop(true);
}

void Game::initFont()
{
    this->font = new sf::Font();
    if (!this->font->loadFromFile("Fonts/PressStart2P-Regular.ttf"))
    {
    }
}

void Game::initPauseMessage()
{
    this->pauseMessage = new sf::Text();
    this->pauseMessage->setFont(*this->font);
    this->pauseMessage->setString("PAUSE");
    this->pauseMessage->setCharacterSize(100);
    this->pauseMessage->setFillColor(sf::Color::White);
    sf::FloatRect textRect = this->pauseMessage->getLocalBounds();
    this->pauseMessage->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    sf::Vector2u windowSize = this->window->getSize();
    this->pauseMessage->setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
}

void Game::initHero()
{
    this->hero = new Hero((char *)"Assets/Image/spaceship_dark.png", *this->window);
}

void Game::initBase()
{
    std::vector<const char *> textures =
        {
            "Assets/Image/base.png",
            "Assets/Image/base_status1.png",
            "Assets/Image/base_status2.png",
            "Assets/Image/base_status3.png",
            "Assets/Image/base_status4.png"};

    this->base = new Base(textures, *this->window);
}

void Game::initBoss()
{
    std::vector<const char *> textures =
        {
            "Assets/Image/boss3.png",
            "Assets/Image/boss2.png",
            "Assets/Image/boss1.png",
            "Assets/Image/boss5.png",
            "Assets/Image/boss4.png",
        };

    this->boss = new Boss(textures, *this->window, this->hero, 50.f);
}

void Game::initEnemies()
{
    std::vector<const char*> textures = 
    {
        "Assets/Image/enemy.png",
        "Assets/Image/enemy1.png",
        "Assets/Image/enemy2.png"
    };

    this->enemies.push_back(new Enemies(textures, *this->window, this->hero, enemySpeed));
}

void Game::initKamikazes()
{
    std::vector<const char*> textures = 
    {
        "Assets/Image/kamikaze.png",
        "Assets/Image/kamikaze1.png",
        "Assets/Image/kamikaze2.png",
        "Assets/Image/kamikaze3.png",
    };

    this->kamikazes.push_back(new Kamikaze(textures, *this->window, this->base->getArea()));
}

void Game::initStatusBar()
{
    sf::Vector2f lifeSize = sf::Vector2f(250, 20);
    sf::Vector2i lifePos = sf::Vector2i(10, 20);
    int maxLife = this->hero->getMaxLife();
    int currentLife = this->hero->getLife();
    sf::Color color = sf::Color::Blue;
    sf::Color background = sf::Color::White;
    this->life = new StatusBar(lifeSize, lifePos, maxLife, currentLife, color, background, "Life: ");

    sf::Vector2f ammunitionSize = sf::Vector2f(200, 10);
    sf::Vector2i ammunitionPos = sf::Vector2i(10, 60);
    int maxAmmunition = this->hero->getMaxAmmunition();
    int currentAmmunition = this->hero->getAmmunition();
    color = sf::Color::Cyan;
    this->ammunition = new StatusBar(ammunitionSize, ammunitionPos, maxAmmunition, currentAmmunition, color, background, "Ammunition: ");

    sf::Vector2f baseSize = sf::Vector2f(400, 20);
    sf::Vector2i basePos = sf::Vector2i(this->window->getSize().x - 430, this->window->getSize().y - 40);
    int maxBaseLife = this->base->getMaxLife();
    int currentBaseLife = this->base->getLife();
    color = sf::Color::Green;
    this->baseLife = new StatusBar(baseSize, basePos, maxBaseLife, currentBaseLife, color, background, "Base: ");
}

void Game::initBossStatusBar()
{
    sf::Vector2f bossSize = sf::Vector2f(400, 20);
    sf::Vector2i bossPos = sf::Vector2i(30, this->window->getSize().y - 40);
    int maxBossLife = this->boss->getMaxLife();
    int currentBossLife = this->boss->getLife();
    sf::Color color = sf::Color::Red;
    sf::Color background = sf::Color::White;
    this->bossLife = new StatusBar(bossSize, bossPos, maxBossLife, currentBossLife, color, background, "Boss: ");
}

void Game::initKillScore()
{
    this->killScore = new sf::Text();
    this->killScore->setFont(*this->font);
    this->killScore->setString("Kills: " + std::to_string(kills));
    this->killScore->setCharacterSize(10);
    this->killScore->setFillColor(sf::Color::White);
    sf::Vector2u windowSize = this->window->getSize();
    this->killScore->setPosition(windowSize.x - 120, 10);
}

Drop *Game::makeAmmuDrop(sf::Vector2f position)
{
    Drop *ammu = new Drop("Assets/Image/ammo.png", position);

    sf::FloatRect originalBounds = ammu->getArea();
    sf::FloatRect reducedBounds = originalBounds;
    reducedBounds.width *= 0.715f;
    reducedBounds.height *= 0.8f;

    ammu->setArea(reducedBounds);
    return ammu;
}

Drop *Game::makeLifeDrop(sf::Vector2f position)
{
    Drop *life = new Drop("Assets/Image/life.png", position);

    sf::FloatRect originalBounds = life->getArea();
    sf::FloatRect reducedBounds = originalBounds;
    reducedBounds.width *= 0.70f;
    reducedBounds.height *= 0.715f;

    life->setArea(reducedBounds);
    return life;
}

// Constructors and Destructors
Game::Game()
{
    this->initWindow();
    this->initBackgroundSprite();
    this->initMenu();
    this->initMusic();
    this->initFont();
    this->initPauseMessage();
    this->initHero();
    this->initBase();
    if (this->music)
    {
        this->music->play();
    }
    this->initStatusBar();
    this->initKillScore();
}

Game::~Game()
{
    delete this->window;
    delete this->backgroundTexture;
    delete this->backgroundSprite;
    delete this->menu;
    delete this->music;
    delete this->hero;
    delete this->base;
    delete this->life;
    delete this->ammunition;
    delete this->font;
    delete this->pauseMessage;
    delete this->baseLife;
    for (auto *enemy : this->enemies)
    {
        delete enemy;
    }
    for (auto *shot : this->heroShots)
    {
        delete shot;
    }
    for (auto *shot : this->enemyShots)
    {
        delete shot;
    }
    for (auto *shot : this->bossShots)
    {
        delete shot;
    }
    for (auto *ammoDrop : this->ammoDrops)
    {
        delete ammoDrop;
    }
    for (auto *lifeDrop : this->lifeDrops)
    {
        delete lifeDrop;
    }
    for (auto *kamikaze : this->kamikazes)
    {
        delete kamikaze;
    }
    delete this->killScore;
    if (bossSpawned)
    {
        delete this->boss;
        delete this->bossLife;
    }
}

// Accesors
bool Game::running()
{
    return this->window->isOpen();
}

// Update
void Game::pollEvents()
{
    while (this->window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            if (event.key.code == sf::Keyboard::Space)
            {
                state = state == GameState::Playing ? GameState::Paused : GameState::Playing;
            }
            if (event.key.code == sf::Keyboard::Q)
            {
                if (state == GameState::Playing)
                {
                    qKeyPressed = true;
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (this->event.mouseButton.button == sf::Mouse::Right)
            {
                this->hero->setDestiny(sf::Mouse::getPosition(*this->window));
            }
            break;
        default:
            break;
        }
        menu->handleInput(event, state, difficulty, *this->window);
    }
}

void Game::garbageRemover()
{
    for (auto it = this->heroShots.begin(); it != this->heroShots.end();)
    {
        if ((*it)->isOutOfWindow(*this->window))
        {
            delete *it;
            this->heroShots.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (auto it = this->enemyShots.begin(); it != this->enemyShots.end();)
    {
        if ((*it)->isOutOfWindow(*this->window))
        {
            delete *it;
            this->enemyShots.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (auto it = this->bossShots.begin(); it != this->bossShots.end();)
    {
        if ((*it)->isOutOfWindow(*this->window))
        {
            delete *it;
            this->bossShots.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void Game::updateDifficulty()
{
    if (kills % 3 == 0 && kills != 0)
    {
        enemySpawnInterval -= 0.1f;
        if (enemySpawnInterval < .4f)
        {
            enemySpawnInterval = .4f;
        }
    }
}

void Game::updateHeroShotCollision()
{
    for (auto it = this->heroShots.begin(); it != this->heroShots.end();)
    {
        for (auto *enemy : this->enemies)
        {
            if ((*it)->getArea().intersects(enemy->getArea()))
            {
                if (rand() % 100 < 40)
                {
                    sf::FloatRect bounds = enemy->getArea();
                    float dropX = bounds.left + bounds.width / 2;
                    float dropY = bounds.top + bounds.height / 2;
                    sf::Vector2f drop = sf::Vector2f(dropX - 25, dropY - 25);

                    if (rand() % 100 < 70)
                    {
                        this->ammoDrops.push_back(makeAmmuDrop(drop));
                    }
                    else
                    {
                        this->lifeDrops.push_back(makeLifeDrop(drop));
                    }
                }

                this->kills++;
                delete *it;
                this->heroShots.erase(it);

                delete enemy;
                this->enemies.erase(std::remove(this->enemies.begin(), this->enemies.end(), enemy), this->enemies.end());

                this->updateDifficulty();
                break;
            }
        }
        if (it != this->heroShots.end())
        {
            it++;
        }
    }
}

void Game::updateEnemyShotCollision()
{
    for (auto it = this->enemyShots.begin(); it != this->enemyShots.end();)
    {
        bool removed = false;

        if (this->base->collision((*it)->getArea()))
        {
            delete *it;
            this->enemyShots.erase(it);
            this->base->damage(5);
            removed = true;
        }
        else
        {
            if ((*it)->getArea().intersects(this->hero->getArea()))
            {
                delete *it;
                this->enemyShots.erase(it);
                this->hero->damage(5);
                removed = true;
                break;
            }
        }

        if (!removed)
        {
            ++it;
        }
    }
}

void Game::updateKamikazeShotCollision()
{
    for (auto it = this->kamikazes.begin(); it != this->kamikazes.end();)
    {
        for (auto *shot : this->heroShots)
        {
            if ((*it)->getArea().intersects(shot->getArea()))
            {
                this->kills++;

                if (rand() % 100 < 40)
                {
                    sf::FloatRect bounds = (*it)->getArea();
                    float dropX = bounds.left + bounds.width / 2;
                    float dropY = bounds.top + bounds.height / 2;
                    sf::Vector2f drop = sf::Vector2f(dropX - 25, dropY - 25);

                    if (rand() % 100 < 70)
                    {
                        this->ammoDrops.push_back(makeAmmuDrop(drop));
                    }
                    else
                    {
                        this->lifeDrops.push_back(makeLifeDrop(drop));
                    }
                }

                delete *it;
                it = this->kamikazes.erase(it);

                delete shot;
                this->heroShots.erase(std::remove(this->heroShots.begin(), this->heroShots.end(), shot), this->heroShots.end());
                break;
            }
        }
        if (it != this->kamikazes.end())
        {
            it++;
        }
    }
}

void Game::updateBaseEnemyCollision()
{
    for (auto it = this->enemies.begin(); it != this->enemies.end();)
    {
        if (this->base->collision((*it)->getArea()))
        {
            delete *it;
            it = this->enemies.erase(it);
            this->base->damage(10);
        }
        else
        {
            ++it;
        }
    }
}

void Game::updateBaseKamikazeCollision()
{
    for (auto it = this->kamikazes.begin(); it != this->kamikazes.end();)
    {
        if (this->base->collision((*it)->getArea()))
        {
            delete *it;
            it = this->kamikazes.erase(it);
            this->base->damage(10);
        }
        else
        {
            ++it;
        }
    }
}

void Game::updateHeroKamikazeCollision()
{
    for (auto it = this->kamikazes.begin(); it != this->kamikazes.end();)
    {
        if ((*it)->getArea().intersects(this->hero->getArea()))
        {
            delete *it;
            it = this->kamikazes.erase(it);
            this->hero->damage(20);
        }
        else
        {
            ++it;
        }
    }
}

void Game::updateHeroCollectsAmmo()
{
    for (auto it = this->ammoDrops.begin(); it != this->ammoDrops.end();)
    {
        bool removed = false;

        if ((*it)->getArea().intersects(this->hero->getArea()))
        {
            delete *it;
            it = this->ammoDrops.erase(it);

            this->hero->rechargeAmmunition(10);
            removed = true;
            break;
        }

        if (!removed)
        {
            ++it;
        }
    }
}

void Game::updateHeroCollectsLife()
{
    for (auto it = this->lifeDrops.begin(); it != this->lifeDrops.end();)
    {
        bool removed = false;

        if ((*it)->getArea().intersects(this->hero->getArea()))
        {
            delete *it;
            it = this->lifeDrops.erase(it);

            this->hero->rechargeLife(10);
            removed = true;
            break;
        }

        if (!removed)
        {
            ++it;
        }
    }
}

void Game::updateEnemyFriendlyFire()
{
    for (auto it = this->enemyShots.begin(); it != this->enemyShots.end();)
    {
        bool removed = false;
        for (auto enemyIt = this->enemies.begin(); enemyIt != this->enemies.end();)
        {
            if ((*it)->getArea().intersects((*enemyIt)->getArea()) && *enemyIt != (*it)->getOwner())
            {
                delete *it;
                it = this->enemyShots.erase(it);
                removed = true;

                delete *enemyIt;
                enemyIt = this->enemies.erase(enemyIt);
                break;
            }
            else
            {
                ++enemyIt;
            }
        }
        if (!removed)
        {
            ++it;
        }
    }
}

void Game::updateBossShotCollision()
{
    for (auto it = this->heroShots.begin(); it != this->heroShots.end();)
    {
        if ((*it)->getArea().intersects(this->boss->getArea()))
        {
            delete *it;
            it = this->heroShots.erase(it);
            if (difficulty == Difficulty::Impossible)
            {
                this->boss->damage(2);
            }
            else if (difficulty == Difficulty::Hard)
            {
                this->boss->damage(3);
            }
            else
            {
                this->boss->damage(4);
            }

            if (rand() % 100 < 15)
            {
                sf::FloatRect bounds = boss->getArea();
                float dropX = bounds.left + bounds.width / 2;
                float dropY = bounds.top + bounds.height / 2;
                sf::Vector2f drop = sf::Vector2f(dropX - 25, dropY - 25);

                if (rand() % 100 < 70)
                {
                    this->ammoDrops.push_back(makeAmmuDrop(drop));
                }
                else
                {
                    this->lifeDrops.push_back(makeLifeDrop(drop));
                }
            }

        }
        else
        {
            ++it;
        }
    }
}

void Game::updateBossHeroCollision(float deltaTime)
{
    if (lastBossCollision < bossDamageCooldown) {
        lastBossCollision += deltaTime;
    }

    if (this->boss->getArea().intersects(this->hero->getArea()) && lastBossCollision >= bossDamageCooldown)
    {
        this->hero->damage(20);
        lastBossCollision = 0;
    }
}

void Game::updateBossBaseCollision(float deltaTime)
{
    if (lastBossCollision < bossDamageCooldown) {
        lastBossCollision += deltaTime;
    }

    if (this->base->collision(this->boss->getArea()) && lastBossCollision >= bossDamageCooldown)
    {
        this->base->damage(10);
        lastBossCollision = 0;
    }
}

void Game::updateBossShotHeroCollision()
{
    for (auto it = this->bossShots.begin(); it != this->bossShots.end();)
    {
        if ((*it)->getArea().intersects(this->hero->getArea()))
        {
            delete *it;
            it = this->bossShots.erase(it);
            this->hero->damage(15);
        }
        else
        {
            ++it;
        }
    }
}

void Game::updateBossShotBaseCollision()
{
    for (auto it = this->bossShots.begin(); it != this->bossShots.end();)
    {
        if (this->base->collision((*it)->getArea()))
        {
            delete *it;
            it = this->bossShots.erase(it);
            this->base->damage(10);
        }
        else
        {
            ++it;
        }
    }
}

void Game::expiresDrops(std::vector<Drop *> &drops)
{
    for (auto *drop : drops)
    {
        if (drop->getClock().getElapsedTime().asSeconds() >= drop->getLifeTime())
        {
            delete drop;
            drops.erase(std::remove(drops.begin(), drops.end(), drop), drops.end());
        }
    }
}

void Game::resetGame()
{
    for (auto *enemy : this->enemies)
    {
        delete enemy;
    }
    this->enemies.clear();

    for (auto *kamikaze : this->kamikazes)
    {
        delete kamikaze;
    }
    this->kamikazes.clear();

    for (auto *shot : this->heroShots)
    {
        delete shot;
    }
    this->heroShots.clear();

    for (auto *shot : this->enemyShots)
    {
        delete shot;
    }
    this->enemyShots.clear();

    for (auto *shot : this->bossShots)
    {
        delete shot;
    }
    this->bossShots.clear();

    for (auto *ammoDrop : this->ammoDrops)
    {
        delete ammoDrop;
    }
    this->ammoDrops.clear();

    for (auto *lifeDrop : this->lifeDrops)
    {
        delete lifeDrop;
    }
    this->lifeDrops.clear();

    if (bossSpawned)
    {
        delete this->boss;
        delete this->bossLife;
        bossSpawned = false;
    }

    this->kills = 0;

    this->hero->reset(*this->window);
    this->base->reset();
}

void Game::gameOver()
{
    if (this->hero->getLife() <= 0 || this->base->getLife() <= 0)
    {
        state = GameState::GameOver;
        this->resetGame();
    }

    if (bossSpawned) {
        if (this->boss->getLife() <= 0)
        {
            state = GameState::Win;
            this->resetGame();
        }
    }
}

void Game::update()
{
    sf::Time deltaTime = clock.restart();
    float deltaTimeSeconds = deltaTime.asSeconds();
    this->pollEvents();

    if (state == GameState::Playing)
    {
        // Update stats
        this->hero->update(*this->window, deltaTimeSeconds);
        this->life->update(this->hero->getLife());
        this->ammunition->update(this->hero->getAmmunition());
        this->base->update(this->regenRate);
        this->baseLife->update(this->base->getLife());
        this->killScore->setString("Kills: " + std::to_string(kills));

        for (auto *shot : this->heroShots)
        {
            shot->update(deltaTimeSeconds);
        }

        if (kills < 50) { 
            for (auto *enemy : this->enemies)
            {
                enemy->update(*this->window, deltaTimeSeconds);
            }

            for (auto *kamikaze : this->kamikazes)
            {
                kamikaze->update(*this->window, deltaTimeSeconds);
            }

            for (auto *shot : this->enemyShots)
            {
                shot->update(deltaTimeSeconds);
            }

            // Spawn enemies
            if (enemySpawnClock.getElapsedTime().asSeconds() >= enemySpawnInterval)
            {
                this->initEnemies();
                enemySpawnClock.restart();
            }

            // Spawn kamikazes
            if (kamikazeSpawnClock.getElapsedTime().asSeconds() >= 5.0f)
            {
                this->initKamikazes();
                kamikazeSpawnClock.restart();
            }

            // Enemy shots
            for (auto *enemy : this->enemies)
            {
                if (enemy->getShotClock().getElapsedTime().asSeconds() >= enemy->getShotInterval())
                {
                    auto shot = enemy->shot("Assets/Image/enemy_shot.png", this->hero->getPosition(), enemy, 300.f);
                    if (shot != nullptr)
                    {
                        this->enemyShots.push_back(shot);
                    }
                    enemy->getShotClock().restart();
                }
            }
        } else if (kills == 50 && !bossSpawned) {
            this->initBoss();
            bossSpawned = true;
            
            this->initBossStatusBar();

            for (auto *enemy : this->enemies)
            {
                delete enemy;
            }
            this->enemies.clear();

            for (auto *kamikaze : this->kamikazes)
            {
                delete kamikaze;
            }
            this->kamikazes.clear();

            for (auto *shot : this->enemyShots)
            {
                delete shot;
            }
            this->enemyShots.clear();
        }

        // Update Boss
        if (bossSpawned)
        {
            this->boss->update(*this->window, deltaTimeSeconds);
            this->bossLife->update(this->boss->getLife());
            this->updateBossShotCollision();
            this->updateBossHeroCollision(deltaTimeSeconds);
            this->updateBossBaseCollision(deltaTimeSeconds);

            // Boss shots
            if (this->boss->getShotClock().getElapsedTime().asSeconds() >= this->boss->getShotInterval())
            {
                auto shot = this->boss->shot("Assets/Image/enemy_shot.png", this->hero->getPosition());
                if (shot != nullptr)
                {
                    this->bossShots.push_back(shot);
                }
                this->boss->getShotClock().restart();
            }

            for (auto *shot : this->bossShots)
            {
                shot->update(deltaTimeSeconds);
            }

            this->updateBossShotHeroCollision();
            this->updateBossShotBaseCollision();
        }

        if (lastHeroShot < heroShotCooldown)
        {
            lastHeroShot += deltaTimeSeconds;
        }

        if (qKeyPressed && lastHeroShot >= heroShotCooldown)
        {
            auto shot = this->hero->shot("Assets/Image/hero_shot.png", (sf::Vector2f)sf::Mouse::getPosition(*this->window));
            
            if (shot != nullptr)
            {
                this->heroShots.push_back(shot);
                lastHeroShot = 0;
            }

            qKeyPressed = false;
        }

        // Expire drops
        this->expiresDrops(this->ammoDrops);
        this->expiresDrops(this->lifeDrops);

        this->garbageRemover();

        // Collisions
        this->updateHeroShotCollision();
        this->updateEnemyShotCollision();
        this->updateKamikazeShotCollision();
        this->updateHeroKamikazeCollision();
        this->updateHeroCollectsAmmo();
        this->updateHeroCollectsLife();
        this->updateBaseEnemyCollision();
        this->updateBaseKamikazeCollision();
        this->updateEnemyFriendlyFire();

        // Game Over
        this->gameOver();
    }
    else
    {
        switch (difficulty)
        {
        case Difficulty::Normal:
            enemySpeed = 80.f;
            enemySpawnInterval = 2.0f;
            break;
        case Difficulty::Hard:
            enemySpeed = 100.f;
            enemySpawnInterval = 1.5f;
            break;
        case Difficulty::Impossible:
            enemySpeed = 120.f;
            enemySpawnInterval = 1.0f;
            break;
        default:
            enemySpeed = 80.f;
            enemySpawnInterval = 2.5f;
            break;
        }
    }
}

// Render
void Game::render()
{

    this->window->clear(sf::Color::Black);

    menu->draw(*this->window, state);

    if (state == GameState::Playing || state == GameState::Paused)
    {
        // Draw Objects
        this->window->draw(*this->backgroundSprite);

        // Plan 0
        this->base->render(*this->window);

        // Plan 1
        for (auto *shot : this->heroShots)
        {
            shot->render(*this->window);
        }

        for (auto *shot : this->enemyShots)
        {
            shot->render(*this->window);
        }

        for (auto *shot : this->bossShots)
        {
            shot->render(*this->window);
        }

        // Plan 2
        for (auto *enemy : this->enemies)
        {
            enemy->render(*this->window);
        }
        for (auto *kamikaze : this->kamikazes)
        {
            kamikaze->render(*this->window);
        }
        this->hero->render(*this->window);

        // Plan 3
        for (auto *ammoDrop : this->ammoDrops)
        {
            ammoDrop->render(*this->window);
        }

        for (auto *lifeDrop : this->lifeDrops)
        {
            lifeDrop->render(*this->window);
        }

        if (bossSpawned)
        {
            this->boss->render(*this->window);
        }

        // Plan 4
        this->life->render(*this->window);
        this->ammunition->render(*this->window);
        this->baseLife->render(*this->window);
        if (bossSpawned)
        {
            this->bossLife->render(*this->window);
        }
        this->window->draw(*this->killScore);

        if (state == GameState::Paused)
        {
            this->window->draw(*this->pauseMessage);
        }
    }
    // End draw

    this->window->display();
}