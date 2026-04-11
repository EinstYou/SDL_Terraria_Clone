#include "Texture.h"

SDL_Texture* CreateTexture(SDL_Renderer* renderer, const char* file){
    SDL_Surface* surface = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);
    return texture;
}



