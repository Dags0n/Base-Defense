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

void StatusBar::initText(const std::string& label, sf::Vector2i position)
{
    if (!this->font.loadFromFile("Fonts/PressStart2P-Regular.ttf")) 
    {
    }

    this->labelText.setFont(this->font);
    this->labelText.setString(label);
    this->labelText.setCharacterSize(10); 
    this->labelText.setFillColor(sf::Color::White);
    this->labelText.setPosition(position.x, position.y - 15);
}

// Constructor
StatusBar::StatusBar(sf::Vector2f size, sf::Vector2i position, int maxPoints, int currentPoints, sf::Color color, sf::Color background, const std::string& label)
{
    this->initVariables(maxPoints, currentPoints);
    this->initBars(size, position, color, background);
    this->initText(label, position);
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
    window.draw(this->labelText);
}