#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

enum class GameState
{
    Menu,
    Playing,
    HowToPlay,
    DifficultySelection,
    Paused,
    GameOver,
    Win
};
enum class Difficulty
{
    Normal,
    Hard,
    Impossible
};

#endif