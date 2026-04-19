
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Physics.h"


struct Player {
    PhysicalObject body;
    Vector2 direction;
    float speed = 300;
    float gravity = 500;
    float jumpForce = 500;
    bool isGrounded = false;
};
extern Player player;

void PlayerStart();
void PlayerEvent(SDL_Event* event);
void PlayerMove(float deltatime);
void PlayerRender(SDL_Renderer* renderer);
void SetPlayerTransform(Vector2 transformPos, Vector2 collisionPos);





#endif