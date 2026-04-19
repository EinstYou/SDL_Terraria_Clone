#include "Physics.h"
#include <math.h>
#include <cstdlib>


Vector2 NormalizeVector(Vector2 vector){
    float hypotenuse = sqrtf((vector.x * vector.x) + (vector.y * vector.y));
    if(hypotenuse != 0.0f){
        return {vector.x / hypotenuse, vector.y / hypotenuse};
    }
    return {0.0f, 0.0f};
}


bool IsColliding(SDL_FRect r1, SDL_FRect r2){
    const float r1Top = r1.y;
    const float r1Bottom = r1.y + r1.h;
    const float r1Left = r1.x;
    const float r1Right = r1.x + r1.w;

    const float r2Top = r2.y;
    const float r2Bottom = r2.y + r2.h;
    const float r2Left = r2.x;
    const float r2Right = r2.x + r2.w;

    return r1Top < r2Bottom && r1Bottom > r2Top && r1Left < r2Right && r1Right > r2Left;
}



float GetOrigin(float position, float size){
    return (position * 2 + size) / 2;
}



int RandomNumberGenerator(int min, int max) {
    return rand() % (max + 1 - min) + min;
}
