#include "Menu.hpp"

Menu::Menu(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("Fonts/PressStart2P-Regular.ttf")) {
    }

    if (!backgroundTexture.loadFromFile("Assets/Image/backgroundMenu1.jpg"))
    {
    }
    backgroundSprite.setTexture(this->backgroundTexture);

    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );

    setupMainMenu();
}

void Menu::setupMainMenu() {
    menuItems = {"Start Game", "Select Hero", "Difficulty", "Exit"};
    menuTexts.clear();

    for (size_t i = 0; i < menuItems.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(menuItems[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 100.f + i * 40.f);
        menuTexts.push_back(text);
    }
}

void Menu::setupHeroSelectionMenu() {
    heroOptions = {"Sonda III", "Falcon 9", "Starship", "Back"};
    heroTexts.clear();

    for (size_t i = 0; i < heroOptions.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(heroOptions[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 100.f + i * 40.f);
        heroTexts.push_back(text);
    }
}

void Menu::setupDifficultySelectionMenu() {
    difficultyOptions = {"Normal", "Hard", "Impossible", "Back"};
    difficultyTexts.clear();

    for (size_t i = 0; i < difficultyOptions.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(difficultyOptions[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 100.f + i * 40.f);
        difficultyTexts.push_back(text);
    }
}

void Menu::handleInput(sf::Event event, GameState& state, HeroType& heroType, Difficulty& difficulty, sf::RenderWindow& window) {
    if (state == GameState::Menu) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

                for (size_t i = 0; i < menuItems.size(); ++i) {
                    if (menuTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        switch (i) {
                            case 0: state = GameState::Playing; break;
                            case 1: state = GameState::HeroSelection; setupHeroSelectionMenu(); break;
                            case 2: state = GameState::DifficultySelection; setupDifficultySelectionMenu(); break;
                            case 3: exit(0); break;
                        }
                    }
                }
            }
        }
    } else if (state == GameState::HeroSelection) {
        handleHeroSelectionInput(event, state, window, heroType);
    } else if (state == GameState::DifficultySelection) {
        handleDifficultySelectionInput(event, state, window, difficulty);
    }
}

void Menu::handleHeroSelectionInput(sf::Event event, GameState& state, sf::RenderWindow& window, HeroType& heroType) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

            for (size_t i = 0; i < heroOptions.size(); ++i) {
                if (heroTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    switch (i) {
                        case 0:
                            heroType = HeroType::Sonda;
                            state = GameState::Menu;
                            break;
                        case 1:
                            heroType = HeroType::Falcon;
                            state = GameState::Menu;
                            break;
                        case 2:
                            heroType = HeroType::Starship;
                            state = GameState::Menu;
                            break;
                        case 3: state = GameState::Menu; break;
                    }
                }
            }
        }
    }
}

void Menu::handleDifficultySelectionInput(sf::Event event, GameState& state, sf::RenderWindow& window, Difficulty& difficulty) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

            for (size_t i = 0; i < difficultyOptions.size(); ++i) {
                if (difficultyTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    for (size_t i = 0; i < difficultyOptions.size(); ++i) {
                        if (difficultyTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            switch (i) {
                                case 0:
                                    difficulty = Difficulty::Normal;
                                    state = GameState::Menu;
                                    break;
                                case 1:
                                    difficulty = Difficulty::Hard;
                                    state = GameState::Menu;
                                    break;
                                case 2:
                                    difficulty = Difficulty::Impossible;
                                    state = GameState::Menu;
                                    break;
                                case 3: state = GameState::Menu; break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Menu::draw(sf::RenderWindow& window, GameState state) {
    window.clear();
    window.draw(backgroundSprite);

    if (state == GameState::Menu) {
        for (const auto& text : menuTexts) {
            window.draw(text);
        }
    } else if (state == GameState::HeroSelection) {
        for (const auto& text : heroTexts) {
            window.draw(text);
        }
    } else if (state == GameState::DifficultySelection) {
        for (const auto& text : difficultyTexts) {
            window.draw(text);
        }
    }
}