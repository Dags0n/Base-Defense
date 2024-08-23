#include "Base.hpp"

// Init funtions
void Base::initAttributes()
{
    this->life = new Attribute(100, 100);
}

void Base::initVariables()
{
    this->sprite = new sf::Sprite();
}

void Base::initSprite(const std::vector<const char *> &srcs, sf::RenderWindow &window)
{
    for (const auto &src : srcs)
    {
        sf::Texture *texture = new sf::Texture();

        if (!texture->loadFromFile(src))
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

void Base::showCollisionBox(sf::RenderWindow &window)
{
    sf::FloatRect spriteBound = sprite->getGlobalBounds();
    float radius = spriteBound.width * 0.946f / 2.f;

    sf::CircleShape hitbox(radius);
    sf::Vector2u windowSize = window.getSize();

    float centerX = windowSize.x / 2.f;
    float centerY = windowSize.y / 2.f;

    hitbox.setPosition(centerX - radius, centerY - radius);

    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(2);
    hitbox.setFillColor(sf::Color::Transparent);

    window.draw(hitbox);
}

// Constructors and Destructors
Base::Base(const std::vector<const char *> &srcs, sf::RenderWindow &window)
{
    this->initAttributes();
    this->initVariables();
    this->initSprite(srcs, window);
}

Base::~Base()
{
    for (auto &texture : this->textures)
    {
        delete texture;
    }

    delete this->sprite;
    delete this->life;
}

// Getters and Setters
int Base::getLife()
{
    return this->life->points();
}

int Base::getMaxLife()
{
    return this->life->maxPoints();
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

bool Base::collision(sf::FloatRect rect)
{
    sf::FloatRect spriteBound = this->sprite->getGlobalBounds();

    float originX = spriteBound.left + spriteBound.width / 2.f;
    float originY = spriteBound.top + spriteBound.height / 2.f;
    float radius = spriteBound.width * 0.946f / 2.f;

    float nearestX = std::max(rect.left, std::min(originX, rect.left + rect.width));
    float nearestY = std::max(rect.top, std::min(originY, rect.top + rect.height));

    float deltaX = originX - nearestX;
    float deltaY = originY - nearestY;
    float distanceSquared = deltaX * deltaX + deltaY * deltaY;

    return distanceSquared <= radius * radius;
}

// update functions
void Base::regenerate(float regenRate)
{
    this->life->recharge(regenRate);
}

void Base::update(float regenRate)
{
    if (this->regenClock.getElapsedTime().asSeconds() >= 1.0f)
    {
        this->regenerate(regenRate);
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
    if (texIndex >= sizeTex)
    {
        texIndex = sizeTex - 1;
    }
    this->sprite->setTexture(*this->textures[texIndex]);
}

void Base::reset()
{
    this->life->recharge(this->life->maxPoints());
}

// render
void Base::render(sf::RenderWindow &window)
{
    window.draw(*this->sprite);
    //showCollisionBox(window);
}
