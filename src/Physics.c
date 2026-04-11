#include "Physics.h"
#include <math.h>




Vector2 NormalizeVector(Vector2 vector){
    float hypotenuse = sqrtf((vector.x * vector.x) + (vector.y * vector.y));
    if(hypotenuse != 0.0f){
        return (Vector2){vector.x / hypotenuse, vector.y / hypotenuse};
    }
    return (Vector2){0.0f, 0.0f};
}