#ifndef CAMERA_H
#define CAMERA_H
#include <SDL3/SDL.h>


void CameraMovement();

void RenderTextureWithCamera(SDL_Renderer* renderer, SDL_Texture* texture, SDL_FRect rect);

void RenderRectWithCamera(SDL_Renderer* renderer, SDL_FRect rect);

#endif