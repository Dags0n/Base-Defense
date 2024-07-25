#include "StatusBar.hpp"

// Inits
void StatusBar::initVariables(int maxPoints, int currentPoints)
{
    this->maxPoints = maxPoints;
    this->currentPoints = currentPoints;
}

void StatusBar::initBars(sf::Vector2f size, sf::Vector2i position, sf::Color color, sf::Color background)
{
    this->maxBar.setSize(size);
    this->maxBar.setPosition(position.x, position.y);
    this->maxBar.setFillColor(background);

    this->currentBar.setSize(size);
    this->currentBar.setPosition(position.x, position.y);
    this->currentBar.setFillColor(color);
}

// Constructor
StatusBar::StatusBar(sf::Vector2f size, sf::Vector2i position, int maxPoints, int currentPoints, sf::Color color, sf::Color background)
{
    this->initVariables(maxPoints, currentPoints);
    this->initBars(size, position, color, background);
}

// Update
void StatusBar::update(int currentPoints)
{
    this->currentPoints = currentPoints;
    float x = (this->currentPoints / static_cast<float>(this->maxPoints)) * this->maxBar.getSize().x;
    float y = this->currentBar.getSize().y;
    this->currentBar.setSize(sf::Vector2f(x, y));
}

// Render
void StatusBar::render(sf::RenderWindow &window)
{
    window.draw(this->maxBar);
    window.draw(this->currentBar);
}