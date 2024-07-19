#include "Game.hpp"

//Private functions
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
    if (!this->music->openFromFile("Assets/Music/background.wav")) {
    }
    this->music->setLoop(true);
    
}

void Game::initHero()
{
    this->hero = new Hero((char*)"Assets/Image/spaceship_dark.png", *this->window);
}

void Game::initBase() 
{
    this->base = new Base(100, 1, this->window->getSize());
}

//Constructors and Destructors
Game::Game()
{
    this->initWindow();
    this->initMusic();
    this->initHero();
    this->initBase();
    if (this->music) {
        this->music->play();
    }
}

Game::~Game()
{
    delete this->window;
    delete this->music;
    delete this->hero;
    delete this->base;
}

//Accesors
bool Game::running()
{
    return this->window->isOpen();
}

// Public function
void Game::pollEvents()
{
    while(this->window->pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
                break;
            default: break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
    this->hero->update(*this->window);
}

void Game::render()
{

    this->window->clear(sf::Color::Black);

    this->hero->render(*this->window);

    this->window->draw(this->base->getShape());

    this->window->display();

}