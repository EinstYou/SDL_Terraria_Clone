#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Game.h"
#include "Input.h"


int main(int argc, char *argv[]) {

    Game::Initialize();

    Game::Start();
    while(Game::gameIsRunning){
        while(SDL_PollEvent(&Input::event)){
            if(Input::event.type == SDL_EVENT_QUIT) Game::gameIsRunning = false;
            Input::keyStates = SDL_GetKeyboardState(NULL);
        }
            
        Game::Update();
        Game::Render();
    }


    Game::Clean();
    return 0;
}

