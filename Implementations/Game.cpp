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

void Game::initMusic()
{
    this->music = new sf::Music();
    if (!this->music->openFromFile("Assets/Music/background.wav"))
    {
    }
    this->music->setLoop(true);
}

void Game::initFont()
{
    this->SpaceMono = new sf::Font();
    if (!this->SpaceMono->loadFromFile("Fonts/PressStart2P-Regular.ttf"))
    {
    }
}

void Game::initPauseMenssage()
{
    this->pauseMessage = new sf::Text();
    this->pauseMessage->setFont(*this->SpaceMono);
    this->pauseMessage->setString("PAUSE");
    this->pauseMessage->setCharacterSize(100);
    this->pauseMessage->setFillColor(sf::Color::Cyan);
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
    this->base = new Base((char *)"Assets/Image/base.png", 100, 1, *this->window);
}

void Game::initEnemies()
{
    this->enemies.push_back(new Enemies((char *)"Assets/Image/enemy.png", *this->window, this->hero));
}

void Game::initStatusBar()
{
    sf::Vector2f lifeSize = sf::Vector2f(250, 20);
    sf::Vector2i lifePos = sf::Vector2i(10, 10);
    int maxLife = this->hero->getMaxLife();
    int currentLife = this->hero->getLife();
    sf::Color color = sf::Color::Blue;
    sf::Color background = sf::Color::White;
    this->life = new StatusBar(lifeSize, lifePos, maxLife, currentLife, color, background);

    sf::Vector2f ammunitionSize = sf::Vector2f(200, 10);
    sf::Vector2i ammunitionPos = sf::Vector2i(10, 40);
    int maxAmmunition = this->hero->getMaxLife();
    int currentAmmunition = this->hero->getLife();
    color = sf::Color::Cyan;
    this->ammunition = new StatusBar(ammunitionSize, ammunitionPos, maxAmmunition, currentAmmunition, color, background);
}

// Constructors and Destructors
Game::Game()
{
    this->initWindow();
    this->initMusic();
    this->initFont();
    this->initPauseMenssage();
    this->initHero();
    this->initBase();
    for (int i = 0; i < 3; i++)
    {
        this->initEnemies();
    }
    if (this->music)
    {
        this->music->play();
    }
    this->initStatusBar();
}

Game::~Game()
{
    delete this->window;
    delete this->music;
    delete this->hero;
    delete this->base;
    delete this->life;
    delete this->ammunition;
    for (auto *enemy : this->enemies)
    {
        delete enemy;
    }
}

// Accesors
bool Game::running()
{
    return this->window->isOpen();
}

// Public function
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
                this->isPaused = !this->isPaused;
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
    }
}

void Game::update()
{
    sf::Time deltaTime = clock.restart();
    float deltaTimeSeconds = deltaTime.asSeconds();
    this->pollEvents();

    if (!isPaused)
    {
        this->hero->update(*this->window, deltaTimeSeconds);
        this->life->update(this->hero->getLife());
        this->ammunition->update(this->hero->getAmmunition());

        // Spawn enemies
        if (enemySpawnClock.getElapsedTime().asSeconds() >= enemySpawnInterval)
        {
            this->initEnemies();
            enemySpawnClock.restart(); // Restart the clock
        }

        // Update enemies
        for (auto *enemy : this->enemies)
        {
            enemy->update(*this->window);
        }
    }
}

void Game::render()
{

    this->window->clear(sf::Color::Black);

    // Draw Objects
    this->base->render(*this->window);
    this->hero->render(*this->window);

    for (auto *enemy : this->enemies)
    {
        enemy->render(*this->window);
    }

    this->life->render(*this->window);
    this->ammunition->render(*this->window);

    if (isPaused)
    {
        this->window->draw(*this->pauseMessage);
    }
    // End draw

    this->window->display();
}