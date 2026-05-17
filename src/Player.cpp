#include "Player.h"
#include "Physics.h"
#include "Texture.h"
#include "Input.h"
#include "World.h"
#include "Camera.h"
#include "vector"
#include "GameTime.h"
#include "Game.h"




Player player;


void PlayerStart(){
    player.body.transform.w = 32;
    player.body.transform.h = 32;

    player.body.collision.w = 24;
    player.body.collision.h = 32;
    
    SetPlayerTransformWithCollision({0, 0});
}


void PlayerEvent(){
    player.direction.x = Input::InputDirection(SDL_SCANCODE_D, SDL_SCANCODE_A);
    if(Input::event.type == SDL_EVENT_KEY_DOWN && Input::event.key.scancode == SDL_SCANCODE_SPACE && player.isGrounded){
        player.body.velocity.y = -player.jumpForce;
        player.isGrounded = false;
    }
}

void PlayerMove() {
    player.body.velocity.y += player.gravity * GameTime::deltaTime;
    player.body.velocity.x = player.speed * player.direction.x;


    SetPlayerTransformWithCollision({player.body.collision.x + (player.body.velocity.x * GameTime::deltaTime), player.body.collision.y});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(player.body.collision, worldTiles[i].rect) && player.body.velocity.x > 0){
            SetPlayerTransformWithCollision({worldTiles[i].rect.x - player.body.collision.w, player.body.collision.y});
            player.body.velocity.x = 0;
        }
        else if(IsColliding(player.body.collision, worldTiles[i].rect) && player.body.velocity.x < 0){
            SetPlayerTransformWithCollision({worldTiles[i].rect.x + worldTiles[i].rect.w, player.body.collision.y});
            player.body.velocity.x = 0;
        }
    }
    

    SetPlayerTransformWithCollision({player.body.collision.x, player.body.collision.y + (player.body.velocity.y * GameTime::deltaTime)});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(player.body.collision, worldTiles[i].rect) && player.body.velocity.y > 0){
            SetPlayerTransformWithCollision({player.body.collision.x, worldTiles[i].rect.y - player.body.collision.h});
            player.body.velocity.y = 0;
            player.isGrounded = true;
        }
        else if (IsColliding(player.body.collision, worldTiles[i].rect) && player.body.velocity.y < 0){
            SetPlayerTransformWithCollision({player.body.collision.x, worldTiles[i].rect.y + worldTiles[i].rect.h});
            player.body.velocity.y = 0;
        }
    }
}

void PlayerRender(){
    RenderTextureWithCamera(Game::renderer, blockTextures[TEXTURE_PLAYER], player.body.transform);
    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    RenderRectWithCamera(Game::renderer, player.body.collision);
}

void SetPlayerTransformWithCollision(Vector2 collisionTransform){
    player.body.collision.x = collisionTransform.x;
    player.body.collision.y = collisionTransform.y;

    player.body.transform.x = collisionTransform.x - player.colOffset.x;
    player.body.transform.y = collisionTransform.y - player.colOffset.y;
}