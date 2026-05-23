#include "Player.h"
#include "Physics.h"
#include "Texture.h"
#include "Input.h"
#include "World.h"
#include "Camera.h"
#include "vector"
#include "GameTime.h"
#include "Game.h"




void Player::Start() {
    transform.w = 32;
    transform.h = 32;

    collision.w = 24;
    collision.h = 32;
    
    SetPlayerTransformWithCollision({0, 0});
}


void Player::Update() {

    direction.x = Input::InputDirection(SDL_SCANCODE_D, SDL_SCANCODE_A);
    if(Input::keyStates[SDL_SCANCODE_SPACE] && isGrounded){
        velocity.y = -jumpForce;
        isGrounded = false;
    }

    velocity.y += gravity * GameTime::deltaTime;
    velocity.x = speed * direction.x;


    SetPlayerTransformWithCollision({collision.x + (velocity.x * GameTime::deltaTime), collision.y});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(collision, worldTiles[i].rect) && velocity.x > 0){
            SetPlayerTransformWithCollision({worldTiles[i].rect.x - collision.w, collision.y});
            velocity.x = 0;
        }
        else if(IsColliding(collision, worldTiles[i].rect) && velocity.x < 0){
            SetPlayerTransformWithCollision({worldTiles[i].rect.x + worldTiles[i].rect.w, collision.y});
            velocity.x = 0;
        }
    }
    

    SetPlayerTransformWithCollision({collision.x, collision.y + (velocity.y * GameTime::deltaTime)});
    for(int i = 0; i < worldTiles.size(); i++){
        if(IsColliding(collision, worldTiles[i].rect) && velocity.y > 0){
            SetPlayerTransformWithCollision({
                collision.x, worldTiles[i].rect.y - collision.h});
            velocity.y = 0;
            isGrounded = true;
        }
        else if (IsColliding(collision, worldTiles[i].rect) && velocity.y < 0){
            SetPlayerTransformWithCollision({collision.x, worldTiles[i].rect.y + worldTiles[i].rect.h});
            velocity.y = 0;
        }
    }
}

void Player::Render(){
    RenderTextureWithCamera(Game::renderer, blockTextures[TEXTURE_PLAYER], Player::transform);
    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    RenderRectWithCamera(Game::renderer, collision);
}

void Player::SetPlayerTransformWithCollision(Vector2 collisionTransform){
    collision.x = collisionTransform.x;
    collision.y = collisionTransform.y;

    transform.x = collisionTransform.x - colOffset.x;
    transform.y = collisionTransform.y - colOffset.y;
}