#include "Camera.h"
#include "Player.h"
#include "World.h"



SDL_FRect camera = {0, 0, 640, 480};


void RenderTextureWithCamera(SDL_Renderer* renderer, SDL_Texture* texture, SDL_FRect rect){
    SDL_FRect withCamera;
    withCamera.x = rect.x - camera.x;
    withCamera.y = rect.y - camera.y;
    withCamera.w = rect.w;
    withCamera.h = rect.h;
    SDL_RenderTexture(renderer, texture, NULL, &withCamera);
}

void RenderRectWithCamera(SDL_Renderer* renderer, SDL_FRect rect){
    SDL_FRect withCamera;
    withCamera.x = rect.x - camera.x;
    withCamera.y = rect.y - camera.y;
    withCamera.w = rect.w;
    withCamera.h = rect.h;
    SDL_RenderRect(renderer, &withCamera);
}


void CameraMovement(SDL_FRect transform){
    camera.x = GetOrigin(transform.x, transform.w) - (camera.w / 2);
    camera.y = GetOrigin(transform.y, transform.h) - (camera.h / 2);
    if(camera.x < 0) camera.x = 0;
    else if (camera.x + camera.w > world.worldTileScale * world.worldTileX) camera.x = world.worldTileScale * world.worldTileX - camera.w;

    if(camera.y < 0) camera.y = 0;
    else if(camera.y + camera.h > world.worldTileScale * world.worldTileY) camera.y = world.worldTileScale * world.worldTileY - camera.h;
    
}