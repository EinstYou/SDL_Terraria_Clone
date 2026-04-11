#include "World.h"
#include "Texture.h"




float WorldTileScale = 64;
int WorldTileX = 10;
int WorldTileY = 50;

int StartX = 0;
int StartY = 5;


void RenderWorld(SDL_Renderer* renderer){

    for(int y = StartY; y < WorldTileY; y++){
        for(int x = StartX; x < WorldTileX; x++){

            SDL_FRect rect = {(float)x * WorldTileScale, (float)y * WorldTileScale, WorldTileScale, WorldTileScale};
            SDL_RenderTexture(renderer, blockTextures[TEXTURE_DIRT], NULL, &rect);
        }
    }
}





