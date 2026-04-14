#include "World.h"
#include "Texture.h"
#include "Camera.h"



float worldTileScale = 32;
int worldTileX = 200;
int worldTileY = 50;

int startX = 0;
int startY = 5;

SDL_FRect worldTiles[10000];

void CreateWorld(){
    int i = 0;
    for(int y = startY; y < worldTileY; y++){
        for(int x = startX; x < worldTileX; x++){
            SDL_FRect rect = {(float)x * worldTileScale, (float)y * worldTileScale, worldTileScale, worldTileScale};
            worldTiles[i] = rect;
            i++;
        }
    }
}

void RenderWorld(SDL_Renderer* renderer){

    for(int rect = 0; rect < sizeof(worldTiles) / sizeof(SDL_FRect); rect++){
        RenderTextureWithCamera(renderer, blockTextures[TEXTURE_DIRT], worldTiles[rect]);
    }
}




