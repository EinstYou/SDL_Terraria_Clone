#ifndef WORLD_H
#define WORLD_H


#include <SDL3/SDL.h>



extern SDL_FRect worldTiles[10000];
void CreateWorld();
void RenderWorld(SDL_Renderer* renderer);




#endif