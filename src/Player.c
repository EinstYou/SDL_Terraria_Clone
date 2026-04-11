#include "Player.h"
#include "Physics.h"
#include "Texture.h"
#include "Input.h"

PhysicalObject player;
Vector2 direction;
float speed = 300;
float gravity = 2000;
float jumpForce = 500;
float velocityY = 0;



bool isGrounded = false;


void PlayerStart(){
    player.transform = (SDL_FRect){0, 0, 50, 50};
}


void PlayerEvent(SDL_Event* event){
    direction = (Vector2) {InputDirection(SDL_SCANCODE_D, SDL_SCANCODE_A), InputDirection(SDL_SCANCODE_S, SDL_SCANCODE_W)};
    direction = NormalizeVector(direction);
    if(event->type == SDL_EVENT_KEY_DOWN && event->key.scancode == SDL_SCANCODE_SPACE && isGrounded){
        velocityY = -jumpForce;
        isGrounded = false;
    }
}

void PlayerMove(float deltatime){
    velocityY += gravity * deltatime;
    player.transform.x += speed * deltatime * direction.x;
    player.transform.y += velocityY * deltatime;
    if(player.transform.y + player.transform.h >= 480){
        player.transform.y = 480 - player.transform.h;
        isGrounded = true;
        velocityY = 0;
    }
    
}

void PlayerRender(SDL_Renderer* renderer){
    SDL_RenderTexture(renderer, blockTextures[TEXTURE_DIRT], NULL, &player.transform);
}




