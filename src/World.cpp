#include "World.h"
#include "Texture.h"
#include "Camera.h"
#include <iostream>
#include "Physics.h"



float worldTileScale = 32;
int worldTileX = 1000;
int worldTileY = 500;
int minY = 7;



std::vector<SDL_FRect> worldTiles;

void CreateWorld(){


    bool canSelect = true;
    int valueY =  RandomNumberGenerator(6, 10);
    int pathTraveled = 0;
    int range;
    int direction;
    for(int x = 0; x < worldTileX; x++){
        if (canSelect){
            direction = RandomNumberGenerator(-1, 1);
            range = RandomNumberGenerator(1, 5);
            canSelect = false;
        }
        else{
            valueY += direction;
            pathTraveled++;
            if(valueY < minY) valueY = minY;
            if(pathTraveled >= range){
                canSelect = true;
                pathTraveled = 0;
            }
        }
        for(int y = valueY; y < worldTileY; y++){
            SDL_FRect rect = {(float)x * worldTileScale, (float)y * worldTileScale, worldTileScale, worldTileScale};
            worldTiles.push_back(rect);
        }
    }
}

void RenderWorld(SDL_Renderer* renderer){

    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(camera, worldTiles[i])) RenderTextureWithCamera(renderer, blockTextures[TEXTURE_DIRT], worldTiles[i]);
    }
}




