#include "Menu.hpp"

Menu::Menu(sf::RenderWindow &window) : window(window)
{
    if (!font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
    {
    }

    if (!backgroundTexture.loadFromFile("Assets/Image/backgroundMenu.png"))
    {
    }
    backgroundSprite.setTexture(this->backgroundTexture);

    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y);

    setupTitle();
    setupMainMenu();
}

void Menu::setupMainMenu()
{
    menuItems = {"Start Game", "How to Play", "Difficulty", "Exit"};
    menuTexts.clear();

    for (size_t i = 0; i < menuItems.size(); ++i)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(menuItems[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 450.f + i * 40.f);
        menuTexts.push_back(text);
    }
}

void Menu::setupHowToPlayMenu()
{
    htpOptions = {"How to Play:", "Press the right mouse button to move;", "Press the Q key to shoot;", "You need to defend your base at any cost;", "Kill all the enemies to win;", "You will need to eliminate 51 of them;", "The Snipers and the Kamikazes will atack you;", "Your last challenge will be to kill their Boss.", "Good luck, you'll need it", "Back"};
    htpTexts.clear();

    for (size_t i = 0; i < htpOptions.size() - 1; ++i)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(htpOptions[i]);

        if (i == 0)
        {
            text.setCharacterSize(36);
            text.setPosition(80.f, 80.f);
        }
        else
        {
            text.setCharacterSize(24);
            text.setPosition(100.f, 100.f + i * 50.f);
        }

        text.setFillColor(sf::Color::White);
        htpTexts.push_back(text);
    }

    sf::Text text;
    text.setFont(font);
    text.setString(htpOptions[htpOptions.size() - 1]);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100.f, 570.f);
    htpTexts.push_back(text);
}

void Menu::setupDifficultySelectionMenu()
{
    difficultyOptions = {"Normal", "Hard", "Impossible", "Back"};
    difficultyTexts.clear();

    for (size_t i = 0; i < difficultyOptions.size(); ++i)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(difficultyOptions[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 450.f + i * 40.f);
        difficultyTexts.push_back(text);
    }
}

void Menu::setupGameOver()
{
    std::vector<std::string> gameOverOptions = {"Game Over", "You Lost!", "Play Again", "Menu", "Exit"};
    setupEndGame(gameOverOptions);
}

void Menu::setupWin()
{
    std::vector<std::string> winOptions = {"Game Over", "You Win!", "Play Again", "Menu", "Exit"};
    setupEndGame(winOptions);
}

void Menu::setupEndGame(const std::vector<std::string> &options)
{
    endOptions = options;
    endTexts.clear();

    for (size_t i = 0; i < 2; ++i)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(endOptions[i]);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 300.f + i * 70.f);
        endTexts.push_back(text);
    }

    for (size_t i = 2; i < endOptions.size(); ++i)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(endOptions[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 450.f + i * 40.f);
        endTexts.push_back(text);
    }
}

void Menu::setupTitle()
{
    title.setFont(font);
    title.setString("EARTH DEFENDERS");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setPosition(70.f, 70.f);

    subtitle.setFont(font);
    subtitle.setString("VOID ASSAULT");
    subtitle.setCharacterSize(28);
    subtitle.setFillColor(sf::Color::White);
    subtitle.setPosition(70.f, 140.f);
}

void Menu::handleInput(sf::Event event, GameState &state, Difficulty &difficulty, sf::RenderWindow &window)
{
    if (state == GameState::Menu)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

                for (size_t i = 0; i < menuItems.size(); ++i)
                {
                    if (menuTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        switch (i)
                        {
                        case 0:
                            state = GameState::Playing;
                            break;
                        case 1:
                            state = GameState::HowToPlay;
                            setupHowToPlayMenu();
                            break;
                        case 2:
                            state = GameState::DifficultySelection;
                            setupDifficultySelectionMenu();
                            break;
                        case 3:
                            exit(0);
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (state == GameState::HowToPlay)
    {
        handleHowToPlayInput(event, state, window);
    }
    else if (state == GameState::DifficultySelection)
    {
        handleDifficultySelectionInput(event, state, window, difficulty);
    }
    else if (state == GameState::GameOver || state == GameState::Win)
    {
        handleEndGameInput(event, state, window);
    }
}

void Menu::handleHowToPlayInput(sf::Event event, GameState &state, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

            for (size_t i = 0; i < htpOptions.size(); ++i)
            {
                if (htpTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    if (i == htpOptions.size() - 1)
                    {
                        state = GameState::Menu;
                    }
                }
            }
        }
    }
}

void Menu::handleDifficultySelectionInput(sf::Event event, GameState &state, sf::RenderWindow &window, Difficulty &difficulty)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

            for (size_t i = 0; i < difficultyOptions.size(); ++i)
            {
                if (difficultyTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    for (size_t i = 0; i < difficultyOptions.size(); ++i)
                    {
                        if (difficultyTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                        {
                            switch (i)
                            {
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
                            case 3:
                                state = GameState::Menu;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Menu::handleEndGameInput(sf::Event event, GameState &state, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*&window);

            for (size_t i = 2; i < endOptions.size(); ++i)
            {
                if (endTexts[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    switch (i)
                    {
                    case 2:
                        state = GameState::Playing;
                        break;
                    case 3:
                        state = GameState::Menu;
                        break;
                    case 4:
                        exit(0);
                        break;
                    }
                }
            }
        }
    }
}

void Menu::draw(sf::RenderWindow &window, GameState state)
{
    window.clear();
    window.draw(backgroundSprite);

    if (state != GameState::HowToPlay)
    {    
        window.draw(title);
        window.draw(subtitle);
    }

    if (state == GameState::Menu)
    {
        for (const auto &text : menuTexts)
        {
            window.draw(text);
        }
    }
    else if (state == GameState::HowToPlay)
    {
        for (const auto &text : htpTexts)
        {
            window.draw(text);
        }
    }
    else if (state == GameState::DifficultySelection)
    {
        for (const auto &text : difficultyTexts)
        {
            window.draw(text);
        }
    }
    else if (state == GameState::GameOver)
    {
        setupGameOver();
        for (const auto &text : endTexts)
        {
            window.draw(text);
        }
    }
    else if (state == GameState::Win)
    {
        setupWin();
        for (const auto &text : endTexts)
        {
            window.draw(text);
        }
    }
}