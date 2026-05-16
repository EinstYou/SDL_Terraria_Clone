#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Game.h"


int main(int argc, char *argv[]) {

    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Hello", 640, 480, 0);
    if(!window){
        std::cout << "SDL_Window Error: " << SDL_GetError() << std::endl;
        printf("SDL_Window Error: %s \n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0);
    if(!renderer){
        printf("SDL_Renderer Error: %s \n", SDL_GetError());
        return 1;
    }

    Game::Start(renderer);
    while(Game::gameIsRunning){
        Game::GetInputs();
            
        Game::Update();
        Game::Render(renderer);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

