#include "Game.h"
#include <Physics.h>
#include <stdio.h>
#include "Input.h"
#include "Player.h"
#include "Texture.h"
#include "World.h"


double deltaTime = 0;
Uint64 currentFrame = 0;
Uint64 nextFrame = 0;


void Start(SDL_Renderer* renderer){
    currentFrame = SDL_GetPerformanceCounter();
    SaveTextures(renderer);
    CreateWorld();
    PlayerStart();
}


void GetInputs(SDL_Event* event){
    PlayerEvent(event);
}

void Update(){
    CalculateDeltaTime();
    printf("FPS: %d\n", (int)(1/deltaTime));
    PlayerMove(deltaTime);
}



void Render(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
    SDL_RenderClear(renderer);

    //Draw Here
    PlayerRender(renderer);
    RenderWorld(renderer);
    SDL_RenderPresent(renderer);
}

void CalculateDeltaTime() {
    nextFrame = (double)SDL_GetPerformanceCounter();
    deltaTime = (double)(nextFrame - currentFrame) / (double)SDL_GetPerformanceFrequency();
    currentFrame = nextFrame;
}