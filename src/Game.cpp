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

void Game::Start(SDL_Renderer* renderer){
    GameTime::pastFrame = SDL_GetPerformanceCounter();
    srand(time(NULL));
    gameIsRunning = true;
    SaveTextures(renderer);
    CreateWorld();
    PlayerStart();
}


void Game::GetInputs(){
    while(SDL_PollEvent(&Input::event)){
        if(Input::event.type == SDL_EVENT_QUIT) gameIsRunning = false;
        PlayerEvent(&Input::event);
    }
}

void Game::Update(){
    GameTime::CalculateDeltaTime();
    PlayerMove();
    CameraMovement();
}



void Game::Render(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
    SDL_RenderClear(renderer);

    //Draw Here
    PlayerRender(renderer);
    RenderWorld(renderer);
    SDL_RenderPresent(renderer);
}