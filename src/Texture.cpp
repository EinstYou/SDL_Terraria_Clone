#include "Texture.h"
#include "Game.h"


SDL_Texture* blockTextures[TEXTURE_COUNT];


SDL_Texture* CreateTexture(const char* file){
    SDL_Surface* surface = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);
    return texture;
}


 void SaveTextures(){
    blockTextures[TEXTURE_GRASS] = CreateTexture("assets/Grass.png");
    blockTextures[TEXTURE_DIRT] = CreateTexture("assets/Dirt.png");
    blockTextures[TEXTURE_STONE] = CreateTexture("assets/Stone.png");
    blockTextures[TEXTURE_PLAYER] = CreateTexture("assets/PlayerS.png");
 }
