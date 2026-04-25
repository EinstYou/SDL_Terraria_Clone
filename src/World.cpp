#include "World.h"
#include "Texture.h"
#include "Camera.h"
#include <iostream>
#include "Physics.h"


World world;




std::vector<Tile> worldTiles;

void CreateWorld(){


    bool canSelect = true;
    int valueY =  RandomNumberGenerator(6, 10);
    int pathTraveled = 0;
    int range;
    int direction;
    for(int x = 0; x < world.worldTileX; x++){
        if (canSelect){
            direction = RandomNumberGenerator(-1, 1);
            range = RandomNumberGenerator(1, 5);
            canSelect = false;
        }
        else{
            valueY += direction;
            pathTraveled++;
            if(valueY < world.minY) valueY = world.minY;
            if(pathTraveled >= range){
                canSelect = true;
                pathTraveled = 0;
            }
        }
        for(int y = valueY; y < world.worldTileY; y++){
            Tile tile;
            tile.rect = {(float)x * world.worldTileScale, (float)y * world.worldTileScale, world.worldTileScale, world.worldTileScale};
            if(y == valueY){
                tile.blockTextureType = TEXTURE_GRASS;
                tile.health = 3;
            }
            else if(y > valueY && y <= valueY + world.stoneLayer){
                tile.blockTextureType = TEXTURE_DIRT;
                tile.health = 3;
            }
            else{
                tile.blockTextureType = TEXTURE_STONE;
                tile.health = 6;
            }
            worldTiles.push_back(tile);
        }
    }
}

void RenderWorld(SDL_Renderer* renderer){

    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(camera, worldTiles[i].rect)) RenderTextureWithCamera(renderer, blockTextures[worldTiles[i].blockTextureType], worldTiles[i].rect);
    }
}




