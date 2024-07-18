#include "Game.hpp"

int main(){

    //Init game engine
    Game game;

    //Gameloop
    while(game.running()){

        //Update
        game.update();

        //Render
        game.render();
    }
    return 0;
}