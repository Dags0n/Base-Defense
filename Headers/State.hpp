#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

enum class GameState
{
    Menu,
    Playing,
    HeroSelection,
    DifficultySelection,
    Paused,
    GameOver,
    Win
};
enum class HeroType
{
    Sonda,
    Falcon,
    Starship
};
enum class Difficulty
{
    Normal,
    Hard,
    Impossible
};

#endif