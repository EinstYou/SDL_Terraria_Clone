#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Game.h"


int main(int argc, char *argv[]) {

    Game::Initialize();

    Game::Start();
    while(Game::gameIsRunning){
        Game::GetInputs();
            
        Game::Update();
        Game::Render();
    }


    Game::Clean();
    return 0;
}

