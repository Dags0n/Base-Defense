#include "Hero.hpp"

//Init funtions
void Hero::initVariables() {
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
}

void Hero::initAttributes() {
    this->life = new Attribute(100, 100);
    this->ammunition = new Attribute(100, 100);
}

void Hero::initSprite(const char* src, sf::RenderTarget &target) {
    if (!this->texture->loadFromFile(src)) {
    }
    this->sprite->setTexture(*this->texture);

    float posX = (target.getSize().x - this->sprite->getLocalBounds().height)/2.0;
    float posY = (target.getSize().y - this->sprite->getLocalBounds().width)/2.0;
    this->sprite->setPosition(sf::Vector2f(posX, posY));
}


//Constructors and Destructors
Hero::Hero(const char* src, sf::RenderTarget &target) {
    this->initVariables();
    this->initAttributes();
    this->initSprite(src, target);
}

Hero::~Hero() {
    delete this->texture;
    delete this->sprite;
    delete this->life;
    delete this->ammunition;
}

//Public functions
void Hero::update(sf::RenderTarget &target)
{
}

void Hero::render(sf::RenderTarget &target)
{
    target.draw(*this->sprite);
}
