#include "Boss.hpp"

// Utility functions
sf::Vector2f generateRandomPositionBoss(sf::RenderTarget &target, float margin = 0.f)
{
    int side = rand() % 4;
    float x, y;
    switch (side)
    {
    case 0: // Top
        x = static_cast<float>(rand() % static_cast<int>(target.getSize().x + 2 * margin)) - margin;
        y = -margin;
        break;
    case 1: // Right
        x = target.getSize().x + margin;
        y = static_cast<float>(rand() % static_cast<int>(target.getSize().y + 2 * margin)) - margin;
        break;
    case 2: // Bottom
        x = static_cast<float>(rand() % static_cast<int>(target.getSize().x + 2 * margin)) - margin;
        y = target.getSize().y + margin;
        break;
    case 3: // Left
        x = -margin;
        y = static_cast<float>(rand() % static_cast<int>(target.getSize().y + 2 * margin)) - margin;
        break;
    }
    sf::Vector2f position(x, y);
    return position;
}

// Init functions
void Boss::initVariables(float bossSpeed)
{
    this->sprite = new sf::Sprite();
    this->bossSpeed = bossSpeed;
    this->shotInterval = 1.f;
}

void Boss::initAttributes()
{
    this->life = new Attribute(100, 100);
}

void Boss::initSprite(const std::vector<const char *> &srcs, sf::RenderTarget &target)
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

    sf::Vector2f position = generateRandomPositionBoss(target, 60.f);
    this->sprite->setPosition(position);
    sf::FloatRect bounds = this->sprite->getLocalBounds();
    this->sprite->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Boss::showCollisionBox(sf::RenderWindow &window)
{
    sf::FloatRect shape = getArea();
    sf::RectangleShape hitbox(sf::Vector2f(shape.width, shape.height));

    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(2);
    hitbox.setPosition(shape.left, shape.top);

    window.draw(hitbox);
}

// Constructors and Destructors
Boss::Boss(const std::vector<const char *> &srcs, sf::RenderWindow &window, Hero *hero, float bossSpeed)
{
    this->initVariables(bossSpeed);
    this->initAttributes();
    this->initSprite(srcs, window);
    this->hero = hero;
}

Boss::~Boss()
{
    for (auto &texture : this->textures)
    {
        delete texture;
    }

    delete this->sprite;
}

// Public functions
void Boss::update(sf::RenderWindow &window, float deltaTime)
{
    this->moveTowardsHero(deltaTime);
    this->updateWalkingAnimation(deltaTime);
}

void Boss::render(sf::RenderWindow &window)
{
    window.draw(*this->sprite);
    //this->showCollisionBox(window);
}

void Boss::moveTowardsHero(float deltaTime)
{
    sf::Vector2f heroPos = this->hero->getPosition();
    sf::Vector2f bossPos = this->sprite->getPosition();
    sf::Vector2f direction = heroPos - bossPos;
    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    direction /= length;
    this->sprite->move(direction * this->bossSpeed * deltaTime);
}

void Boss::updateWalkingAnimation(float deltaTime)
{
    this->animationTime += deltaTime;
    if (this->animationTime >= this->timePerFrame)
    {
        this->animationTime -= this->timePerFrame;
        this->currentTextureIndex = (this->currentTextureIndex + 1) % this->textures.size();
        this->sprite->setTexture(*this->textures[this->currentTextureIndex]);
    }
}

Shot *Boss::shot(const std::string &src, const sf::Vector2f &destiny)
{
    return new Shot(src, this->sprite->getPosition(), destiny);
}

void Boss::damage(int points)
{
    this->life->consume(points);
}

// Getters
sf::Clock &Boss::getShotClock()
{
    return this->shotClock;
}

float Boss::getShotInterval()
{
    return this->shotInterval;
}

sf::FloatRect Boss::getArea()
{
  if (!this->sprite)
  {
      return sf::FloatRect();
  }

  float reductionFactor = 0.6f;

  sf::FloatRect originalBounds = this->sprite->getGlobalBounds();
  sf::FloatRect reducedBounds = originalBounds;
  reducedBounds.width *= reductionFactor;
  reducedBounds.height *= reductionFactor;

  reducedBounds.left += (originalBounds.width - reducedBounds.width) / 2.0f;
  reducedBounds.top += (originalBounds.height - reducedBounds.height) / 2.0f;

  return reducedBounds;
}

int Boss::getLife()
{
    return this->life->points();
}

int Boss::getMaxLife()
{
    return this->life->maxPoints();
}