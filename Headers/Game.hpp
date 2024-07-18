#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Hero.hpp"

class Game {
private:

    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event event;
    sf::Music* music;

    //Game Objects
    Hero* hero;

    //Private functions
    void initVariables();
    void initWindow();
    void initMusic();
    void initHero();

public:

    //Contructors and Destructors
    Game();
    ~Game();

    //Accesors
    bool running(); 

    //Public functions
    void pollEvents();
    void update();
    void render();
};

#endif