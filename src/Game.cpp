#include "Game.h"
#include <Physics.h>
#include <iostream>
#include <ctime>
#include "Input.h"
#include "Player.h"
#include "Texture.h"
#include "World.h"
#include "Camera.h"
#include "GameTime.h"

bool Game::gameIsRunning = 0;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;

void Game::Start(){

    srand(time(NULL));

    GameTime::pastFrame = SDL_GetPerformanceCounter();
    Game::gameIsRunning = true;
    
    SaveTextures();
    CreateWorld();
    PlayerStart();
}



void Game::Update(){
    GameTime::CalculateDeltaTime();
    PlayerMove();
    CameraMovement();
}



void Game::Render(){

    SDL_SetRenderDrawColor(Game::renderer, 100, 200, 255, 255);
    SDL_RenderClear(Game::renderer);

    //Draw Here
    PlayerRender();
    RenderWorld();
    SDL_RenderPresent(Game::renderer);
}



int Game::Initialize(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    Game::window = SDL_CreateWindow("Hello", 640, 480, 0);
    if(Game::window == nullptr){
        std::cout << "SDL_Window Error: " << SDL_GetError() << std::endl;
        printf("SDL_Window Error: %s \n", SDL_GetError());
        return 1;
    }

    Game::renderer = SDL_CreateRenderer(Game::window, 0);
    if(Game::renderer == nullptr){
        printf("SDL_Renderer Error: %s \n", SDL_GetError());
        return 1;
    }
    return 0;
}



void Game::Clean(){
    SDL_DestroyRenderer(Game::renderer);
    SDL_DestroyWindow(Game::window);
    SDL_Quit();
}