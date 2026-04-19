#include "Player.h"
#include "Physics.h"
#include "Texture.h"
#include "Input.h"
#include "World.h"
#include "Camera.h"
#include "vector"




Player player;


void PlayerStart(){
    player.body.transform = {100, 0, 32, 32};
    player.body.collision = {player.body.transform.x + 5, player.body.transform.y, 22, 32};
}


void PlayerEvent(SDL_Event* event){
    player.direction.x = InputDirection(SDL_SCANCODE_D, SDL_SCANCODE_A);
    if(event->type == SDL_EVENT_KEY_DOWN && event->key.scancode == SDL_SCANCODE_SPACE && player.isGrounded){
        player.body.velocity.y = -player.jumpForce;
        player.isGrounded = false;
    }
}

void PlayerMove(float deltatime) {
    player.body.velocity.y += player.gravity * deltatime;
    player.body.velocity.x = player.speed * player.direction.x;



    //I will fix later: Dont use old transforms for colliding
    SetPlayerTransform({player.body.transform.x + (player.body.velocity.x), player.body.transform.y}, {5, 0});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(player.body.collision, worldTiles[i])){
            player.body.velocity.x = 0;
        }
    }

    SetPlayerTransform({player.body.transform.x, player.body.transform.y + (player.body.velocity.y)}, {5, 0});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(player.body.collision, worldTiles[i])){
            player.body.velocity.y = 0;
            player.isGrounded = true;
        }
    }
}

void PlayerRender(SDL_Renderer* renderer){
    RenderTextureWithCamera(renderer, blockTextures[TEXTURE_PLAYER], player.body.transform);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    RenderRectWithCamera(renderer, player.body.collision);
}

void SetPlayerTransform(Vector2 transformPos, Vector2 collisionPos){
    player.body.transform.x = transformPos.x;
    player.body.transform.y = transformPos.y;

    player.body.collision.x = transformPos.x + collisionPos.x;
    player.body.collision.y = transformPos.y + collisionPos.y;
}