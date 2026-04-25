#include "Player.h"
#include "Physics.h"
#include "Texture.h"
#include "Input.h"
#include "World.h"
#include "Camera.h"
#include "vector"




Player player;


void PlayerStart(){
    player.body.transform.w = 32;
    player.body.transform.h = 32;

    player.body.collision.w = 24;
    player.body.collision.h = 32;
    
    SetPlayerTransform({100, 0});
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


    const float oldPosX = player.body.transform.x;
    SetPlayerTransform({player.body.transform.x + (player.body.velocity.x * deltatime), player.body.transform.y});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(player.body.collision, worldTiles[i].rect)){
            SetPlayerTransform({oldPosX, player.body.transform.y});
            player.body.velocity.x = 0;
        }
    }
    

    const float oldPosY = player.body.transform.y;
    SetPlayerTransform({player.body.transform.x, player.body.transform.y + (player.body.velocity.y * deltatime)});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(player.body.collision, worldTiles[i].rect)){
            SetPlayerTransform({player.body.transform.x, oldPosY});
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

void SetPlayerTransform(Vector2 transformPos){
    player.body.transform.x = transformPos.x;
    player.body.transform.y = transformPos.y;

    player.body.collision.x = transformPos.x + player.colOffset.x;
    player.body.collision.y = transformPos.y + player.colOffset.y;
}