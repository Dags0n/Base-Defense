#include "Base.hpp"

// Init funtions
void Base::initAttributes(){
    this->life = new Attribute(100, 100);
    this->regenRate = new Attribute(1, 1);
}

void Base::initVariables()
{
    this->sprite = new sf::Sprite();
}

void Base::initSprite(const std::vector<const char*>& srcs, sf::RenderWindow &window)
{
    for(const auto& src : srcs){
        sf::Texture* texture = new sf::Texture();

        if(!texture->loadFromFile(src))
        {
        }

        this->textures.push_back(texture);
    }

    this->sprite->setTexture(*this->textures[0]);

    float desiredWidth = 400.0f;
    float desiredHeight = 400.0f;
    float scaleX = desiredWidth / this->sprite->getLocalBounds().width;
    float scaleY = desiredHeight / this->sprite->getLocalBounds().height;
    this->sprite->setScale(sf::Vector2f(scaleX, scaleY));

    float posX = (window.getSize().x - desiredWidth) / 2.0f;
    float posY = (window.getSize().y - desiredHeight) / 2.0f;
    this->sprite->setPosition(sf::Vector2f(posX, posY));
}

// Constructors and Destructors
Base::Base(const std::vector<const char*>& srcs, sf::RenderWindow &window)
{
    this->initAttributes();
    this->initVariables();
    this->initSprite(srcs, window);
}

Base::~Base()
{
    for (auto& texture : this->textures){
        delete texture;
    }

    delete this->sprite;
    delete this->life;
    delete this->regenRate;
}

// Getters and Setters
int Base::getLife()
{
    return this->life->points();
}

int Base::getMaxLife(){
    return this->life->maxPoints();
}

int Base::getRate(){
    return this->regenRate->points();
}

sf::FloatRect Base::getArea()
{
    return this->sprite->getGlobalBounds();
}

// Public functions
void Base::damage(int value)
{
    this->life->consume(value);
}


// update functions
void Base::regenerate(){
    this->life->recharge(regenRate->points());
}

void Base::update()
{
    if(this->regenClock.getElapsedTime().asSeconds() >= 1.0f)
    {
        this->regenerate();
        this->regenClock.restart();
    }
    this->updateSprite();
}                               

void Base::updateSprite()
{
    int max = this->getMaxLife();
    int current = this->getLife();
    int sizeTex = this->textures.size();

    int interval = max / sizeTex;
    int texIndex = (max - current) / interval;
    if (texIndex >= sizeTex) {
        texIndex = sizeTex - 1;
    }
    this->sprite->setTexture(*this->textures[texIndex]);
}

// render
void Base::render(sf::RenderWindow &window)
{
    window.draw(*this->sprite);
}
