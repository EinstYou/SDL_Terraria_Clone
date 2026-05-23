#ifndef PHYSISCS_H
#define PHYSISCS_H
#include <SDL3/SDL.h>


typedef struct Vector2{
    float x;
    float y;
}Vector2;


Vector2 NormalizeVector(Vector2 vector);

bool IsColliding(SDL_FRect r1, SDL_FRect r2);

float GetOrigin(float position, float size);
int RandomNumberGenerator(int min, int max);


#endif