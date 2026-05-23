
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Physics.h"
#include "GameObject.h"


class Player : public GameObject {
public:
    Vector2 direction;
    Vector2 velocity;

    SDL_FRect transform;
    SDL_FRect collision;
    Vector2 colOffset = {5, 0};

    float speed = 300;
    float gravity = 1000;
    float jumpForce = 500;
    bool isGrounded = false;

    void SetPlayerTransformWithCollision(Vector2 collisionTransform);

    void Start() override;
    void Update() override;
    void Render() override;
};








#endif