#include "Player.h"
#include "Physics.h"
#include "Texture.h"
#include "Input.h"
#include "World.h"
#include "Camera.h"

PhysicalObject player;
Vector2 direction;
float speed = 300;
float gravity = 2000;
float jumpForce = 500;
float velocityY = 0;
float velocityX = 0;



bool isGrounded = false;


void PlayerStart(){
    player.transform = {0, 0, 32, 32};
}


void PlayerEvent(SDL_Event* event){
    direction = {InputDirection(SDL_SCANCODE_D, SDL_SCANCODE_A), InputDirection(SDL_SCANCODE_S, SDL_SCANCODE_W)};
    direction = NormalizeVector(direction);
    if(event->type == SDL_EVENT_KEY_DOWN && event->key.scancode == SDL_SCANCODE_SPACE && isGrounded){
        velocityY = -jumpForce;
        isGrounded = false;
    }
}

void PlayerMove(float deltatime) {
    velocityY += gravity * deltatime;
    velocityX = speed;

    float playerOldX = player.transform.x;
    player.transform.x += speed * deltatime * direction.x;
    for(int i = 0; i < sizeof(worldTiles) / sizeof(SDL_FRect); i++){
        if(IsColliding(player.transform, worldTiles[i])){
            player.transform.x = playerOldX;
            velocityX = 0;
        }
    }

    float playerOldY = player.transform.y;
    player.transform.y += velocityY * deltatime;
    for(int i = 0; i < sizeof(worldTiles) / sizeof(SDL_FRect); i++){
        if(IsColliding(player.transform, worldTiles[i])){
            player.transform.y = playerOldY;
            velocityY = 0;
            isGrounded = true;
        }
    }
}

void PlayerRender(SDL_Renderer* renderer){
    RenderTextureWithCamera(renderer, blockTextures[TEXTURE_PLAYER], player.transform);
}




