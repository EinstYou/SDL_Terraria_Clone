
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Physics.h"


extern PhysicalObject player;



void PlayerStart();
void PlayerEvent(SDL_Event* event);
void PlayerMove(float deltatime);
void PlayerRender(SDL_Renderer* renderer);





#endif