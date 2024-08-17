#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include <SFML/Graphics.hpp>

class StatusBar
{
private:
    // Variables
    sf::RectangleShape maxBar;
    int maxPoints;
    sf::RectangleShape currentBar;
    int currentPoints;

    sf::Text labelText;
    sf::Font font;

    // Inits
    void initVariables(int maxPoints, int currentPoints);
    void initBars(sf::Vector2f size, sf::Vector2i position, sf::Color color, sf::Color background);
    void initText(const std::string &label, sf::Vector2i position);

public:
    // Constructors
    StatusBar(sf::Vector2f size, sf::Vector2i position, int maxPoints, int currentPoints, sf::Color color, sf::Color background, const std::string &label);

    // Update
    void update(int currentPoints);

    // Render
    void render(sf::RenderWindow &window);
};

#endif