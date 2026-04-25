#ifndef WORLD_H
#define WORLD_H


#include <SDL3/SDL.h>
#include "Physics.h"
#include <vector>



struct World{
    float worldTileScale = 32;
    int worldTileX = 1000;
    int worldTileY = 500;
    int stoneLayer = 3;
    int minY = 7;
};

typedef struct Tile{
    int blockTextureType;
    int health;
    SDL_FRect rect;
}Tile;




extern std::vector<Tile> worldTiles;
void CreateWorld();
void RenderWorld(SDL_Renderer* renderer);




#endif