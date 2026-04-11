#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Game.h"



int main(int argc, char *argv[]) {

    if(!SDL_Init(SDL_INIT_VIDEO)){
        printf("SDL_Init Error: %s \n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Hello", 640, 480, 0);
    if(!window){
        printf("SDL_Window Error: %s \n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0);
    if(!renderer){
        printf("SDL_Renderer Error: %s \n", SDL_GetError());
        return 1;
    }

    bool running = true;
    Start(renderer);
    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_EVENT_QUIT) running = false;
            GetInputs(&e);
            
        }

        Update();
        Render(renderer);
        SDL_Delay(1);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

