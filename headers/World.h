#ifndef WORLD_H
#define WORLD_H


#include <SDL3/SDL.h>
#include <vector>



extern std::vector<SDL_FRect> worldTiles;
void CreateWorld();
void RenderWorld(SDL_Renderer* renderer);




#endif