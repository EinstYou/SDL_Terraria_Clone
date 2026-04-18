#include "World.h"
#include "Texture.h"
#include "Camera.h"
#include <iostream>
#include "Physics.h"



float worldTileScale = 32;
int worldTileX = 200;
int worldTileY = 50;


std::vector<SDL_FRect> worldTiles;

void CreateWorld(){
    for(int x = 0; x < worldTileX; x++){
        for(int y = RandomNumberGenerator(10, 11); y < worldTileY; y++){
            SDL_FRect rect = {(float)x * worldTileScale, (float)y * worldTileScale, worldTileScale, worldTileScale};
            worldTiles.push_back(rect);
        }
    }
}

void RenderWorld(SDL_Renderer* renderer){

    for(int i = 0; i < worldTiles.size(); i++){
        RenderTextureWithCamera(renderer, blockTextures[TEXTURE_DIRT], worldTiles[i]);
    }
}




