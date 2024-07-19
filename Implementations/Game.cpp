#include "Game.hpp"

//Private functions
void Game::initWindow()
{
    this->videoMode.height = 480;
    this->videoMode.width = 640;

    this->window = new sf::RenderWindow(this->videoMode, "Base Defense", sf::Style::Default);
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
    this->hero = new Hero((char*)"Assets/Image/spaceship_dark.png");
}

void Game::initBase() 
{
    this->base = new Base(200, 160, 100, 1);
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
}

//Accesors
bool Game::running()
{
    return this->window->isOpen();
}

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

// Public functions
void Game::update()
{
    this->pollEvents();
}

void Game::render()
{

    this->window->clear(sf::Color::Black);

    this->window->draw(this->hero->getSprite());

    this->window->draw(this->base->getShape());

    this->window->display();

}