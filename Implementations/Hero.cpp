#include "Hero.hpp"

//Private funtions
void Hero::initVariables() {
    this->texture = new sf::Texture();
    this->sprite = new sf::Sprite();
}

void Hero::initAttributes() {
    this->life = new Attribute(100, 100);
    this->ammunition = new Attribute(100, 100);
}

void Hero::initSprite(const char* src) {
    if (!this->texture->loadFromFile(src)) {
    }
    this->sprite->setTexture(*this->texture);
}


//Constructors and Destructors
Hero::Hero(const char* src) {
    this->initVariables();
    this->initAttributes();
    this->initSprite(src);
}

Hero::~Hero() {
    delete this->texture;
    delete this->sprite;
    delete this->life;
    delete this->ammunition;
}


//Getters and Setters
sf::Sprite& Hero::getSprite() {
    return *this->sprite;
}