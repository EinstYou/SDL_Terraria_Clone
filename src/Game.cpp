#include "Game.h"
#include <Physics.h>
#include <iostream>
#include <ctime>
#include "Input.h"
#include "Player.h"
#include "Texture.h"
#include "World.h"
#include "Camera.h"


double deltaTime = 0;


void Start(SDL_Renderer* renderer){
    SaveTextures(renderer);
    CreateWorld();
    PlayerStart();
    srand(time(NULL));
}


void GetInputs(SDL_Event* event){
    PlayerEvent(event);
}

void Update(){
    PlayerMove(deltaTime);
    CameraMovement();
}



void Render(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
    SDL_RenderClear(renderer);

    //Draw Here
    PlayerRender(renderer);
    RenderWorld(renderer);
    SDL_RenderPresent(renderer);
}