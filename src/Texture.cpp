#include "Texture.h"


SDL_Texture* blockTextures[TEXTURE_COUNT];


SDL_Texture* CreateTexture(SDL_Renderer* renderer, const char* file){
    SDL_Surface* surface = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);
    return texture;
}


 void SaveTextures(SDL_Renderer* renderer){
    blockTextures[TEXTURE_GRASS] = CreateTexture(renderer, "assets/Grass.png");
    blockTextures[TEXTURE_DIRT] = CreateTexture(renderer, "assets/Dirt.png");
    blockTextures[TEXTURE_STONE] = CreateTexture(renderer, "assets/Stone.png");
    blockTextures[TEXTURE_PLAYER] = CreateTexture(renderer, "assets/PlayerS.png");
 }
