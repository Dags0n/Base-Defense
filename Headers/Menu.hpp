#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "State.hpp"

class Menu {
public:
    Menu();
    void handleInput(sf::Event event, GameState& state, HeroType& heroType, Difficulty& difficulty, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window, GameState state);

private:
    void setupMainMenu();
    void setupHeroSelectionMenu();
    void setupDifficultySelectionMenu();
    void handleHeroSelectionInput(sf::Event event, GameState& state, sf::RenderWindow& window, HeroType& heroType);
    void handleDifficultySelectionInput(sf::Event event, GameState& state, sf::RenderWindow& window, Difficulty& difficulty);

    sf::Font font;
    std::vector<std::string> menuItems;
    std::vector<sf::Text> menuTexts;

    std::vector<std::string> heroOptions;
    std::vector<sf::Text> heroTexts;

    std::vector<std::string> difficultyOptions;
    std::vector<sf::Text> difficultyTexts;
};

#endif