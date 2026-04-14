#ifndef PHYSISCS_H
#define PHYSISCS_H
#include <SDL3/SDL.h>


typedef struct Vector2{
    float x;
    float y;
}Vector2;


typedef struct PhysicalObject{
    Vector2 velocity;
    SDL_FRect transform;
    SDL_FRect collision;
} PhysicalObject;


Vector2 NormalizeVector(Vector2 vector);

bool IsColliding(SDL_FRect r1, SDL_FRect r2);

float GetOrigin(float position, float size);


#endif