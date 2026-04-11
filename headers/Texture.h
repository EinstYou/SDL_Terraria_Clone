#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


typedef enum Blocks{
    TEXTURE_DIRT,
    TEXTURE_COUNT
}Blocks;

extern SDL_Texture* blockTextures[TEXTURE_COUNT];


SDL_Texture* CreateTexture(SDL_Renderer* renderer, const char* file);

void SaveTextures(SDL_Renderer* renderer);






#endif